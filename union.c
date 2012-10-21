# include<stdio.h>
# include<malloc.h>

struct node
{	int element,count,parent;
	char setname[10];
}*ptr[50];

int root[2],k=-1;

void readset()
{	int n,i;
	struct node *temp;
	int temparray[20];
	temp=(struct node *)malloc(sizeof(struct node));
	temp->parent=-1;
	
	printf("\nEnter the set name:");
	scanf("%s",temp->setname);
	
	printf("\nEnter the no. of elements in the set:");
	scanf("%d",&n);

	temp->count=n;
	printf("\nEnter the root element:");
	scanf("%d",&temp->element);

	root[++k]=temp->element;
	ptr[temp->element]=temp;

	printf("\nEnter the set elements:");
	for(i=0;i<n-1;i++)
		scanf("%d",&temparray[i]);

	for(i=0;i<n-1;i++)
	{	temp=(struct node *)malloc(sizeof(struct node));
		temp->count=-1;
		temp->element=temparray[i];
		printf("\nEnter the parent of element %d:",temparray[i]);
		scanf("%d",&temp->parent);
		ptr[temp->element]=temp;
	}
}

void Union()
{	struct node *t1,*t2;
	t1=ptr[root[0]];
	t2=ptr[root[1]];
	if(t1->count < t2->count)
	{	t1->parent=t2->element;
		t2->count+=t1->count;
	}
	else
	{	t2->parent=t1->element;
		t1->count+=t2->count;
	}
}

void display()
{	int i;
	for(i=0;i<50;i++)
	{	if(ptr[i]!=NULL)
			printf("\nElement:%d\tParent:%d",ptr[i]->element,ptr[i]->parent);
	}
}

void find(int x)
{	struct node *temp;
	int root,par;
	temp=ptr[x];
	while(temp->parent!=-1)
		temp=ptr[temp->parent];
	root=temp->element;
	temp=ptr[x];
	while(temp->parent!=-1)
	{	par=temp->parent;
		if(temp->parent!=root)
			temp->parent=root;
		temp=ptr[par];
	}
	printf("\nThe element %d belongs to the set %s",x,temp->setname);
	printf("\nAfter path compression:");
	display();
}

void main()
{	int ch,x;
	for(x=0;x<50;x++)
		ptr[x]=NULL;
	do
	{	printf("\nMENU\n\t1.Create sets\n\t2.Find\n\t3.Union\n\t4.Exit\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{	case 1:printf("\nEnter the details of first set:\n");
				readset();
				printf("\nEnter the details of second set:\n");
				readset();
				break;
			case 2:printf("\nEnter the element to be searched for:");
				scanf("%d",&x);
				find(x);
				break;
			case 3:Union();
				printf("\nAfter Union\n");
				display();
				break;
			case 4:break;
		}
	}while(ch!=4);
}

/* 
	OUTPUT
---------------------

MENU
	1.Create sets
	2.Find
	3.Union
	4.Exit
Enter your choice:1

Enter the details of first set:

Enter the set name:a

Enter the no. of elements in the set:3

Enter the root element:1

Enter the set elements:2
3

Enter the parent of element 2:1

Enter the parent of element 3:1

Enter the details of second set:

Enter the set name:b

Enter the no. of elements in the set:3

Enter the root element:10

Enter the set elements:20
30

Enter the parent of element 20:10

Enter the parent of element 30:20

MENU
	1.Create sets
	2.Find
	3.Union
	4.Exit
Enter your choice:2

Enter the element to be searched for:10

The element 10 belongs to the set b
After path compression:
Element:1	Parent:-1
Element:2	Parent:1
Element:3	Parent:1
Element:10	Parent:-1
Element:20	Parent:10
Element:30	Parent:20
MENU
	1.Create sets
	2.Find
	3.Union
4.Exit
Enter your choice:3

After Union

Element:1	Parent:-1
Element:2	Parent:1
Element:3	Parent:1
Element:10	Parent:1
Element:20	Parent:10
Element:30	Parent:20
MENU
	1.Create sets
	2.Find
	3.Union
4.Exit
Enter your choice:4

*/



