#ifndef ADIOS2_DERIVED_PARSER_EXPHELPER_H_
#define ADIOS2_DERIVED_PARSER_EXPHELPER_H_

#include <map>
#include <tuple>
#include <string>
#include <vector>

namespace adios2{
    namespace detail{
 
  enum ExpressionOperator  {
    OP_NULL,
    OP_ALIAS, /* Parser-use only */
    OP_PATH, /* Parser-use only */
    OP_NUM, /* Parser-use only */
    OP_INDEX,
    OP_ADD,
    OP_SQRT,
    OP_POW,
    OP_MAGN
  };

namespace{
  const std::map<std::string, ExpressionOperator> string_to_op = {
      {"ALIAS", ExpressionOperator::OP_ALIAS}, /* Parser-use only */
      {"PATH", ExpressionOperator::OP_PATH}, /* Parser-use only */
      {"NUM", ExpressionOperator::OP_NUM}, /* Parser-use only */
      {"INDEX", ExpressionOperator::OP_INDEX},
      {"+", ExpressionOperator::OP_ADD},
      {"add", ExpressionOperator::OP_ADD},
      {"ADD", ExpressionOperator::OP_ADD},
      {"SQRT", ExpressionOperator::OP_SQRT},
      {"POW", ExpressionOperator::OP_POW},
      {"^", ExpressionOperator::OP_POW},
      {"MAGNITUDE", ExpressionOperator::OP_MAGN},
      {"magnitude", ExpressionOperator::OP_MAGN}
    };
      
    const std::map<ExpressionOperator, std::string> op_to_string = {
      {ExpressionOperator::OP_NULL, "NULL"},
      {ExpressionOperator::OP_ALIAS, "ALIAS"}, /* Parser-use only */
      {ExpressionOperator::OP_PATH, "PATH"}, /* Parser-use only */
      {ExpressionOperator::OP_NUM, "NUM"}, /* Parser-use only */
      {ExpressionOperator::OP_INDEX, "INDEX"},
      {ExpressionOperator::OP_ADD, "ADD"},
      {ExpressionOperator::OP_SQRT, "SQRT"},
      {ExpressionOperator::OP_POW, "POW"},
      {ExpressionOperator::OP_MAGN, "MAGNITUDE"}
    };
}
    inline std::string get_op_name(ExpressionOperator op)
    {
      return op_to_string.at(op);
    }

    inline ExpressionOperator get_op(std::string op)
    {
      return string_to_op.at(op);
    }

}
}
#endif