#include "ASTDriver.h"

namespace adios2
{
namespace detail
{

using indx_type = std::vector<std::tuple<int, int, int>>;

ASTDriver::ASTDriver() {}

ASTDriver::ASTDriver(const std::string input)
{
  std::cout << "ASTDriver parsing input expression \"" << input << "\"" << std::endl;
  ASTDriver::parse(input);
}

ASTDriver::~ASTDriver()
{
    ASTDriver::destroy_lex_structures();
    while (holding.size() > 0)
    {
        delete holding.top();
        holding.pop();
    }
}

ASTNode *ASTDriver::getAST()
{
    // TODO: check only one ASTNode remains in holding
    // else throw error that parsing failed
    resolve(holding.top());
    std::cout << "ASTDriver, expression has been parsed. Created Abstract Syntax Tree:\n";
    std::cout << holding.top()->printpretty() << std::endl;
    return holding.top();
}

void ASTDriver::resolve(ASTNode *node)
{
    if (VariableNode *varnode = dynamic_cast<VariableNode*>(node))
    {
        std::tuple<std::string, indx_type> var_info;
        var_info = lookup_var(varnode->get_alias());
        varnode->set_varname(std::get<0>(var_info));
	indx_type i = std::get<1>(var_info);
	if (i.size() > 0)
	  {
	    node = new IndexNode(varnode, i);
	  }
    }
    else if (OperatorNode *opnode = dynamic_cast<OperatorNode*>(node))
    {   
        for (ASTNode *subexpr : opnode->get_subexprs())
        {
            resolve(subexpr);
        }
    }
    else if (IndexNode *idxnode = dynamic_cast<IndexNode*>(node))
    {
        resolve(idxnode->get_varnode());
    }
}

std::tuple<std::string, indx_type> ASTDriver::lookup_var(const std::string alias)
{
    return aliases[alias];
}

std::string ASTDriver::lookup_var_name(const std::string alias)
{
    std::tuple<std::string, indx_type> var = aliases[alias];
    return std::get<0>(var);
}

indx_type ASTDriver::lookup_var_indices(const std::string alias)
{
    std::tuple<std::string, indx_type> var = aliases[alias];
    return std::get<1>(var);
}

void ASTDriver::add_lookup_entry(std::string alias, std::string var_name, indx_type indices)
{
    aliases.insert({alias, {var_name, indices}});
}

void ASTDriver::add_lookup_entry(std::string alias, std::string var_name)
{
    aliases.insert({alias, {var_name, {}}});
}

void ASTDriver::createOperatorNode(std::string op_name, size_t numsubexprs)
{
    OperatorNode *node = new OperatorNode(op_name, numsubexprs);
    for (size_t i = 1; i <= numsubexprs; ++i)
    {
        // TODO: check that holding contains ASTNode(s)
        // else throw error that parsing failed
        ASTNode *subexpr = holding.top();
        node->insert_subexpr_n(subexpr, numsubexprs - i);
        holding.pop();
    }
    holding.push(node);
}

void ASTDriver::createConditionNode(std::string condition)
{
    ASTNode *subexpr1 = holding.top();
    holding.pop();
    ASTNode *subexpr2 = holding.top();
    holding.pop();
    ConditionNode *node = new ConditionNode(condition, subexpr1, subexpr2);
    holding.push(node);
}

void ASTDriver::createRelationNode(std::string relation)
{
    ASTNode *subexpr1 = holding.top();
    holding.pop();
    ASTNode *subexpr2 = holding.top();
    holding.pop();
    ConditionNode *node = new ConditionNode(relation, subexpr1, subexpr2);
    holding.push(node);
}

void ASTDriver::createVariableNode(std::string alias)
{
    VariableNode *node = new VariableNode(alias);
    holding.push(node);
}

void ASTDriver::createIndexNode(std::string alias, indx_type indices)
{
    VariableNode *var = new VariableNode(alias);
    IndexNode *node = new IndexNode(var, indices);
    holding.push(node);
}

void ASTDriver::createNumberNode(std::string value)
{
  NumberNode *node = new NumberNode(value);
  holding.push(node);
}

}
}
