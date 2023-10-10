#include "adios2/helper/adiosType.h"
#include "VariableDerived.h"

namespace adios2
{
namespace core
{

    VariableDerived::VariableDerived(const std::string &name, derived::Expression exp)
    : VariableBase(name, exp.GetDataType(), helper::GetDataTypeSize(exp.GetDataType()), exp.GetShape(), exp.GetStart(), exp.GetCount(), exp.IsConstantShape()),
    expression(exp)
    {
    }

} // end namespace core
} // end namespace adios2
