%{ 
#include<stdio.h>
%}
%token SWITCH
%token BREAK
%token ID
%token NUM
%token CASE
%token DEFAULT
%token NO
%%
SS: S'\n' {printf("Accepted");return 0;}
S: SWITCH '('ID')'line BLK;
BLK: '{'line BODY'}'|;
BODY: CASE ' 'NUM':'line expr line BODY|DEFAULT ':'line expr line| CASE ' 'NO':'line expr line BODY|;
expr: E';'line expr|ID'='E';'line expr|BREAK';'|'{'expr'}' |;
E: T'+'E|T'-'E|T;
T: T'*'F';'|T'/'F|F;
F: ID|NUM|'('E')';
line : '\n'|;
%%
int yywrap()
{
return 1;
}
void yyerror(char *s)
{
}
main()
{
	if(yyparse())
	{
		printf("Not Accepted");
	}
}
