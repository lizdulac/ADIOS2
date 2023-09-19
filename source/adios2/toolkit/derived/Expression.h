#include <string>
#include "adios2/common/ADIOSTypes.h"

namespace adios2{

namespace derived{

class Expression{
    DataType m_Type;
    int m_ElementSize;
public:
    Expression(std::string expression);
    Dims GetShape();
    Dims GetStart();
    Dims GetCount();
    DataType GetType();
    size_t GetElementSize();
};

}
}
