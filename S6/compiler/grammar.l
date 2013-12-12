%{
#include "y.tab.h"
%}

id [A-Za-z][A-Za-z0-9_]*
num [0-9]+
op [+\-*/]

%%
{op} {return *yytext;}
{id} {return ID;}
{num} {return NUM;}
"("|")"|"\n" {return *yytext;}
. {return *yytext;}
%%
