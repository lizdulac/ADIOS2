#include "Expression.h"

namespace adios2{

namespace derived{

Expression::Expression(std::string expression)
{
    m_Type = DataType::None;
    m_ElementSize = 0;
}

Dims Expression::GetShape()
{
    return {0};
}

Dims Expression::GetStart()
{
    return {0};
}

Dims Expression::GetCount()
{
    return {0};
}

DataType Expression::GetType()
{
    return m_Type;
}

size_t Expression::GetElementSize()
{
    return m_ElementSize;
}

}
}
