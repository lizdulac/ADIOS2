#ifndef ADIOS2_DERIVED_Expression_H_
#define ADIOS2_DERIVED_Expression_H_

#include <string>
#include "adios2/common/ADIOSTypes.h"

namespace adios2{

namespace derived{

enum SupportedExp  {
    OP_ALIAS, /* Parser-use only */
    OP_PATH, /* Parser-use only */
    NULL_OP, /* not used */
    NULL_OP_VAR,
    NULL_OP_INDEX,
    NULL_OP_NUM,
    OP_ADD,
    OP_MUL
};

std::unordered_map<std::string, std::function<void *(void *)>> FunctionList =
{
        {SupportedExp::OP_ADD, detail::AddOp},
        {SupportedExp::OP_MUL, detail::MulOp}
};

class ExpressionTree
{
    std::vector<std::tuple<Expression, std::string> > sub_exprs;
    Op_info op;
};

class Expression
{
    ExpressionTree m_Exp;

    DataType m_Type;
    bool m_ConstantShape;
    Dims m_Shape;
    Dims m_Start;
    Dims m_Count;

public:
    Expression() = default;
    Expression(std::string expression);

    Dims GetShape();
    Dims GetStart();
    Dims GetCount();
    DataType GetDataType();
    bool IsConstantShape();

    void CheckCorrectness();
    void *ApplyExpression();
};

}
}
#ifndef
#define ADIOS2_DERIVED_Expression_CPP_
