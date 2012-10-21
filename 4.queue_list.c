//Queue Implementation using Linked list
#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
}*front,*rear;

void insert()
{
	struct node *np;
	np=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter the no. to be inserted : \n");
	scanf("%d",&np->data);
	np->next=NULL;
	if(front==NULL)
	{
		front=np;
		rear=np;
	}
	else
	{
		rear->next=np;
		rear=np;
	}	
}

void delete()
{
	int item;
	if(front==NULL)
		printf("\n Queue is empty\n");
	else
	{
		item=front->data;
		printf("\nThe item deleted is %d",item);
		front=front->next;
	}
}

void display()
{
	struct node *temp;
	temp=front;
	if(front==NULL)
		printf("\nQueue empty\n");
	else
	{
		printf("The queue contains : ");
		while(temp!=NULL)
		{
			printf("\t%d",temp->data);
			temp=temp->next;
		}
	}
}

void main()
{
	int c,n;
	do
	{
		printf("\nEnter your choice\n1.Enqueue\n2.Dequeue\n3.Display\n4.exit\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1 : insert();
				 break;
			case 2 : delete();
				 break;
			case 3 : display();
				 break;
			case 4 : exit(0);

			default : printf("Invalid Entry");
		}
	}
	while(1);
}         //End of Program
/*
  OUTPUT
---------------
Enter your choice
1.Enqueue
2.Dequeue
3.Display
4.exit
1

Enter the no. to be inserted : 
12

Enter your choice
1.Enqueue
2.Dequeue
3.Display
4.exit
1

Enter the no. to be inserted : 
36

Enter your choice
1.Enqueue
2.Dequeue
3.Display
4.exit
3
The queue contains : 	12	36
Enter your choice
1.Enqueue
2.Dequeue
3.Display
4.exit
2

The item deleted is 12
Enter your choice
1.Enqueue
2.Dequeue
3.Display
4.exit
3
The queue contains : 	36
Enter your choice
1.Enqueue
2.Dequeue
3.Display
4.exit
4

*/
