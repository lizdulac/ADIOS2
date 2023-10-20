#ifndef ADIOS2_DERIVED_Function_CPP_
#define ADIOS2_DERIVED_Function_CPP_

#include "Function.h"
#include "Function.tcc"
#include "adios2/common/ADIOSMacros.h"
#include "adios2/helper/adiosFunctions.h"
#include <cmath>

namespace adios2
{
namespace derived
{
/*void *AddFunc(std::vector<DerivedData> input, DataType type)
{
#define declare_type(T)                                                                            \
    if (type == helper::GetDataType<T>())                                                          \
    {                                                                                              \
        std::vector<std::vector<T>> templatedInput;                                                \
        ConvertInputData<T>(input, templatedInput);                                                \
        return DerivedAddFunction<T>(templatedInput);                                              \
    }
    ADIOS2_FOREACH_STDTYPE_1ARG(declare_type)
#undef declare_type
    helper::Throw<std::invalid_argument>("Derived", "Function", "AddFunc",
                                        "Invalid variable types used for ADD operation");
    return (void *) nullptr;
}*/

// TODO check if T is char and exit or throw an exception

DerivedData AddFunc(std::vector<DerivedData> inputData, DataType type)
{
    size_t dataSize = std::accumulate(std::begin(inputData[0].Count), std::end(inputData[0].Count),
                                      1, std::multiplies<size_t>());
#define declare_type_add(T)                                                                        \
    if (type == helper::GetDataType<T>())                                                          \
    {                                                                                              \
        T *addValues = (T *)malloc(dataSize * sizeof(T));                                          \
        memset(addValues, 0, sizeof(T));                                                           \
        for (auto &variable : inputData)                                                           \
        {                                                                                          \
            for (size_t i = 0; i < dataSize; i++)                                                  \
            {                                                                                      \
                addValues[i] += *(reinterpret_cast<T *>(variable.Data) + i);                       \
            }                                                                                      \
        }                                                                                          \
        return DerivedData({(void *)addValues, inputData[0].Start, inputData[0].Count});           \
    }
    ADIOS2_FOREACH_PRIMITIVE_STDTYPE_1ARG(declare_type_add)
    helper::Throw<std::invalid_argument>("Derived", "Function", "AddFunc",
                                         "Invalid variable types");
    return DerivedData();
}

DerivedData MagnitudeFunc(std::vector<DerivedData> inputData, DataType type)
{
    size_t dataSize = std::accumulate(std::begin(inputData[0].Count), std::end(inputData[0].Count),
                                      1, std::multiplies<size_t>());
    std::cout << "MAGN " << dataSize << std::endl;
#define declare_type_mag(T)                                                                        \
    if (type == helper::GetDataType<T>())                                                          \
    {                                                                                              \
        T *magValues = (T *)malloc(dataSize * sizeof(T));                                          \
        memset(magValues, 0, sizeof(T));                                                           \
        for (auto &variable : inputData)                                                           \
        {                                                                                          \
            for (size_t i = 0; i < dataSize; i++)                                                  \
            {                                                                                      \
                T data = *(reinterpret_cast<T *>(variable.Data) + i);                              \
                magValues[i] += (data * data);                                                     \
            }                                                                                      \
        }                                                                                          \
        for (size_t i = 0; i < dataSize; i++)                                                      \
        {                                                                                          \
            magValues[i] = std::sqrt(magValues[i]);                                                \
        }                                                                                          \
        return DerivedData({(void *)magValues, inputData[0].Start, inputData[0].Count});           \
    }
    ADIOS2_FOREACH_PRIMITIVE_STDTYPE_1ARG(declare_type_mag)
    helper::Throw<std::invalid_argument>("Derived", "Function", "MagnitudeFunc",
                                         "Invalid variable types");
    return DerivedData();
}

Dims SameDimsFunc(std::vector<Dims> input)
{
    // check that all dimenstions are the same
    if (input.size() > 1)
    {
        bool dim_are_equal = std::equal(input.begin() + 1, input.end(), input.begin());
        if (!dim_are_equal)
            helper::Throw<std::invalid_argument>("Derived", "Function", "SameDimFunc",
                                                 "Invalid variable dimensions");
    }
    // return the first dimension
    return input[0];
}

/*
#define declare_template_instantiation(T)                                                          \
    void ConvertInputData(std::vector<DerivedData>, std::vector<std::vector<T>> &);                \
    void *DerivedAddFunction(std::vector<std::vector<T>>);

ADIOS2_FOREACH_STDTYPE_1ARG(declare_template_instantiation)
#undef declare_template_instantiation
*/

}
} // namespace adios2
#endif
