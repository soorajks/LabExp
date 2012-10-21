//Infix Expression Evaluation
#include<stdio.h>
#include <ctype.h>
char s[50];
int top = -1; /* Global declarations */

push(char elem)
 { /* Function for postfix PUSH  operation */
	 s[++top] = elem;
 }

char pop() 
 { /* Function for postfix POP operation */
 	return (s[top--]);
 }





int a[50];
int top1=-1;       /* Global declarations */
 
pushp(int elem)
{                       /* Function for eval PUSH operation */
a[++top1]=elem;
}
 
int popp()
{                      /* Function for eval POP operation */
 return(a[top1--]);
}


int pr(char elem)
 { /* Function for precedence */
	 switch (elem) 
	 {
		 case '#':
		  return 0;
		 case '(':
		  return 1;
		 case '+':
		 case '-':
		  return 2;
		 case '*':
		 case '/':
		  return 3;
	 }
 }

main()
 { /* Main Program */
	 char infx[50], pofx[50], ch, elem;
	 int i = 0, k = 0;
	 
	 printf("\n\nRead the Infix Expression ? ");
	 scanf("%s", infx);
	 push('#');
	 while ((ch = infx[i++]) != '\0') 
	{
		  if (ch == '(')
			   push(ch);
		  else if (isalnum(ch))
			   pofx[k++] = ch;
		  else if (ch == ')') 
			{
			   while (s[top] != '(')
				    pofx[k++] = pop();
			   elem = pop(); /* Remove ( */
			}
		 else 
			{ /* Operator */
  			   while (pr(s[top]) >= pr(ch))
				    pofx[k++] = pop();
			   push(ch);
			}
 	}
	 while (s[top] != '#') /* Pop from stack till empty */
	 pofx[k++] = pop();
 	 pofx[k] = '\0'; /* Make pofx as valid string */
 	 printf("\n The Infix : %s \t Postfix : %s\n",infx,pofx);
char ca;	 
int op1,op2;i=0;
 	 while( (ca=pofx[i++]) != '\0')
	 {
		  if(isdigit(ca))
			 pushp(ca-'0'); /* Push the operand */
		  else
		  {        /* Operator,pop two  operands */
			   op2=popp();
			   op1=popp();
			   switch(ca)
			   {
				   case '+':pushp(op1+op2);break;
				   case '-':pushp(op1-op2);break;
				   case '*':pushp(op1*op2);break;
				   case '/':pushp(op1/op2);break;
			   }
		  }
	 }
	 
	 printf("\n Result after Evaluation: %d\n",a[top]);
}   //End of Program

/*
   OUTPUT
------------------
Read the Infix Expression ? 
((2+3)*(4+5))

 The Infix : ((2+3)*(4+5)) 	 Postfix : 23+45+*

 Result after Evaluation: 45

*/
