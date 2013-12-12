%{
#include<stdio.h>
%}
%token NUM
%token ID
%token DATA
%%

S:ST {printf("\nInput Accepted\n");return 0;};
ST:ID'(' PARA ')' '\n' '{' BODY '}'
  |DATA' 'ID'(' PARA ')' '\n' '{' BODY '}' ;

PARA:DATA' 'ID
	|PARA','PARA
	;
	
        
BODY: BODY BODY
     |E ';' '\n'
     |DATA' 'ID';''\n'
     |'\n'
     ;
     
     
E:ID'='E
  |E'+'E     
  |E'-'E
  |E'*'E
  |E'/'E
  |E'+''+'
  |E'-''-'
  |ID
  |NUM
  |
  ;
  
A:NUM
 |ID
 ;
%%

int yyerror()
{	printf("\nThe string not accepted\n");
}

int main()
{
	printf("\nEnter the string:");
	yyparse();
}
