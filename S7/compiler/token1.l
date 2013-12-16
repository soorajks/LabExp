%{
#include "stdio.h"
%}
id [A-Za-z_][A-Za-z0-9]*
num [0-9]+
op [+\-*/<>:&|!=]|"=="|"<="|">="
keyword "if"|"else"|"while"|"do"|"while"|"continue"|"break"|"for"|"do"|"char"|"void"|"unsigned"|"int"|"float"|"double"|"long"|"return"
header {id}".h"
preproc "#include"|"#define"
punct "`"|"~"|"@"|"#"|"$"|"%"|"^"|"("|")"|"_"|"'"|"\""|";"|"?"|"."|","|"}"|"{"
string ["].*["]
%option noyywrap
%%
{string} {printf(" String:%s\n",yytext);}
{header} {printf(" header: %s\n",yytext);}
{preproc} {printf(" preproc: %s\n",yytext);}
{keyword} {printf(" keyword: %s\n",yytext);}
{id} {printf(" identifier:%s\n",yytext);}
{num} {printf(" NUmber:%s\n",yytext);}
{op} {printf(" Operator:%s\n",yytext);}
{punct} {printf(" Punctuation:%s\n",yytext);}

%%
main()
{
	yyin=fopen("sample.c","r");
	yylex();
	return 0;
}

