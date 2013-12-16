%{
#include<stdio.h>
%}
%token FOR
%token NUM
%token ID
%%
SS: A '\n' {printf("accepted ");return 0;};
A: S ';' |S '\n' '{' '\n' EL '}'|S '\n' EX ';'|S '\n' AS ';' ;
S: FOR '(' AS ';' CS ';' EX  ')'|'(' AS ';' CS ';' EX ',' EX ')' ;
AS: ID '=' RV|;
CS: ID cndop RV|;
RV: ID|NUM|CS;
E: ID inc|;
inc: '+' '+'|'-' '-' |;
EL: EX ';' '\n'EL|EX;
EX: ID '=' RV op RV|E;
op: '+'|'-'|'*'|'/';
cndop: '='|'!' '='|'>' '='|'<' '='|'<'|'>'|'&''&'|'|''|';

%%
int yywrap()
{
return 1;
}

void yyerror(char *s)
{}

main()
{
	if(yyparse())
	{
		printf("Not accepted\n");
	}
} 
