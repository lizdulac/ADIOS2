#ifndef ADIOS2_DERIVED_Expression_H_
#define ADIOS2_DERIVED_Expression_H_

#include "Function.h"
#include "adios2/common/ADIOSTypes.h"
#include "parser/ASTNode.h"
#include "parser/parser.hpp"
#include <string>
#include <unordered_map>

namespace adios2
{

namespace derived
{
/*
 A Note on Types:
 - Variables: detail is Variable Name (std::string). There should be no sub_exprs
 - Indexing/Slicing: detail is indices (std::vector<std::tuple<size_t start, size_t end, size_t
 stride>>
 */
struct OpInfo
{
    adios2::detail::ExpressionOperator operation;
    std::vector<std::tuple<size_t, size_t, size_t>> indices;
    double constant;
};

class ExpressionTree
{
public:
    std::vector<std::tuple<ExpressionTree, std::string, bool>> sub_exprs;
    OpInfo detail;

    ExpressionTree(){};
    ExpressionTree(adios2::detail::ExpressionOperator o) : detail({o, {}, 0}) {}
    ExpressionTree(adios2::detail::ExpressionOperator o, double c) : detail({o, {}, 0}) {}
    ExpressionTree(std::vector<std::tuple<size_t, size_t, size_t>> indices)
    : detail({adios2::detail::ExpressionOperator ::OP_INDEX, indices, 0})
    {
    }

    void set_base(double c);
    void set_indeces(std::vector<std::tuple<size_t, size_t, size_t>> index_list);

    void add_child(ExpressionTree exp);
    void add_child(std::string var);

    std::vector<std::string> VariableNameList();
    Dims GetDims(std::map<std::string, Dims> NameToDims);
    std::vector<DerivedData>
    ApplyExpression(DataType type, size_t numBlocks,
                    std::map<std::string, std::vector<DerivedData>> nameToData);
    void print();
};

class Expression
{
    ExpressionTree m_Expr;

    Dims m_Shape;
    Dims m_Start;
    Dims m_Count;

    ExpressionTree ASTNode_to_ExpressionTree(adios2::detail::ASTNode *ASTTree);

public:
    Expression() = default;
    Expression(std::string expression);

    std::string ExprString;

    Dims GetShape();
    Dims GetStart();
    Dims GetCount();
    void SetDims(std::map<std::string, std::tuple<Dims, Dims, Dims>> NameToDims);
    std::vector<std::string> VariableNameList();
    std::vector<DerivedData>
    ApplyExpression(DataType type, size_t numBlocks,
                    std::map<std::string, std::vector<DerivedData>> nameToData);
};

}
}
#endif
