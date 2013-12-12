%{
#include "stdio.h"
%}
%token ID
%token NUM
%%
S:E '\n' {printf("Accepted..\n");return 0;}
E:E '+' T|E '-' T|T;
T:T '*' F|T '/' F|F;
F:ID|NUM| '(' E ')';
%%
main()
{
yyparse();
}
int yywrap()
{
return 1;
}
void yyerror()
{
printf("Rejected\n");
}
