%{   
#include "parser.hpp"
#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno;
%}

%option noyywrap


DIGIT    [0-9]
CHAR     ([a-z]|[A-Z])
   
%%

"+"            {return PLUS;}
"-"            {return MINUS;}
"*"            {return MULT;}
"/"            {return DIV;}
"("            {return L_PAREN;}
")"            {return R_PAREN;}
"sqrt"         {return SQRT;}
"^"            {return POW;}
"sin"          {return SIN;}
"cos"          {return COS;}
"tan"          {return TAN;}
"magnitude"    {return MAGNITUDE;}
"curl"         {return CURL;}


(\.{DIGIT}+)|({DIGIT}+(\.{DIGIT}*)?([eE][+-]?[0-9]+)?)   {yylval.dval = atof(yytext); return NUMBER;}

[ \t]+         {/* ignore spaces */}

(\n|\0|EOF|$end)           {return ENDL;}

({CHAR}|{DIGIT}|_)+        {yylval.sval=strdup(yytext); return ALIAS;}

:(\\|\/|_|{DIGIT})*{CHAR}+(\\|\/|-|_|{DIGIT}|{CHAR})*      {yylval.sval=strndup(yytext + 1,strlen(yytext)-1); return PATH;}

'(\\|\/|_|{DIGIT})*{CHAR}+(\\|\/|-|_|{DIGIT}|{CHAR})*'     {yylval.sval=strndup(yytext + 1,strlen(yytext)-2); return PATH;}

"["({DIGIT}+|{DIGIT}*":"{DIGIT}*":"{DIGIT}*)(,({DIGIT}+|{DIGIT}*":"{DIGIT}*":"{DIGIT}*))*"]"                            {yylval.sval=strndup(yytext + 1,strlen(yytext)-2); return INDICES;}

.              {printf("Error at line %d: unrecognized symbol \"%s\"\n", yylloc.first_line, yytext); exit(0);}

%%
