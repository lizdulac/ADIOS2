/* calculator. */
%{
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
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
  struct custom_data* expr;
}

%error-verbose
%locations

%start input
%token MULT DIV PLUS MINUS L_PAREN R_PAREN END
%token SQRT
%token SIN COS TAN
%token MAGNITUDE CURL
%token NUMBER
%type <dval> NUMBER
%type <expr> input exp
%left PLUS MINUS
%left MULT DIV
%nonassoc UMINUS


%% 

input:		        exp END         { yyparse_value = $1->expression; }
			;

exp:		        NUMBER                { void* expr = malloc(sizeof(Number<double>)); struct custom_data* cd = new struct custom_data; Number<double>* num = new(expr) Number<double>($1); cd->expression = num; $$ = cd;}
                        | exp PLUS exp        { void* expr = malloc(sizeof(Addition<double>)); struct custom_data* cd = new struct custom_data; Addition<double>* add = new(expr) Addition<double>($1->expression, $3->expression); cd->expression = add; $$ = cd; }
                        | exp MINUS exp        { void* expr = malloc(sizeof(Subtraction<double>)); struct custom_data* cd = new struct custom_data; Subtraction<double>* subtr = new(expr) Subtraction<double>($1->expression, $3->expression); cd->expression = subtr; $$ = cd; }
                        | exp MULT exp        { void* expr = malloc(sizeof(Multiplication<double>)); struct custom_data* cd = new struct custom_data; Multiplication<double>* mult = new(expr) Multiplication<double>($1->expression, $3->expression); cd->expression = mult; $$ = cd; }
                        | exp DIV exp        { void* expr = malloc(sizeof(Division<double>)); struct custom_data* cd = new struct custom_data; Division<double>* div = new(expr) Division<double>($1->expression, $3->expression); cd->expression = div; $$ = cd; }
                        | MINUS exp %prec UMINUS        { void* expr = malloc(sizeof(Negation<double>)); struct custom_data* cd = new struct custom_data; Negation<double>* negative = new(expr) Negation<double>($2->expression); cd->expression = negative; $$ = cd; }
			| L_PAREN exp R_PAREN { $$ = $2; }
			;
%%

void parse_expression(char* input) {
  /*
  if (argc > 1) {
      yyin = fopen(argv[1], "r");
      if (yyin == NULL){
         printf("syntax: %s filename\n", argv[0]);
      }//end if
   }//end if
  */
  //yyinput = input;
  yy_scan_string(input);
   yyparse(); // Calls yylex() for tokens.
   if (yyparse_value == nullptr)
     {
       printf("Parsed tree, but didn't return correctly\n");
     }else{
       printf("Parsed tree: %s\n", yyparse_value->printpretty("    ").c_str());
   }
}

void yyerror(const char *msg) {
   printf("** Line %d: %s\n", yylloc.first_line, msg);
}


