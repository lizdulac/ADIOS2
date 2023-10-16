#include "adios2/helper/adiosType.h"
#include "VariableDerived.h"

namespace adios2
{
namespace core
{

    VariableDerived::VariableDerived(const std::string &name, adios2::derived::Expression expr,
                                     const DataType exprType, const bool isConstant,
                                     const DerivedVarType varType)
    : VariableBase(name, exprType, helper::GetDataTypeSize(exprType), expr.GetShape(), expr.GetStart(), expr.GetCount(), isConstant),
    m_Expr(expr), m_VarType(varType)
    {
        std::cout << "Creating derived variable " << name << std::endl;
        std::cout << "Set initial dimensions for derived variable " << name <<
                 " start: " << m_Start << " count: " << m_Count << std::endl;
    }

    std::vector<std::string> VariableDerived::VariableNameList(){ return m_Expr.VariableNameList(); }
    void VariableDerived::UpdateExprDim(std::map<std::string, std::tuple<Dims, Dims, Dims>> NameToDims){ return m_Expr.SetDims(NameToDims); }


} // end namespace core
} // end namespace adios2
