#include "ASTNode.h"

namespace adios2
{
namespace detail
{

VariableNode::VariableNode(std::string a)
  :alias(a)
{
}

VariableNode::~VariableNode()
{
}

std::string VariableNode::printpretty(std::string indent)
{
    std::string result = indent + "Variable Node:\n";
    if (!alias.empty())
    {
        result += indent + " (alias: \"" + alias + "\")\n";
    }
    if (!varname.empty())
    {
        result += indent + " (varname: \"" + varname + "\")\n";
    }
    else if (!alias.empty())
    {
        result += indent + " (varname not found)\n";
    }

    return result;
}

std::string VariableNode::get_alias() { return alias; }

std::string VariableNode::get_varname() { return varname; }

void VariableNode::set_varname(const std::string s) { varname = s; }

IndexNode::IndexNode(ASTNode *var, std::vector<std::tuple<int, int, int>> idx)
  : varnode(var), indices(idx)
{
}
  
IndexNode::~IndexNode()
{
  delete varnode;
}

std::string IndexNode::printpretty(std::string indent)
{
    std::string result = indent + "Index Node:\n";
    if (!indices.empty())
    {
        result += indent + " (indices: [ ";
        for (std::tuple<int, int, int> idx : indices)
        {
            result += std::to_string(std::get<0>(idx)) + ":";
            result += std::to_string(std::get<1>(idx)) + ":";
            result += std::to_string(std::get<2>(idx)) + " ";
        }
        result += "] )\n";
    }
    result += varnode->printpretty(indent + "    ");

    return result;
}
  
std::vector<std::tuple<int, int, int>> IndexNode::get_indices() { return indices; }

ASTNode *IndexNode::get_varnode() { return varnode; }
  
OperatorNode::OperatorNode(std::string op)
  : opname(op)
{
}

OperatorNode::OperatorNode(std::string op, size_t numsubexprs)
  : opname(op)
{
    sub_exprs.resize(numsubexprs);
}

OperatorNode::~OperatorNode()
{
    for (ASTNode *sub_expr : sub_exprs)
    {
        delete sub_expr;
    }
    sub_exprs.clear();
}

void OperatorNode::set_num_subexprs(size_t n) { sub_exprs.resize(n); }

void OperatorNode::pushback_subexpr(ASTNode *subexpr) { sub_exprs.push_back(subexpr); }

void OperatorNode::insert_subexpr_n(ASTNode *subexpr, size_t index) { sub_exprs[index] = subexpr; }

std::string OperatorNode::printpretty(std::string indent)
{
    std::string result = indent + "Operator Node: " + opname + "\n";

    for (ASTNode *node : sub_exprs)
    {
        result += node->printpretty(indent + "    ");
    }

    return result;
}

std::vector<ASTNode *> OperatorNode::get_subexprs() { return sub_exprs; }

std::string OperatorNode::get_opname() { return opname; }

NumberNode::NumberNode(std::string v)
  :value(v)
{
}

NumberNode::~NumberNode()
{
}

std::string NumberNode::printpretty(std::string indent)
{
    std::string result = indent + "Number Node: " + value + "\n";

    return result;
}

std::string NumberNode::get_value() { return value; }

}
}
