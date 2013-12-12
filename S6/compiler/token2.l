%{
#include "stdio.h"
int str=0;
int hdr=0,pre=0,no=0,key=0,idd=0,punt=0,opp=0;
%}
id [A-Za-z_][A-Za-z0-9]*
num [0-9]+
op [+\-*/<>:&|!=]|"=="|"<="|">="|"\%"
keyword "if"|"else"|"while"|"do"|"while"|"continue"|"break"|"for"|"do"|"char"|"void"|"unsigned"|"int"|"float"|"double"|"long"|"return"
header {id}".h"
preproc "#include"|"#define"
punct "`"|"~"|"@"|"#"|"$"|"^"|"("|")"|"'"|"\""|";"|"?"|"."|","|"}"|"{"
string ["].*["]
ws [ \t\n]
%option noyywrap
%%
{string} {str++;}
{header} {hdr++;}
{preproc} {pre++;}
{keyword} {key++;}
{id} {idd++;}
{num} {no++;}
{op} {opp++;}
{punct} {punt++;}
{ws} {}
%%
main()
{
	yyin=fopen("sample.c","r");
	yylex();
	printf(" String:%d\n",str);
	printf(" header: %d\n",hdr);
	printf(" preproc: %d\n",pre);
	printf(" keyword: %d\n",key);
	printf(" identifier:%d\n",idd);
	printf(" NUmber:%d\n",no);
	printf(" Operator:%d\n",opp);
	printf(" Punctuation:%d\n",punt);
	return 0;
}

