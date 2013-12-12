%{
#include"y.tab.h"
%}
num [0-9]+
id [a-zA-Z_][a-zA-Z0-9]*
%%
while {return WHILE;}
do {return DO;}
{num} {return NUM;}
{id} {return ID;}
. {return *yytext;}
\n {return *yytext;}
%%

