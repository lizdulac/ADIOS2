#ifndef ADIOS2_CORE_VARIABLE_DERIVED_H_
#define ADIOS2_CORE_VARIABLE_DERIVED_H_

#include "adios2/common/ADIOSTypes.h"
#include "adios2/core/VariableBase.h"
#include "adios2/helper/adiosType.h"
#include "adios2/toolkit/derived/Expression.h"

namespace adios2
{
namespace core
{

/**
 * @param Base (parent) class for template derived (child) class Variable.
 */
class VariableDerived : public VariableBase
{
    derived::Expression expression;

public:
    VariableDerived(const std::string &name, const DataType type, const size_t elementSize,
                 const Dims &shape, const Dims &start, const Dims &count, const bool constantShape);

    ~VariableDerived() = default;

    void AddDerivedExpression(derived::Expression exp);

};

} // end namespace core
} // end namespace adios2

#endif /* ADIOS2_CORE_VARIABLE_DERIVED_H_ */
