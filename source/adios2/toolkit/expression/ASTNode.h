#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Expression.h"

/*****************************************/


class ASTNode
{
public:
  ASTNode();
  ASTNode(ExprHelper::expr_op);
  ASTNode(ExprHelper::expr_op, const char *a);
  ASTNode(ExprHelper::expr_op, double val);
  ASTNode(ExprHelper::expr_op, ASTNode *e);
  ASTNode(ExprHelper::expr_op, ASTNode *e, const char *i);
  ASTNode(ExprHelper::expr_op, ASTNode *e1, ASTNode *e2);

  // Copy constructor
  ASTNode(const ASTNode &e);

  ~ASTNode();

  static std::pair<std::string, std::string> lookup_var(const std::string var_alias);
  static std::string lookup_var_path(const std::string var_alias);
  static std::string lookup_var_indices(const std::string var_alias);
  static void add_lookup_entry(const std::string alias, const std::string var_name, const std::string indices);
  
  void add_operand(const ASTNode* e);
  //void assign_type(enum types t);
  void infer_type();
  void printpretty(std::string indent = "");
  void to_expr(Expression*);

  //private:
  ExprHelper::expr_op operation;
  std::string op_name;
  std::string alias;
  std::string indices;
  double value;
  //enum ops operation;
  //enum types type;
  std::vector<ASTNode*> sub_expr;
  /*
  struct var_lookup_entry
  {
    std::string path;
    std::vector<std::pair<bool, size_t>> indices;
    //adios2::Variable var;
    
  }
  static std::map<std::string, struct var_lookup_entry> var_lookup;
  */
  static std::map<std::string, std::pair<std::string, std::string> > var_lookup;
  // DEBUGGING
  static int num_expr;
};
