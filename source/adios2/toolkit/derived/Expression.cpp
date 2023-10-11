#ifndef ADIOS2_DERIVED_Expression_CPP_
#define ADIOS2_DERIVED_Expression_CPP_

#include "Expression.h"

namespace adios2{

namespace derived{

//Expression::Expression(std::string string_exp): m_Exp(string_exp), m_Type(m_Exp.type), m_ConstantShape(m_Exp.constantShape), m_Shape(m_Exp.shape), m_Start(m_Exp.start), m_Count(m_Exp.count) {}

Expression::Expression(std::string string_exp)//, adios2::core::VarMap variables)
: m_Shape({0}), m_Start({0}), m_Count({0})
{
    m_Type = DataType::Float;
    m_ConstantShape = true;
    adios2::detail::ASTNode *root_node = adios2::detail::parse_expression(string_exp);
    std::cout << "Converting the ASTNode to ExpressionTree" << std::endl;
    m_Exp = ASTNode_to_ExpressionTree(root_node);//, variables);
    m_Exp.print();
}

ExpressionTree Expression::ASTNode_to_ExpressionTree(adios2::detail::ASTNode* node)//, adios2::core::VarMap variables)
{
    std::cout << "Adding node " << node->operation << " " << node->sub_expr.size() << std::endl;
    ExpressionTree exprTree_node(node->operation);
    for (adios2::detail::ASTNode* e: node->sub_expr)
    {
        std::cout << "Look at sub-expression " << e->operation << std::endl;
        switch (e->operation)
        {
            case adios2::detail::ExpressionOperator::OP_ALIAS:
                // add an index vector
                exprTree_node.add_child(e->lookup_var_path(e->alias));
                std::cout << "variable alias " << e->lookup_var_path(e->alias) << std::endl;
                break;
            case adios2::detail::ExpressionOperator::OP_PATH:
                exprTree_node.add_child(e->alias);
                std::cout << "variable path" << std::endl;
                break;
            case adios2::detail::ExpressionOperator::OP_NUM:
                exprTree_node.set_base(e->value);
                std::cout << "value" << std::endl;
                break;
            default: //if the children nodes are other expressions, convert them to expressions
                auto temp_node = ASTNode_to_ExpressionTree(e);
                std::cout << "recursive - child operation is " << e->operation << std::endl;
                // move from a binary to a multinary tree if the child has the same operation
                if (e->operation == node->operation) // TODO check if the base is the same
                {
                    // concatenate exprTree with temp_node
                    for (std::tuple<ExpressionTree, std::string, bool> childTree: temp_node.sub_exprs)
                    {
                        if(std::get<2>(childTree) == true)
                            exprTree_node.add_child(std::get<0>(childTree));
                        else
                            exprTree_node.add_child(std::get<1>(childTree));
                    }
                }
                else
                {
                    exprTree_node.add_child(temp_node);
                }
        }
    }
    return exprTree_node;
}

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

DataType Expression::GetDataType()
{
    return m_Type;
}

bool Expression::IsConstantShape()
{
    return m_ConstantShape;
}

bool Expression::CheckCorrectness()
{
    return true;
}

void Expression::ApplyExpression()
{
    // recompute the shape in case the variables were updated
}

}
}
#endif
