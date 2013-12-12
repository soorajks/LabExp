%{
#include<stdlib.h>
#include "y.tab.h"
extern int yylval;
%}
num ([0-9]+|[0-9]*)(\.([0-9]+))?
%%
{num} {yylval=atoi(yytext);return NUM;}
[+\-*/] {return *yytext;}
[\(\)] {return *yytext;}
[\n] {return *yytext;}
%%

