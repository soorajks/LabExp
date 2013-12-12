%{
#include<stdio.h>
%}
%token WHILE
%token NUM
%token ID
%token DO
%%
S: WHILE '(' check ')' NL BLK {printf("accepted \n ");return 0;} | DO NL BLK WHILE '(' check ')' ';' {printf("accepted \n");return 0;};
BLK: expr ';' | '{' NL exprlist '}' | ;
exprlist: expr ';' NL exprlist | expr ';' NL;
check: cond | E;
expr: check |E1 '=' E;
NL:'\n' |;
E: T '+' E | T;
T: F '*' T | F;
F: B | '('  E ')' ;
cond: B '=' '=' B
	|B '!' '=' B
	|B '>' B
	|B '<' B 
	|B '>' '=' B
	|B '<' '=' B
	|E '&' '&' B
	|E '|' '|' E;
E1: ID;
B: E1|NUM;
%%
int yywrap()
{
	return 1;
}
void yyerror(char *s)
{
	printf("%s \n",s);
}
main()
{
	if(yyparse())
	{
		printf("not accepted\n");}
	}

