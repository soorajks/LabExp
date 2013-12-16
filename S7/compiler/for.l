%{
#include "y.tab.h"
#include<stdio.h>
%}
num [0-9]+
id [a-zA-Z_][a-zA-Z0-9]*
%%
for {return FOR;}
{num} {return NUM;}
{id} {return ID;}
. {return *yytext;}
\n {return *yytext;}
%%

