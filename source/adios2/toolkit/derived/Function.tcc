#ifndef ADIOS2_DERIVED_Function_TCC_
#define ADIOS2_DERIVED_Function_TCC_

#include "Function.h"
#include <numeric>
#include <algorithm>

namespace adios2
{
namespace derived
{
    /*
    template <class T>
    void ConvertInputData(std::vector<DerivedData> inputData, std::vector<std::vector<T>> &templatedInput)
    {
        for (auto &variable : inputData)
        {
            std::vector<T> varData;
            size_t dataSize =
                std::accumulate(std::begin(variable.Count), std::end(variable.Count), 1,
                                std::multiplies<size_t>());
            //std::copy(reinterpret_cast<T *>(variable.Data), reinterpret_cast<int *>(variable.Data) + dataSize, varData.begin());
            templatedInput.push_back(varData);
        }
    }

    template <class T>
    void *DerivedAddFunction(std::vector<std::vector<T>> VarDataList)
    {
        size_t numElem = VarDataList[0].size();
        std::vector<T> addData(numElem, 0);
        for(auto &variableData: VarDataList)
        {
            std::transform(variableData.cbegin(), variableData.cend(), addData.cbegin(), addData.begin(), [](const int& i, const int& j){ return i + j; });
        }
        return reinterpret_cast<void *>(addData.data());
    }

    void *DerivedAddFunction(std::vector<std::vector<std::string>> VarDataList)
    {
        helper::Throw<std::invalid_argument>("Derived", "Function", "DerivedAddFunction",
                                             "The ADD Operator cannot be applied on string variables");
        return (void *) nullptr;
    }

    void *DerivedAddFunction(std::vector<std::vector<char>> VarDataList)
    {
        helper::Throw<std::invalid_argument>("Derived", "Function", "DerivedAddFunction",
                                             "The ADD Operator cannot be applied on char variables");
        return (void *) nullptr;
    }*/
}
}
#endif
