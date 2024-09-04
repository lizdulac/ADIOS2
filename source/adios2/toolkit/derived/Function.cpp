#ifndef ADIOS2_DERIVED_Function_CPP_
#define ADIOS2_DERIVED_Function_CPP_

#include "Function.h"
#include "Function.tcc"
#include "adios2/helper/adiosFunctions.h"
#include "adios2/helper/adiosLog.h"
#include <adios2-perfstubs-interface.h>
#include <cmath>
#include "Hash.h"
//#ifdef ADIOS2_HAVE_KOKKOS
//#endif

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

// TODO: replace addFunc implementation with hash implementation
// will require kokkos and maybe kokkos view
// Only if ADIOS HAS Kokkos
DerivedData HashFunc(std::vector<DerivedData> inputData, DataType type)
{
    std::cout << "HashFunc called" << std::endl;
    std::cout << "type: " << type << std::endl;
    PERFSTUBS_SCOPED_TIMER("derived::Function::HashFunc");
    if (inputData[0].Start.size() != 1)
      std::cout << "An error message is supposed to go here" << std::endl;
    size_t start = inputData[0].Start[0];
    size_t dataSize = std::accumulate(std::begin(inputData[0].Count), std::end(inputData[0].Count), 1, std::multiplies<size_t>());
#define declare_type_hash(T)                                                                       \
    if (type == helper::GetDataType<T>())                                                          \
    {                                                                                              \
      dataSize *= sizeof(T);					                                   \
    }
    ADIOS2_FOREACH_PRIMITIVE_STDTYPE_1ARG(declare_type_hash)

      std::vector<uint8_t> hashOutput = stateDiffHash((float*)inputData[0].Data + start, dataSize);
    //std::vector<uint8_t> hashOutput = stateDiffHash(inputData[0].Data, dataSize);
    void *hashData = std::malloc(hashOutput.size());
    std::memcpy(hashData, hashOutput.data(), hashOutput.size() * sizeof(uint8_t));
    size_t out_start = start * 33 / 4096;
    size_t out_count = dataSize * 33 / 4096;

    std::cout << "Function.cpp Hash function returning DerivedData" << std::endl;
    
    return DerivedData({hashData, {out_start}, {out_count}});
    //return DerivedData({hashData, {0}, {hashOutput.size()}});
    //kokkos_murmur3::hash(inputData[0].Data, dataSize, 0/*(uint8_t*)seed*/);
    

    /*
#define declare_type_hash(T)                                                                       \
    if (type == helper::GetDataType<T>())                                                          \
    {                                                                                              \
        T *hashValues = ApplyOneToOne<T>(inputData, dataSize, [](T a, T b) { return a + b; });     \
        return DerivedData({(void *)hashValues, inputData[0].Start, inputData[0].Count});          \
    }
    ADIOS2_FOREACH_PRIMITIVE_STDTYPE_1ARG(declare_type_hash)
    helper::Throw<std::invalid_argument>("Derived", "Function", "HashFunc",
                                         "Invalid variable types");
    */
    //    return DerivedData();
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

// TODO: hardcode output to float of some size
// or from num blocks n, pow(2, ciel(log_2(n)) + 1) - 1
Dims HashDimsFunc(std::vector<Dims> input)
{
    // check that all dimenstions are the same
    if (input.size() != 1)
    {
      helper::Throw<std::invalid_argument>("Derived", "Function", "HashDimsFunc",
					   "Invalid variable dimensions");
    }

    size_t size = (size_t)(input[0][0] * 33 / 4096); // Assume chunk size of 4KB

    std::cout << "Function.cpp HashDimsFunc input size: " << input[0][0];
    std::cout << " -> output size " << size << std::endl;
    return {size};
}

#define declare_template_instantiation(T)                                                          \
    T *ApplyOneToOne(std::vector<DerivedData>, size_t, std::function<T(T, T)>);                    \
    T *ApplyCurl(T *input1, T *input2, T *input3, size_t dims[3]);

ADIOS2_FOREACH_PRIMITIVE_STDTYPE_1ARG(declare_template_instantiation)
#undef declare_template_instantiation

}
} // namespace adios2
#endif
