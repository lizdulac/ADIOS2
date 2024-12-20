#ifndef ASTNODE_HH
#define ASTNODE_HH
#include <string>
#include <tuple>
#include <vector>

namespace adios2
{
namespace detail
{

class ASTNode
{
public:
    ASTNode() {}
    ~ASTNode() {}

    virtual std::string printpretty(std::string = "") { return "NULL Node"; }
};

class VariableNode : public ASTNode
{
public:
    VariableNode(std::string alias);
    ~VariableNode();

    std::string printpretty(std::string = "");

    std::string get_alias();
    std::string get_varname();

    void set_varname(const std::string);

private:
    std::string alias;
    std::string varname;
};

class IndexNode : public ASTNode
{
public:
    IndexNode(ASTNode *var, std::vector<std::tuple<int, int, int>> indices);
    ~IndexNode();
  
    std::string printpretty(std::string = "");
    std::vector<std::tuple<int, int, int>> get_indices();
    ASTNode *get_varnode();
  
private:
    ASTNode *varnode;
    std::vector<std::tuple<int, int, int>> indices;
};

class OperatorNode : public ASTNode
{
public:
    OperatorNode(std::string opname);
    OperatorNode(std::string opname, size_t numsubexprs);
    ~OperatorNode();

    void set_num_subexprs(size_t);
    void pushback_subexpr(ASTNode *);
    void insert_subexpr_n(ASTNode *, size_t);
    std::string printpretty(std::string = "");

    std::vector<ASTNode *> get_subexprs();
    std::string get_opname();

private:
    std::vector<ASTNode *> sub_exprs;
    std::string opname;
};

class ConditionNode : public ASTNode
{
public:
    ConditionNode(std::string cond, ASTNode *expr1, ASTNode *expr2);
    ~ConditionNode();

    std::string printpretty(std::string = "");

    ASTNode *get_subexpr1();
    ASTNode *get_subexpr2();
    std::string get_condition();

private:
    ASTNode *subexpr1;
    ASTNode *subexpr2;
    std::string condition;
};

class RelationNode : public ASTNode
{
public:
    RelationNode(std::string rel, ASTNode *cond1, ASTNode *cond2);
    ~RelationNode();

    std::string printpretty(std::string = "");

    ASTNode *get_condition1();
    ASTNode *get_condition2();
    std::string get_relation();

private:
    ASTNode *condition1;
    ASTNode *condition2;
    std::string relation;
};

class NumberNode : public ASTNode
{
public:
    NumberNode(std::string);
    ~NumberNode();

    std::string printpretty(std::string = "");
    std::string get_value();

private:
    std::string value;
};

}
}
#endif // ! ASTNODE_HH
