%{   
#include "parser.h"
#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno;
%}

%option noyywrap


DIGIT    [0-9]
   
%%

"-"            {return MINUS;}
"+"            {return PLUS;}
"*"            {return MULT;}
"/"            {return DIV;}
"("            {return L_PAREN;}
")"            {return R_PAREN;}
"sqrt"         {return SQRT;}
"sin"          {return SIN;}
"cos"          {return COS;}
"tan"          {return TAN;}
"magnitude"    {return MAGNITUDE;}
"curl"         {return CURL;}


(\.{DIGIT}+)|({DIGIT}+(\.{DIGIT}*)?([eE][+-]?[0-9]+)?)   {return NUMBER;}

[ \t]+         {/* ignore spaces */}

[\n<<EOF>>$end]           {return END;}

.              {printf("Error at line %d: unrecognized symbol \"%s\"\n", yylloc.first_line, yytext); exit(0);}

%%
