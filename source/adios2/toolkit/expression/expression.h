#include <tuple>
#include <string>
#include <vector>

#include "ExprHelper.h"

/*
 A Note on Types:
 - Variables: detail is Variable Name (std::string). There should be no sub_exprs
 - Indexing/Slicing: detail is indices (std::vector<std::tuple<size_t start, size_t end, size_t stride>>
 - All other (normal) Operations: detail is ExprHelper::expr_op (operation)
 */

struct OpInfo
{
  ExprHelper::expr_op operation;
  std::vector<std::tuple<size_t, size_t, size_t> > indices;
  double constant;
};

class Expression
{
public:
  std::vector<std::tuple<Expression*, std::string>> sub_exprs;
  OpInfo detail;

  Expression() {};
  Expression(ExprHelper::expr_op o) : detail({o,{},0}) {}
  Expression(ExprHelper::expr_op o, double c) : detail({o,{},0}) {}
  Expression(std::vector<std::tuple<size_t, size_t, size_t> > indices)
    : detail({ExprHelper::OP_INDEX, indices,0}) {}

  void set_base(double c)
  {
    detail.constant = c;
  }
  
  void add_child(Expression *exp)
  {
    sub_exprs.push_back({exp, ""});
  }

  void add_child(std::string var)
  {
    std::cout << "add_child with string: " << var << std::endl;
    sub_exprs.push_back({nullptr, var});
  }
  void add_child(std::string var, std::vector<std::tuple<size_t, size_t, size_t> >)
  {
    std::cout << "add_child with string: " << var << std::endl;
    // TODO: include indices
    sub_exprs.push_back({nullptr, var});
  }

  void print()
  {
    std::cout << "Print Expression:" << std::endl;
    std::cout << "\toperation: " << ExprHelper::get_op_name(detail.operation) << std::endl;
    std::cout << "\tconstant: " << detail.constant << std::endl;
    std::cout << "\tchildren: " << sub_exprs.size() << std::endl;

    for (std::tuple<Expression*, std::string> t: sub_exprs)
      {
	if (std::get<0>(t) != nullptr)
	  {
	    std::get<0>(t)->print();
	  }
	else
	  {
	    std::cout << "string: " << std::get<1>(t) << std::endl;
	  }
      }
  }
};
