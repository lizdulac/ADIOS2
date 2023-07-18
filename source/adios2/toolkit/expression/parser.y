/* calculator. */
%{
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
 #include <string>
 #include <vector>
 #include <iostream>
 #include "lexer.h"
 #include "expression.h"

  extern int yyparse();

  static Expression<double>* yyparse_value;
  
 // Here is an example how to create custom data structure
 typedef struct custom_data {
   Expression<double>* expression;
 } custom_data;

  void yyerror(const char *msg);

%}

%union{
  double dval;
  int ival;
  char* sval;
  struct custom_data* expr;
}

%error-verbose
%locations

%start input
%token SQRT POW
%token SIN COS TAN
%token MAGNITUDE CURL
%token MULT DIV PLUS MINUS L_PAREN R_PAREN ENDL
%token NUMBER
%token ALIAS PATH
%type <dval> NUMBER
%type <sval> ALIAS PATH
%type <expr> input exp
%left PLUS MINUS
%left MULT DIV
%right POW
%nonassoc UMINUS


%% 

input:                  {}
                        | ENDL input             {}
                        | decl input             {}
                        | exp input              { yyparse_value = $1->expression; }
			;

decl:                   ALIAS PATH      { add_var($1,$2); }
                        ;

exp:                    ALIAS                  { void* expr = malloc(sizeof(Alias<double>)); struct custom_data* cd = new struct custom_data; Alias<double>* var = new(expr) Alias<double>($1); cd->expression = var; $$ = cd; }
                        | NUMBER                { void* expr = malloc(sizeof(Number<double>)); struct custom_data* cd = new struct custom_data; Number<double>* num = new(expr) Number<double>($1); cd->expression = num; $$ = cd;}
			| L_PAREN exp R_PAREN { $$ = $2; }
                        | exp MULT exp        { void* expr = malloc(sizeof(Multiplication<double>)); struct custom_data* cd = new struct custom_data; Multiplication<double>* mult = new(expr) Multiplication<double>($1->expression, $3->expression); cd->expression = mult; $$ = cd; }
                        | exp DIV exp        { void* expr = malloc(sizeof(Division<double>)); struct custom_data* cd = new struct custom_data; Division<double>* div = new(expr) Division<double>($1->expression, $3->expression); cd->expression = div; $$ = cd; }
                        | exp PLUS exp        { void* expr = malloc(sizeof(Addition<double>)); struct custom_data* cd = new struct custom_data; Addition<double>* add = new(expr) Addition<double>($1->expression, $3->expression); cd->expression = add; $$ = cd; }
                        | exp MINUS exp        { void* expr = malloc(sizeof(Subtraction<double>)); struct custom_data* cd = new struct custom_data; Subtraction<double>* subtr = new(expr) Subtraction<double>($1->expression, $3->expression); cd->expression = subtr; $$ = cd; }
                        | MINUS exp %prec UMINUS        { void* expr = malloc(sizeof(Negation<double>)); struct custom_data* cd = new struct custom_data; Negation<double>* negative = new(expr) Negation<double>($2->expression); cd->expression = negative; $$ = cd; }
                        | SQRT L_PAREN exp R_PAREN        { void* expr = malloc(sizeof(Sqrt<double>)); struct custom_data* cd = new struct custom_data; Sqrt<double>* sqrt = new(expr) Sqrt<double>($3->expression); cd->expression = sqrt; $$ = cd; }
                        | exp POW exp        { void* expr = malloc(sizeof(Pow<double>)); struct custom_data* cd = new struct custom_data; Pow<double>* pow = new(expr) Pow<double>($1->expression, $3->expression); cd->expression = pow; $$ = cd; }
			;
%%

std::vector<std::string> parse_expression(const char* input) {
  yy_scan_string(input);
   yyparse();

   // DEBUGGING
   if (yyparse_value == nullptr)
     {
       printf("Parsed tree, but didn't return correctly\n");
     }else{
       printf("Parsed tree: %s\n", yyparse_value->printpretty("    ").c_str());
       }
   // END DEBUGGING

   std::vector<std::string> ret;
    yyparse_value->get_var(&ret);
    return ret;
}

void yyerror(const char *msg) {
   printf("** Line %d: %s\n", yylloc.first_line, msg);
}


