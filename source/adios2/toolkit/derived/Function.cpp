#ifndef ADIOS2_DERIVED_Function_CPP_
#define ADIOS2_DERIVED_Function_CPP_

#include "Function.h"
#include "Function.tcc"
#include "adios2/common/ADIOSMacros.h"
#include "adios2/helper/adiosFunctions.h"
#include <adios2-perfstubs-interface.h>
#include <cmath>

namespace adios2
{
namespace derived
{

DerivedData AddFunc(std::vector<DerivedData> inputData, DataType type)
{
    PERFSTUBS_SCOPED_TIMER("derived::Function::AddFunc");
    size_t dataSize = std::accumulate(std::begin(inputData[0].Count), std::end(inputData[0].Count),
                                      1, std::multiplies<size_t>());

#define declare_type_add(T)                                                                        \
    if (type == helper::GetDataType<T>())                                                          \
    {                                                                                              \
        T *addValues = ApplyOneToOne<T>(inputData, dataSize, [](T a, T b) { return a + b; });      \
        return DerivedData({(void *)addValues, inputData[0].Start, inputData[0].Count});           \
    }
    ADIOS2_FOREACH_PRIMITIVE_STDTYPE_1ARG(declare_type_add)
    helper::Throw<std::invalid_argument>("Derived", "Function", "AddFunc",
                                         "Invalid variable types");
    return DerivedData();
}

DerivedData MagnitudeFunc(std::vector<DerivedData> inputData, DataType type)
{
    PERFSTUBS_SCOPED_TIMER("derived::Function::MagnitudeFunc");
    size_t dataSize = std::accumulate(std::begin(inputData[0].Count), std::end(inputData[0].Count),
                                      1, std::multiplies<size_t>());
#define declare_type_mag(T)                                                                        \
    if (type == helper::GetDataType<T>())                                                          \
    {                                                                                              \
        T *magValues = ApplyOneToOne<T>(inputData, dataSize, [](T a, T b) { return a + b * b; });  \
        for (size_t i = 0; i < dataSize; i++)                                                      \
        {                                                                                          \
            magValues[i] = (T)std::sqrt(magValues[i]);                                             \
        }                                                                                          \
        return DerivedData({(void *)magValues, inputData[0].Start, inputData[0].Count});           \
    }
    ADIOS2_FOREACH_PRIMITIVE_STDTYPE_1ARG(declare_type_mag)
    helper::Throw<std::invalid_argument>("Derived", "Function", "MagnitudeFunc",
                                         "Invalid variable types");
    return DerivedData();
}

/*
 * Input: 3D vector field F(x,y,z)= {F1(x,y,z), F2(x,y,z), F3(x,y,z)}
 *
 *     inputData - (3) components of 3D vector field
 *
 * Computation:
 *     curl(F(x,y,z)) = (partial(F3,y) - partial(F2,z))i
 *                    + (partial(F1,z) - partial(F3,x))j
 *                    + (partial(F2,x) - partial(F1,y))k
 *
 *     boundaries are calculated only with data in block
 *         (ex: partial derivatives in x direction at point (0,0,0)
 *              only use data from (1,0,0), etc )
 */
DerivedData Curl3DFunc(const std::vector<DerivedData> inputData, DataType type)
{
    PERFSTUBS_SCOPED_TIMER("derived::Function::Curl3DFunc");
    size_t dims[3] = {inputData[0].Count[0], inputData[0].Count[1], inputData[0].Count[2]};

    DerivedData curl;
    curl.Start = inputData[0].Start;
    curl.Start.push_back(0);
    curl.Count = inputData[0].Count;
    curl.Count.push_back(3);

#define declare_type_curl(T)                                                                       \
    if (type == helper::GetDataType<T>())                                                          \
    {                                                                                              \
        T *input1 = (T *)inputData[0].Data;                                                        \
        T *input2 = (T *)inputData[1].Data;                                                        \
        T *input3 = (T *)inputData[2].Data;                                                        \
        curl.Data = ApplyCurl(input1, input2, input3, dims);                                       \
        return curl;                                                                               \
    }
    ADIOS2_FOREACH_PRIMITIVE_STDTYPE_1ARG(declare_type_curl)
    helper::Throw<std::invalid_argument>("Derived", "Function", "Curl3DFunc",
                                         "Invalid variable types");
    return DerivedData();
}

std::vector<DerivedData> ExtractDimensionN(DerivedData inputData, DataType type, size_t dim)
{
    size_t num_data_sets = inputData.Count[dim];
    size_t num_chunks = 1;
    size_t chunk_length = 1;
    for (size_t i = 0; i < dim; ++i)
    {
        num_chunks *= inputData.Count[i];
    }
    for (size_t i = dim + 1; i < inputData.Count.size(); ++i)
    {
        chunk_length *= inputData.Count[i];
    }

    Dims set_Start;
    Dims set_Count;
    for (size_t i = 0; i < inputData.Start.size(); ++i)
    {
        if (i != dim)
        {
            set_Start.push_back(inputData.Start[i]);
            set_Count.push_back(inputData.Count[i]);
        }
    }

    std::vector<DerivedData> result;
    size_t chunk_size = chunk_length * helper::GetDataTypeSize(type);
    // TO DO - FREE
    for (size_t i = 0; i < num_data_sets; ++i)
        result.push_back({malloc(num_chunks * chunk_size), set_Start, set_Count});

    // How does Start factor in?
    //  size_t data_iter = 0;
    char *input_ptr = (char *)inputData.Data;
    for (size_t chunk = 0; chunk < num_chunks; ++chunk)
    {
        for (size_t data_set = 0; data_set < num_data_sets; ++data_set)
        {
            char *result_ptr = (char *)(result[data_set].Data);
            memcpy(result_ptr + (chunk * chunk_size),
                   input_ptr + (((num_data_sets * chunk) + data_set) * chunk_size), chunk_size);

            // memcpy(&(result[data_set].Data[chunk * chunk_length]), &(inputData.Data[data_iter]),
            /*
          for (size_t chunk_iter = 0; chunk_iter < chunk_length; ++chunk_iter)
            {
              result[data_set].Data[(chunk * chunk_length) + chunk_iter] =
          inputData.Data[data_iter++];
              }*/
        }
    }

    return result;
}

Dims SameDimsFunc(std::vector<Dims> input)
{
    // check that all dimenstions are the same
    if (input.size() > 1)
    {
        Dims first_element = input[0];
        bool dim_are_equal = std::all_of(input.begin() + 1, input.end(),
                                         [&first_element](Dims x) { return x == first_element; });
        if (!dim_are_equal)
            helper::Throw<std::invalid_argument>("Derived", "Function", "SameDimsFunc",
                                                 "Invalid variable dimensions");
    }
    // return the first dimension
    return input[0];
}

// Input Dims are the same, output is combination of all inputs
Dims CurlDimsFunc(std::vector<Dims> input)
{
    // check that all dimenstions are the same
    if (input.size() > 1)
    {
        Dims first_element = input[0];
        bool dim_are_equal = std::all_of(input.begin() + 1, input.end(),
                                         [&first_element](Dims x) { return x == first_element; });
        if (!dim_are_equal)
            helper::Throw<std::invalid_argument>("Derived", "Function", "CurlDimsFunc",
                                                 "Invalid variable dimensions");
    }
    // return original dimensions with added dimension of number of inputs
    Dims output = input[0];
    output.push_back(input.size());
    return output;
}

#define declare_template_instantiation(T)                                                          \
    T *ApplyOneToOne(std::vector<DerivedData>, size_t, std::function<T(T, T)>);                    \
    T *ApplyCurl(T *input1, T *input2, T *input3, size_t dims[3]);

ADIOS2_FOREACH_PRIMITIVE_STDTYPE_1ARG(declare_template_instantiation)
#undef declare_template_instantiation

}
} // namespace adios2
#endif
