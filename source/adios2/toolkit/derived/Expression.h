#ifndef ADIOS2_DERIVED_Expression_H_
#define ADIOS2_DERIVED_Expression_H_

#include <string>
#include "adios2/common/ADIOSTypes.h"
//#include "adios2/core/IO.h"
#include "parser/parser.hpp"
#include "parser/ASTNode.h"

namespace adios2{

namespace derived{
/*
 A Note on Types:
 - Variables: detail is Variable Name (std::string). There should be no sub_exprs
 - Indexing/Slicing: detail is indices (std::vector<std::tuple<size_t start, size_t end, size_t stride>>
 - All other (normal) Operations: detail is ExprHelper::expr_op (operation)
 */

struct OpInfo
{
  adios2::detail::ExpressionOperator operation;
  std::vector<std::tuple<size_t, size_t, size_t> > indices;
  double constant;
};

class ExpressionTree
{
public:
  std::vector<std::tuple<ExpressionTree, std::string, bool>> sub_exprs;
  OpInfo detail;

  ExpressionTree() {};
  ExpressionTree(adios2::detail::ExpressionOperator  o) : detail({o,{},0}) {}
  ExpressionTree(adios2::detail::ExpressionOperator  o, double c) : detail({o,{},0}) {}
  ExpressionTree(std::vector<std::tuple<size_t, size_t, size_t> > indices)
    : detail({adios2::detail::ExpressionOperator ::OP_INDEX, indices, 0}) {}

  void set_base(double c)
  {
    detail.constant = c;
  }
  
  void add_child(ExpressionTree exp)
  {
    sub_exprs.push_back({exp, "", true});
  }

  void add_child(std::string var)
  {
    std::cout << "add_child with string: " << var << std::endl;

    sub_exprs.push_back({ExpressionTree(), var, false});
  }
  void add_child(std::string var, std::vector<std::tuple<size_t, size_t, size_t> >)
  {
    std::cout << "add_child with string: " << var << std::endl;
    // TODO: include indices
    sub_exprs.push_back({ExpressionTree(), var, false});
  }

  void print()
  {
    std::cout << "Print Expression:" << std::endl;
    std::cout << "\toperation: " << get_op_name(detail.operation) << std::endl;
    std::cout << "\tconstant: " << detail.constant << std::endl;
    std::cout << "\tchildren: " << sub_exprs.size() << std::endl;

    for (std::tuple<ExpressionTree, std::string, bool> t: sub_exprs)
      {
	if (std::get<2>(t) == true)
	  {
	    std::get<0>(t).print();
	  }
	else
	  {
	    std::cout << "string: " << std::get<1>(t) << std::endl;
	  }
      }
  }
};

class Expression
{
    ExpressionTree m_Exp;

    DataType m_Type;
    bool m_ConstantShape;
    Dims m_Shape;
    Dims m_Start;
    Dims m_Count;

    ExpressionTree ASTNode_to_ExpressionTree(adios2::detail::ASTNode* ASTTree);//, adios2::core::VarMap m_Variables);

public:
    Expression() = default;
    Expression(std::string expression);//, adios2::core::VarMap m_Variables);

    Dims GetShape();
    Dims GetStart();
    Dims GetCount();
    DataType GetDataType();
    bool IsConstantShape();

    bool CheckCorrectness();
    void ApplyExpression();
};

}
}
#endif
