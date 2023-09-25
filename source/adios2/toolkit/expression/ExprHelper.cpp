#include "ExprHelper.h"

const std::map<const char*, ExprHelper::expr_op> ExprHelper::string_to_op = {
  {"ALIAS", ExprHelper::OP_ALIAS}, /* Parser-use only */
  {"PATH", ExprHelper::OP_PATH}, /* Parser-use only */
  {"NUM", ExprHelper::OP_NUM}, /* Parser-use only */
  {"INDEX", ExprHelper::OP_INDEX},
  {"ADD", ExprHelper::OP_ADD},
  {"SQRT", ExprHelper::OP_SQRT},
  {"POW", ExprHelper::OP_POW},
  {"MAGNITUDE", ExprHelper::OP_MAGN}
};
  
const std::map<ExprHelper::expr_op, std::string> ExprHelper::op_to_string = {
  {ExprHelper::OP_ALIAS, "ALIAS"},
  {ExprHelper::OP_PATH, "PATH"},
  {ExprHelper::OP_NUM, "NUM"},
  {ExprHelper::OP_INDEX, "INDEX"},
  {ExprHelper::OP_ADD, "ADD"},
  {ExprHelper::OP_SQRT, "SQRT"},
  {ExprHelper::OP_POW, "POW"},
  {ExprHelper::OP_MAGN, "MAGNITUDE"}
};

std::string ExprHelper::get_op_name(ExprHelper::expr_op op)
{
  return ExprHelper::op_to_string.at(op);
}

ExprHelper::expr_op ExprHelper::get_op(const char *op)
{
  return ExprHelper::string_to_op.at(op);
}
