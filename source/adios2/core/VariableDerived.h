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
    adios2::derived::Expression m_Expr;
    DerivedVarType m_VarType;

public:
    VariableDerived(const std::string &name, adios2::derived::Expression expr,
                    const DataType exprType, const bool isConstant,
                    const DerivedVarType varType);
    ~VariableDerived() = default;

    void ApplyExpression(){};
    void UpdateExprDim(){};
};

} // end namespace core
} // end namespace adios2

#endif /* ADIOS2_CORE_VARIABLE_DERIVED_H_ */
