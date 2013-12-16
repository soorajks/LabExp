%{
#include"y.tab.h"
%}
num [0-9]+ 
no ['][a-z][']
id [a-zA-Z_][A-Za-z0-9_]*
%%
switch {return SWITCH;}
{no} {return NO;}
case {return CASE;}
break {return BREAK;}
default {return DEFAULT;}
{num} {return NUM;}
{id} {return ID;}
. {return *yytext;}                      
\n {return *yytext;}
%%


