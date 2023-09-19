#include "VariableDerived.h"

namespace adios2
{
namespace core
{

    VariableDerived::VariableDerived(const std::string &name, const DataType type, const size_t elementSize,
                 const Dims &shape, const Dims &start, const Dims &count, const bool constantShape)
    : VariableBase(name, type, elementSize, shape, start, count, constantShape)
    { 
    }

    void VariableDerived::AddDerivedExpression(derived::Expression exp): expression(exp){}
} // end namespace core
} // end namespace adios2
