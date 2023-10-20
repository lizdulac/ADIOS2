#include "VariableDerived.h"
#include "adios2/helper/adiosType.h"

namespace adios2
{
namespace core
{

VariableDerived::VariableDerived(const std::string &name, adios2::derived::Expression expr,
                                 const DataType exprType, const bool isConstant,
                                 const DerivedVarType varType)
: VariableBase(name, exprType, helper::GetDataTypeSize(exprType), expr.GetShape(), expr.GetStart(),
               expr.GetCount(), isConstant),
  m_Expr(expr), m_DerivedType(varType)
{
    std::cout << "Creating derived variable " << name << std::endl;
    std::cout << "Set initial dimensions for derived variable " << name << " start: " << m_Start
              << " count: " << m_Count << std::endl;
}

DerivedVarType VariableDerived::GetDerivedType() { return m_DerivedType; }

std::vector<std::string> VariableDerived::VariableNameList() { return m_Expr.VariableNameList(); }
void VariableDerived::UpdateExprDim(std::map<std::string, std::tuple<Dims, Dims, Dims>> NameToDims)
{
    m_Expr.SetDims(NameToDims);
    m_Shape = m_Expr.GetShape();
    m_Start = m_Expr.GetStart();
    m_Count = m_Expr.GetCount();
}

std::vector<void *>
VariableDerived::ApplyExpression(std::map<std::string, std::vector<void *>> NameToData,
                                 std::map<std::string, std::tuple<Dims, Dims, Dims>> NameToDims)
{
    size_t numBlocks = 0;
    std::map<std::string, std::vector<adios2::derived::DerivedData>> inputData;
    for (auto variable : NameToData)
    {
        if (numBlocks == 0)
            numBlocks = variable.second.size();
        if (numBlocks != variable.second.size())
            helper::Throw<std::invalid_argument>("Core", "VariableDerived", "ApplyExpression",
                                                 " variables do not have the same number of blocks "
                                                 " in computing the derived variable " +
                                                     m_Name);
    }
    std::cout << "Derived variable " << m_Name
              << ": PASS : variables have written the same num of blocks" << std::endl;
    for (auto variable : NameToData)
    {
        std::vector<adios2::derived::DerivedData> varData;
        for (size_t i = 0; i < numBlocks; i++)
        {
            varData.push_back(adios2::derived::DerivedData(
                {variable.second[i], std::get<0>(NameToDims[variable.first]),
                 std::get<1>(NameToDims[variable.first])}));
        }
        inputData.insert({variable.first, varData});
    }
    std::vector<adios2::derived::DerivedData> outputData =
        m_Expr.ApplyExpression(m_Type, numBlocks, inputData);
    std::vector<void *> blockData;
    for (size_t i = 0; i < numBlocks; i++)
    {
        blockData.push_back(outputData[i].Data);
    }
    return blockData;
}

} // end namespace core
} // end namespace adios2
