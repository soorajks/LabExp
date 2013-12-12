%{
#include "y.tab.h"
extern int yylval;
%}
num [0-9]+
%%
{num} {yylval=atoi(yytext); return NUM;}
\n {return *yytext;}
. {return *yytext;}
%%

