#ifndef ADIOS2_DERIVED_Function_H_
#define ADIOS2_DERIVED_Function_H_

#include "adios2/common/ADIOSTypes.h"
#include "adios2/helper/adiosLog.h"
#include "parser/ExprHelper.h"
#include <functional>

namespace adios2
{
namespace derived
{

    struct DerivedData
    {
        void *Data;
        Dims Start;
        Dims Count;
    };
/*
    template <class T>
    void ConvertInputData(std::vector<DerivedData> inputData, std::vector<std::vector<T>> &outputData);

    template <class T>
    void * DerivedAddFunction(std::vector<std::vector<T>> VarDataList);
*/
    struct OperatorFunctions
    {
        std::function<DerivedData(std::vector<DerivedData>, DataType)> ComputeFct;
        std::function<Dims(std::vector<Dims>)> DimsFct;
    };

    DerivedData AddFunc(std::vector<DerivedData> input, DataType type);
    DerivedData MagnitudeFunc(std::vector<DerivedData> input, DataType type);

    Dims SameDimsFunc(std::vector<Dims> input);

    const std::map<adios2::detail::ExpressionOperator, OperatorFunctions> OpFunctions = {
        {adios2::detail::ExpressionOperator::OP_ADD, {AddFunc, SameDimsFunc}},
        {adios2::detail::ExpressionOperator::OP_MAGN, {MagnitudeFunc, SameDimsFunc}}};
}
}
#endif