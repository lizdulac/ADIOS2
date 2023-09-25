/* calculator. */
%{
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
 #include <stack>
 #include <string>
 #include <vector>
 #include <iostream>
 #include "lexer.h"
 #include "ASTNode.h"
  
  extern int yyparse(std::stack<ASTNode*>* expr_stack);

  void* createExpr(std::stack<ASTNode*>*, ExprHelper::expr_op, const char*, double, size_t);
  
  static void* yyparse_value;  

  void yyerror(std::stack<ASTNode*>* expr_stack, const char *msg);

%}

%parse-param {std::stack<ASTNode*>* expr_stack}

%union{
  double dval;
  int ival;
  char* sval;
  void* expr_ptr;
}

%error-verbose
%locations

%start input
%token COMMA L_PAREN R_PAREN ENDL
%token SQRT POW
%token SIN COS TAN
%token MAGNITUDE CURL
%token MULT DIV PLUS MINUS INDICES
%token NUMBER
%token ALIAS PATH
%type <dval> NUMBER
%type <sval> ALIAS PATH INDICES
%type <expr_ptr> input exp
%left PLUS MINUS
%left MULT DIV
%right POW
%nonassoc UMINUS


%% 

input:                  {}
                        | ENDL input             {}
                        | decl input             {}
| exp input              { /*yyparse_value = $1->expression;*/ }
			;

decl:                   ALIAS PATH               { ASTNode::add_lookup_entry($1, $2, ""); }
| ALIAS PATH INDICES     { ASTNode::add_lookup_entry($1, $2, $3); }
                        ;

//index:                  NUMBER comma index { ASTNode::extend_current_lookup_indices($1); }
//                        | NUMBER { ASTNode::extend_current_lookup_indices($1); }
//                        ;

list: exp COMMA list {}
| exp {}
;

exp:                    ALIAS                  { $$ = createExpr(expr_stack, ExprHelper::OP_ALIAS, $1, 0, 0); }
| ALIAS INDICES         { createExpr(expr_stack, ExprHelper::OP_ALIAS, $1, 0, 0); $$ = createExpr(expr_stack, ExprHelper::OP_INDEX, $2, 0, 1); }
| PATH                  { $$ = createExpr(expr_stack, ExprHelper::OP_PATH, $1, 0, 0); }
| NUMBER                { $$ = createExpr(expr_stack, ExprHelper::OP_NUM, "", $1, 0); }
| L_PAREN exp R_PAREN { $$ = $2; }
| exp PLUS exp { $$ = createExpr(expr_stack, ExprHelper::OP_ADD, "", 0, 2); }
| MAGNITUDE L_PAREN exp R_PAREN { $$ = createExpr(expr_stack, ExprHelper::OP_MAGN, "", 0, 1);}
			;
%%

void* createExpr(std::stack<ASTNode*>* expr_stack, ExprHelper::expr_op op, const char* name, double value, size_t numsubexprs) {
  std::cout << "Creating ASTNode in function createExpr" << std::endl;
  std::cout << "\tstack size: " << expr_stack->size() << "\n\top: " << op << "\n\tname: " << name << "\n\tvalue: " << value << "\n\tnumsubexprs: " << numsubexprs << std::endl;

  ASTNode *subexpr1, *subexpr2;
  switch(numsubexprs) {
  case 0:
    if (op == ExprHelper::OP_ALIAS)
      {
	expr_stack->push(new ASTNode(op, name));
      } else if (op == ExprHelper::OP_PATH)
      {
	expr_stack->push(new ASTNode(op, name));
      } else if (op == ExprHelper::OP_NUM)
      {
	expr_stack->push(new ASTNode(op, value));
      }
    break;
  case 1:
    subexpr1 = expr_stack->top();
    expr_stack->pop();
    if (op == ExprHelper::OP_INDEX)
      {
	expr_stack->push(new ASTNode(op, subexpr1, name));
	
      } else {
      expr_stack->push(new ASTNode(op, subexpr1));
    }
    break;
  case 2:
    std::cout << "Case 2:" << std::endl;
    subexpr2 = expr_stack->top();
    expr_stack->pop();
    subexpr1 = expr_stack->top();
    expr_stack->pop();
    std::cout << "\tpush new ASTNode" << std::endl;
    expr_stack->push(new ASTNode(op, subexpr1, subexpr2));
    break;
  }

  return &expr_stack->top();
}

Expression* parse_expression(const char* input) {
  yy_scan_string(input);
  std::stack<ASTNode*> expr_stack;
  yyparse(&expr_stack);

  // DEBUGGING
  std::cout << "yyparse complete. Stack size: " << expr_stack.size() << std::endl;
  std::cout << "parser prettyprint:" << std::endl;
  expr_stack.top()->printpretty("");

  Expression *root = new Expression();
  expr_stack.top()->to_expr(root);
  return root;
}

void yyerror(std::stack<ASTNode*>* expr_stack, const char *msg) {
   printf("** Line %d: %s\n", yylloc.first_line, msg);
}


