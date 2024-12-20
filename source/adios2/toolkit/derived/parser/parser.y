%skeleton "lalr1.cc"
%require "3.8.2"
%header

 //%define api.token.raw
%define api.namespace {adios2::detail}
//%define api.token.constructor
%define api.value.type {std::string}
%define parse.assert

%code requires {
  #include <tuple>
  #include <vector>
  #include <string>
  namespace adios2
  {
    namespace detail
    {
      class ASTDriver;
    }
  }
}

// The parsing context.
%param { ASTDriver& drv }

%locations

%define parse.trace
%define parse.error detailed
%define parse.lac full

%code {
#include "ASTDriver.h"
#include "ASTNode.h"
}

%define api.token.prefix {TOK_}

%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER INLINE RESTRICT
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token BOOL COMPLEX IMAGINARY
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

/*
%token
  ASSIGN  "="
  COMMA   ","
  COLON   ":"
  L_PAREN "("
  R_PAREN ")"
  L_BRACE "["
  R_BRACE "]"
;

%token <std::string> OPERATOR
%token <std::string> IDENTIFIER "identifier"
%token <std::string> VARNAME
%token <std::string> NUM
%nterm <int> list
%nterm <std::vector<std::tuple<int, int, int>>> indices_list
%nterm <std::tuple<int, int, int>> index
%left OPERATOR
*/

%start start_node
%%

primary_expression
	: IDENTIFIER { drv.createVariableNode($1); }
	| "@" CONSTANT // throw error if not int
	| CONSTANT { drv.createNumberNode($1); }
 //	| STRING_LITERAL
 //	| '(' expression ')'
	| '('  ')'
	;

postfix_expression
	: primary_expression
//  ?	| postfix_expression '[' expression ']'
//	| IDENTIFIER '(' ')'
	| IDENTIFIER '(' argument_expression_list ')' { drv.createOperatorNode($1, $3); }
	  /*	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
     	| postfix_expression '.' IDENTIFIER
	| postfix_expression PTR_OP IDENTIFIER
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
	| '(' type_name ')' '{' initializer_list '}'
	| '(' type_name ')' '{' initializer_list ',' '}'*/
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

unary_expression
	: postfix_expression
	  /*	| INC_OP unary_expression
		| DEC_OP unary_expression */
	| unary_operator cast_expression
	  /*	| SIZEOF unary_expression
		| SIZEOF '(' type_name ')'*/
	;

unary_operator
	: '-'
	;
	  /*
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;
	  */
// not used
cast_expression
	: unary_expression
	  //	| '(' type_name ')' cast_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression { drv.createOperatorNode($2, 2); }
	| multiplicative_expression '/' cast_expression { drv.createOperatorNode($2, 2); }
//	| multiplicative_expression '%' cast_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression { drv.createOperatorNode($2, 2); }
	| additive_expression '-' multiplicative_expression { drv.createOperatorNode($2, 2); }
	;

// not used
shift_expression
	: additive_expression
/*	| shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression
*/
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression   { drv.createConditionNode($2); }
	| relational_expression '>' shift_expression   { drv.createConditionNode($2); }
	| relational_expression LE_OP shift_expression { drv.createConditionNode($2); }
	| relational_expression GE_OP shift_expression { drv.createConditionNode($2); }
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression { drv.createConditionNode($2); }
	| equality_expression NE_OP relational_expression { drv.createConditionNode($2); }
	;

// not used
and_expression
	: equality_expression
//	| and_expression '&' equality_expression
	;

// not used
exclusive_or_expression
	: and_expression
//	| exclusive_or_expression '^' and_expression
	;

// not used
inclusive_or_expression
	: exclusive_or_expression
//	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression { drv.createRelationNode($2); }
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression { drv.createRelationNode($2); }
	;

conditional_expression
	: logical_or_expression
	  //	| logical_or_expression '?' expression ':' conditional_expression
	;

assignment_expression
	: conditional_expression
	  //	| unary_expression assignment_operator assignment_expression
	;

/*
assignment_operator
	: '='
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| LEFT_ASSIGN
	| RIGHT_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;
*/

expression
	: assignment_expression
	  //	| expression ',' assignment_expression
	;

assignment
	: IDENTIFIER '=' STRING_LITERAL { drv.add_lookup_entry($1,  $3); }
	| IDENTIFIER '=' IDENTIFIER     { drv.add_lookup_entry($1,  $3); }
	;

start_node
	: assignment ';' start_node
	| expression
	;

	/*

assignment:
  IDENTIFIER ASSIGN VARNAME { drv.add_lookup_entry($1,  $3); }
| IDENTIFIER ASSIGN IDENTIFIER { drv.add_lookup_entry($1,  $3); }
| IDENTIFIER ASSIGN VARNAME L_BRACE indices_list R_BRACE { drv.add_lookup_entry($1, $3, $5); }
| IDENTIFIER ASSIGN IDENTIFIER L_BRACE indices_list R_BRACE { drv.add_lookup_entry($1, $3, $5); }
;

exp:
  NUM { drv.createNumberNode($1); }
| exp OPERATOR exp { drv.createOperatorNode($2, 2); }
| "(" exp ")" {  }
| IDENTIFIER "(" list ")" { drv.createOperatorNode($1, $3); }
| IDENTIFIER "[" indices_list "]" { drv.createIndexNode($1, $3); }
| IDENTIFIER  { drv.createVariableNode($1); }
;


indices_list:
  %empty { $$ = {}; }
| indices_list COMMA index { $1.push_back($3); $$ = $1; }
| index { $$ = {$1}; }
;

index:
  %empty                  { $$ = {-1, -1,  1}; }
| NUM COLON NUM COLON NUM { $$ = {std::stoi($1), std::stoi($3), std::stoi($5)}; }
| COLON NUM COLON NUM     { $$ = {-1, std::stoi($2), std::stoi($4)}; }
| NUM COLON COLON NUM     { $$ = {std::stoi($1), -1, std::stoi($4)}; }
| NUM COLON NUM COLON     { $$ = {std::stoi($1), std::stoi($3),  1}; }
| NUM COLON NUM           { $$ = {std::stoi($1), std::stoi($3),  1}; }
| COLON COLON NUM         { $$ = {-1, -1, std::stoi($3)}; }
| COLON NUM COLON         { $$ = {-1, std::stoi($2),  1}; }
| COLON NUM               { $$ = {-1, std::stoi($2),  1}; }
| NUM COLON COLON         { $$ = {std::stoi($1), -1,  1}; }
| NUM COLON               { $$ = {std::stoi($1), -1,  1}; }
| NUM                     { $$ = {std::stoi($1), std::stoi($1),  1}; }
;

list:
  %empty { $$ = 0; }
| exp COMMA list { $$ = $3 + 1; }
| exp { $$ = 1; }

%%
	*/

%%
#include <stdio.h>

extern char yytext[];
extern int column;

void yyerror(char const *s)
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}

void
adios2::detail::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
