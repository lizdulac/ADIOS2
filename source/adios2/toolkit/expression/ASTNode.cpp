#include "ASTNode.h"

/*****************************************/
// alias maps to pair of path and indices (indices may be empty string)
std::map<std::string, std::pair<std::string, std::string> > ASTNode::var_lookup;
int ASTNode::num_expr = 0;

ASTNode::ASTNode()
{
  // DEBUGGING
  ++num_expr;
  std::cout << "\tNum expressions: " << num_expr << std::endl;
}

ASTNode::ASTNode(ExprHelper::expr_op op)
  :operation(op)
{
  // DEBUGGING
  ++num_expr;
  std::cout << "creating ASTNode object with op: " << ExprHelper::get_op_name(operation) << ", operation: " << operation<< std::endl;
  std::cout << "\tNum expressions: " << num_expr << std::endl;
}

ASTNode::ASTNode(ExprHelper::expr_op op, const char *str)
  :operation(op)
{
  std::cout << "creating ASTNode object with op: " << op << " translated to operation (string): " << ExprHelper::get_op_name(op) << ", operation: " << operation << " and string: " << str << std::endl;
  switch(operation){
  case ExprHelper::OP_ALIAS:
    alias = str;
    break;
  case ExprHelper::OP_PATH:
    alias = str;
    break;
  case ExprHelper::OP_INDEX:
    indices = str;
    break;
  default:
    // Error
    std::cout << "***That's a problem... ASTNode constructed with string should be alias type, path type,  or index type\n";
  }
  // DEBUGGING  
  ++num_expr;
  std::cout << "\tNum expressions: " << num_expr << std::endl;
  }

ASTNode::ASTNode(ExprHelper::expr_op op, double val)
  :operation(op), value(val)
{
  // DEBUGGING
  ++num_expr;
  std::cout << "creating ASTNode object with op: " << op << " translated to operation (string): " << ExprHelper::get_op_name(operation) << ", operation: " << operation << " and value: " << value << std::endl;
  std::cout << "\tNum expressions: " << num_expr << std::endl;
}

ASTNode::ASTNode(ExprHelper::expr_op op, ASTNode *e)
  :operation(op)
{  
  sub_expr.push_back(e);
  // DEBUGGING
  ++num_expr;
  std::cout << "creating ASTNode object with op: " << op << " translated to operation (string): " << ExprHelper::get_op_name(operation) << ", operation: " << operation << " and subexpression with op: " << op << " translated to operation (string): " << ExprHelper::get_op_name(sub_expr[0]->operation) << std::endl;
  std::cout << "\tNum expressions: " << num_expr << std::endl;
}

// for index
ASTNode::ASTNode(ExprHelper::expr_op op, ASTNode *e, const char *str)
  :operation(op), indices(str)
{
   
  sub_expr.push_back(e);
  // DEBUGGING
  ++num_expr;
  std::cout << "creating ASTNode object with op: " << op << " translated to operation (string): " << ExprHelper::get_op_name(operation) << ", operation: " << operation << ", subexpression with op: " << op << " translated to operation (string): " << ExprHelper::get_op_name(sub_expr[0]->operation) << ", and indices " << indices << std::endl;
  std::cout << "\tNum expressions: " << num_expr << std::endl;
}

ASTNode::ASTNode(ExprHelper::expr_op op, ASTNode *e1, ASTNode *e2)
  :operation(op)
{
   
  sub_expr.push_back(e1);
  sub_expr.push_back(e2);
  // DEBUGGING
  ++num_expr;
  std::cout << "creating ASTNode object with op: " << op << " translated to operation (string): " << ExprHelper::get_op_name(operation) << ", operation: " << operation << " and subexpression1 with op: " << op << " translated to operation (string): " << ExprHelper::get_op_name(sub_expr[0]->operation) << " and subexpression2 with op: " << op << " translated to operation (string): " << ExprHelper::get_op_name(sub_expr[1]->operation) << std::endl;
  std::cout << "\tNum expressions: " << num_expr << std::endl;
}

// Copy constructor
ASTNode::ASTNode(const ASTNode &e)
    :operation(e.operation), alias(e.alias), value(e.value), sub_expr(e.sub_expr)
{
  // DEBUGGING
  ++num_expr;
  std::cout << "ASTNode Copy Constructor for op: " << ExprHelper::get_op_name(operation) << ", operation: " << operation << std::endl;
  std::cout << "\tNum expressions: " << num_expr << std::endl;
}

ASTNode::~ASTNode()
{
  for (ASTNode* e: sub_expr)
    {
      delete e;
    }
  // DEBUGGING
  --num_expr;
  std::cout << "Destructor called for expression with op: " << ExprHelper::get_op_name(operation) << ", operation: " << operation << std::endl;
  std::cout << "\tNum expressions: " << num_expr << std::endl;
}

  std::pair<std::string, std::string> ASTNode::lookup_var(const std::string var_alias)
  {
    return var_lookup[var_alias];
  }

  std::string ASTNode::lookup_var_path(const std::string var_alias)
  {
    return var_lookup[var_alias].first;
  }

  std::string ASTNode::lookup_var_indices(const std::string var_alias)
  {
    return var_lookup[var_alias].second;
  }

  void ASTNode::add_lookup_entry(const std::string alias, const std::string var_name, const std::string indices)
  {
    std::cout << "Adding alias to lookup table:\n\talias: " << alias << "\n\tvar_name: " << var_name << "\n\tindices: " << indices <<  std::endl;
    var_lookup[alias] = std::make_pair(var_name, indices);
  }
  
  void ASTNode::add_operand(const ASTNode* e){}

//  void ASTNode::assign_type(enum types t){}
  
  void ASTNode::infer_type(){}

  void ASTNode::printpretty(std::string indent)
  {
    std::cout << indent << ExprHelper::get_op_name(operation) << ":";
    switch (operation) {
    case ExprHelper::OP_ALIAS:
	std::cout << " (alias " << alias << " maps to Variable '";
	std::cout << lookup_var_path(alias) << "'";
	if (lookup_var_indices(alias) != "")
	  {
	    std::cout << " [" << lookup_var_indices(alias) << "]";
	  }
	std::cout << ")";
      break;
    case ExprHelper::OP_PATH:
	std::cout << " (" << alias << ")";
      break;
    case ExprHelper::OP_INDEX:
	std::cout << " [" << indices << "]";
      break;
    }    
    std::cout << std::endl;
    for (ASTNode* e: sub_expr)
      {
	e->printpretty(indent + "    ");
      }
  }

void ASTNode::to_expr(Expression *parent)
{
  switch (operation) {
  case ExprHelper::OP_ALIAS:
    // TODO: populate index vector
    if (lookup_var_indices(alias) == "")
      {
	parent->add_child(lookup_var_path(alias), {});
      } else {
	parent->add_child(lookup_var_path(alias));
      }
    break;
  case ExprHelper::OP_PATH:
      parent->add_child(alias);
    break;
  case ExprHelper::OP_NUM:
      parent->add_child(value);
  default:
      Expression *expr = parent->add_child(operation);
      for (ASTNode* e: sub_expr)
	{
	  e->to_expr(expr);
	}
      }
}
