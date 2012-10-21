#include<stdio.h>
#include<malloc.h>

struct node
{   int priority;
    int info;
    struct node *next;
}*start, *q, *temp, *new;
 
void insert()
{   int item, itprio;
    new = (struct node *)malloc( sizeof(struct node));
    printf("\nEnter the element to be inserted:");
    scanf("%d",&item );
    printf("\nEnter its priority:");
    scanf("%d",&itprio);
    new->info=item;
    new->priority =itprio;
 
    if(start==NULL||itprio<start->priority)
    {	new->next = start;
        start = new;
    }
    else
    {     q=start;
          while(q->next!=NULL && q->next->priority<=itprio)
                q = q->next;
          new->next = q->next;
	  q->next = new;
    }
}
 
void del()
{
    if (start==NULL)
    {    printf("\nQueue Underflow\n");
 
    }
    else
    {    new = start;
         printf("\nDeleted item is:%d\n",new->info);
         start=start->next;
         free(start);
    }
}

 
void display()
{   temp=start;
 
    if (start==NULL )
        printf("\nQueue is empty\n");
    else
    {   printf("\nQueue is:\n" );
        while(temp!=NULL)
        {     printf("\t%d[priority=%d]",temp->info,temp->priority );
              temp=temp->next;
        }
    }
}

int main()
{   int ch;
 
    do
    {    printf("\nMENU\n\t1.Insert\n\t2.Delete\n\t3.Display\n\t4.Exit\nEnter your choice:");
         scanf("%d",&ch);
         switch (ch)
         {    case 1:insert();
                     break;
              case 2:del();
                     break;
              case 3:display();
                     break;
              case 4:break;
         }
    }while(ch<4);
}

/*

	OUTPUT
-----------------------

MENU
	1.Insert
	2.Delete
	3.Display
	4.Exit
Enter your choice:1

Enter the element to be inserted:10

Enter its priority:2

MENU
	1.Insert
	2.Delete
	3.Display
	4.Exit
Enter your choice:1

Enter the element to be inserted:20

Enter its priority:5

MENU
	1.Insert
	2.Delete
	3.Display
	4.Exit
Enter your choice:3

Queue is:
	10[priority=2]	20[priority=5]
MENU
	1.Insert
	2.Delete
	3.Display
	4.Exit
Enter your choice:1

Enter the element to be inserted:5

Enter its priority:1

MENU
	1.Insert
	2.Delete
	3.Display
	4.Exit
Enter your choice:3

Queue is:
	5[priority=1]	10[priority=2]	20[priority=5]
MENU
	1.Insert
	2.Delete
	3.Display
	4.Exit
Enter your choice:2

Deleted item is:5

MENU
	1.Insert
	2.Delete
	3.Display
	4.Exit
Enter your choice:4

*/
 

