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
    {}

} // end namespace core
} // end namespace adios2
