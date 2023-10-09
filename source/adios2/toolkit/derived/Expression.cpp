#ifndef ADIOS2_DERIVED_Expression_CPP_
#define ADIOS2_DERIVED_Expression_CPP_

#include "Expression.h"

namespace
{
    //template<class T>
    //VariableInfo AddOp(std::vector<VariableInfo> operands)
    //{}

    ExpressionTree parse_expression(std::string expression)
    {
    }
}

namespace adios2{

namespace derived{

Expression::Expression(std::string string_exp): m_Exp(string_exp), m_Type(m_Exp.type), m_ConstantShape(m_Exp.constantShape), m_Shape(m_Exp.shape), m_Start(m_Exp.start), m_Count(m_Exp.count) {}

Dims Expression::GetShape()
{
    return m_Shape;
}

Dims Expression::GetStart()
{
    return m_Start;
}

Dims Expression::GetCount()
{
    return m_Count;
}

DataType GetDataType()
{
    return m_Type;
}

bool m_ConstatShape()
{
    return m_ConstantShape;
}

bool CheckCorrectness()
{
    return true;
}

void *ApplyExpression()
{
    // recompute the shape in case the variables were updated
}

}
}
#ifndef
