#ifndef ADIOS2_DERIVED_Function_H_
#define ADIOS2_DERIVED_Function_H_

#include <functional>
#include "adios2/common/ADIOSTypes.h"
#include "parser/ExprHelper.h"

namespace adios2{
namespace derived{

struct DerivedData
{
    void *Data;
    Dims Start;
    Dims Count;
};

struct OperatorFunctions
{
    std::function<void(std::vector<DerivedData>, DataType)> ComputeFct;
    std::function<Dims(std::vector<Dims>)> DimsFct;
};

void AddFunc(std::vector<DerivedData> input, DataType type);
Dims SameDimsFunc(std::vector<Dims> input);

const std::map<adios2::detail::ExpressionOperator, OperatorFunctions> OpFunctions = {
    {adios2::detail::ExpressionOperator::OP_ADD, {AddFunc, SameDimsFunc}}
};

}
}
#endif