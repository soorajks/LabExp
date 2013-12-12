%{
#include<stdio.h>
%}
%token NUM
%left '+''-''*''/'
%right NEGATIVE
%%
S:E{printf("\n");}
E: E '+' E {printf("+");}
|E '*' E{printf("*");}
|E '-' E{printf("-");}
|E '/' E{printf("/");}
|'(' E ')'
|'-' E %prec NEGATIVE {printf("-");}
|NUM {printf("%d",yylval);};
%%
int main()
{
yyparse();

}
int yywrap()
{
return 1;
}
void yyerror(char *s)
{}

