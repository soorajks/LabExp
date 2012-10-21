//Stack implementation using Arrays
#include<stdio.h>
int arr[50],top=0,s;
void push();
void pop();
void display();
main()
{
	int c,t;
	printf("\nEnter the size of stack : ");
	scanf("%d",&s);
	do
	{
		printf("\n Menu \n1.Insert\n2.Delete\n3.Display\n");
		scanf("%d",&t);
		switch(t)
		{
			case 1 : push();
				 break;
			case 2 : pop();
				 break;
			case 3 : display();
				 break;
			default : printf("Wrong entry !!\n");
		}
		printf("Do you want to continue/exit 1/0 ?\n");
		scanf("%d",&c);
	}
	while(c);
}


void push()
{
	if(top==s)
		printf("\nStack overflow\n");
	else
	{
		printf("Enter the element : ");
		scanf("%d",&arr[top]);
		top=top+1;
	}
}


void pop()
{
	if(top==0)
		printf("Stack is underflow");
	else
		top=top-1;
}


void display()
{
	int i;
	if(top==0)
		printf("Stack empty");
	else
	{
		printf("The stack is \t");
		for(i=0;i<top;i++)
			printf("%d\t",arr[i]);
		printf("\n");
	}
}   //End of Program


/*

  OUTPUT
---------------
Enter the size of stack : 2

 Menu 
1.Insert
2.Delete
3.Display
1
Enter the element : 25
Do you want to continue/exit 1/0 ?
1

 Menu 
1.Insert
2.Delete
3.Display
1
Enter the element : 32
Do you want to continue/exit 1/0 ?
1

 Menu 
1.Insert
2.Delete
3.Display
3
The stack is 	25	32	
Do you want to continue/exit 1/0 ?
1

 Menu 
1.Insert
2.Delete
3.Display
1

Stack overflow
Do you want to continue/exit 1/0 ?
0

*/
