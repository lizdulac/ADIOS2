#include "adios2/helper/adiosType.h"
#include "VariableDerived.h"

namespace adios2
{
namespace core
{

    VariableDerived::VariableDerived(const std::string &name, derived::Expression exp)
    : VariableBase(name, exp.m_Type, helper::GetDataTypeSize(exp.m_Type), exp.GetShape(), exp.GetStart(), exp.GetCount(), exp.m_ConstantShape), expression(exp)
    {
    }

} // end namespace core
} // end namespace adios2
