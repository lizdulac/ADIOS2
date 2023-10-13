#ifndef ADIOS2_DERIVED_Function_CPP_
#define ADIOS2_DERIVED_Function_CPP_

#include "Function.h"
#include "adios2/helper/adiosComm.h"

namespace adios2
{
namespace derived
{
    void AddFunc(std::vector<DerivedData> input, DataType type){};
    Dims SameDimsFunc(std::vector<Dims> input)
    {
        // check that all dimenstions are the same
        if(input.size() > 1)
        {
            bool dim_are_equal = std::equal(input.begin() + 1, input.end(), input.begin());
            if (!dim_are_equal)
                helper::Throw<std::invalid_argument>("Derived", "Function", "SameDimFunc",
                                                 "invalid variable dimensions");
        }
        // return the first dimension
        return input[0];
    };
}    
} // namespace adios2
#endif
