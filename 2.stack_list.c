//Stack implementation using Linked list
#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
}
*top;
void insert()
{
	struct node *np;
	np=(struct node *)malloc(sizeof(struct node));
	printf("\n Enter the no. to be inserted : \n");
	scanf("%d",&np->data);
	np->next = NULL;
	if(top==NULL)
		top=np;	
	else
	{
		np->next = top;
		top=np;
	}	
}


void pop()
{
	struct node *np;
	if(top==NULL)
		printf("\n Empty stack");
	else
		top = top->next;
}


void display()
{
	struct node *np;
	np=top;
	if(np==NULL)
		printf("\nStack empty");
	else
	{
		printf("\nStack contains : \n");
		while(np != NULL)
		{
			printf("\t%d",np->data);
			np=np->next;
		}
		printf("\n");
	}
}


void main()
{
	int c,n;
	do
	{
		printf("\nEnter the choice \n1.Push\n2.Pop\n3.Display\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1 : insert();
				 break;
			case 2 : pop();
				 break;
			case 3 : display();
				 break;
			default : printf("\n Invalid entry\n");
		}
		printf("Do you want to continue/exit 1/0 ?\n");
		scanf("%d",&c);
	}
	while(c);
}
//End of Program

/*

  OUTPUT
---------------
Enter the choice 
1.Push
2.Pop
3.Display
1    

 Enter the no. to be inserted : 
65
Do you want to continue/exit 1/0 ?
1

Enter the choice 
1.Push
2.Pop
3.Display
1

 Enter the no. to be inserted : 
98
Do you want to continue/exit 1/0 ?
1

Enter the choice 
1.Push
2.Pop
3.Display
3

Stack contains : 
	98	65
Do you want to continue/exit 1/0 ?
1

Enter the choice 
1.Push
2.Pop
3.Display
2
Do you want to continue/exit 1/0 ?
1

Enter the choice 
1.Push
2.Pop
3.Display
3

Stack contains : 
	65
Do you want to continue/exit 1/0 ?
0		*/

