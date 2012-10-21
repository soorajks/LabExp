//Queue implementation using Arrays
#include<stdio.h>
int q[100],s,rear=0,front=0;


void insert()
{
	if(rear==s)
		printf("\nQueue full\n");
	else
	{
		printf("\n Enter the elements to be inserted : \n");
		scanf("%d",&q[rear]);
		rear=rear+1;
	}
}


void del()
{
if(front==rear)
printf("\n Empty queue\n");
else
{
q[front]=q[front+1];
rear=rear-1;
}
}


void display()
{
	int i;
	printf("\n The queue is : \n");
	for(i=front;i<rear;i++)
		printf("%d\t",q[i]);
}

void main()
{
	int c,n;
	printf("Enter the size of queue : \n");
	scanf("%d",&s);
	do
	{
		printf("\nEnter your choice\n1.Enqueue\n2.Dequeue\n3.Display\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1 : insert();
				 break;
			case 2 : del();
				 break;
			case 3 : display();
				 break;
			default : printf("Invalid entry");
		}
		printf("\nDo you wish to continue/exit 1/0 \n");
		scanf("%d",&n);
	}
	while(n);
}
//End of Program






/*

   OUTPUT
---------------
Enter the size of queue : 
2

Enter your choice
1.Enqueue
2.Dequeue
3.Display
1

 Enter the elements to be inserted : 
98

Do you wish to continue/exit 1/0 
1

Enter your choice
1.Enqueue
2.Dequeue
3.Display
1

 Enter the elements to be inserted : 
65

Do you wish to continue/exit 1/0 
1

Enter your choice
1.Enqueue
2.Dequeue
3.Display
3

 The queue is : 
98	65	
Do you wish to continue/exit 1/0 
1

Enter your choice
1.Enqueue
2.Dequeue
3.Display
2

Do you wish to continue/exit 1/0 
1

Enter your choice
1.Enqueue
2.Dequeue
3.Display
3

 The queue is : 
65	
Do you wish to continue/exit 1/0 
0

*/
