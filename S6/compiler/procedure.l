%{
#include<stdio.h>
#include"y.tab.h"
%}
id [a-zA-Z][a-zA-Z0-9]*
num [0-9]+
%option noyywrap
%%
"void"|"int"|"char"|"float"|"double" {return DATA;}
{id} {return ID;}
{num} {return NUM;}

"\n" {return *yytext;}
. {return *yytext;}
%%
