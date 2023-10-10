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
    //m_Exp = ASTNode_to_ExpressionTree(root_node, variables);
}

void Expression::ASTNode_to_ExpressionTree(adios2::detail::ASTNode* node)//, adios2::core::VarMap variables)
{
    ExpressionTree exprTree_node(node->operation);
    for (adios2::detail::ASTNode* e: node->sub_expr)
    {
        // if the children nodes are other expressions, convert them to expressions
        if (e->operation != adios2::detail::ExpressionOperator::OP_ALIAS &&
            e->operation != adios2::detail::ExpressionOperator::OP_PATH &&
            e->operation != adios2::detail::ExpressionOperator::OP_NUM)
        {
            ASTNode_to_ExpressionTree(e);
            // add_child(what is returned by the previous function);
        }
        else{ // otherwise add parameters to the current expression node
            switch (node->operation)
            {
                case adios2::detail::ExpressionOperator::OP_ALIAS:
                    // add an index vector
                    break;
                case adios2::detail::ExpressionOperator::OP_PATH:
                    exprTree_node.add_child(e->alias);
                    break;
                case adios2::detail::ExpressionOperator::OP_NUM:
                    exprTree_node.set_base(e->value);
                    break;
                default:
                    break;
            }
        }
    }
    //return exprTree_node;

  //switch (node->operation) {
  /*case adios2::detail::ExpressionOperator::OP_ALIAS:
    // TODO: populate index vector
    if (node->lookup_var_indices(node->alias) != "")
      {
        ExpressionTree *expr = new ExpressionTree(adios2::detail::ExpressionOperator::OP_INDEX/*, lookup_var_indices(alias)*///);
     /*   expr->add_child(node->lookup_var_path(node->alias));
        //parent->add_child(expr);
      } else {
	    //parent->add_child(node->lookup_var_path(node->alias));
      }
    break;*/
  // add a variable to the list of operands
  //case adios2::detail::ExpressionOperator::OP_PATH:
      //parent->add_child(alias);
    //break;
  //case adios2::detail::ExpressionOperator::OP_NUM:
      //parent->set_base(value);
  //default:
  //  ExpressionTree expr;
    /*if (parent->detail.operation != operation)
      {
	expr = new ExpressionTree(operation);
	parent->add_child(expr);
      }
    else
      {
	expr = parent;
      }*/

  //}
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
