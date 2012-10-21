//Open Hashing
#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *next;
};
struct node *s[100],*temp;

void init(int n)
{
	int i;
	for(i=0;i<n;i++)
	s[i]=NULL;
}

void insert(int n)
{
	int no,pos;
	printf("\nEnter the element to be inserted  :");
	scanf("%d",&no);
	pos=no%n;
	if(s[pos]==NULL)
	{
		s[pos]=(struct node *)malloc(sizeof(struct node));
		s[pos]->data=no;
		s[pos]->next=NULL;
	}
	else
	{
		struct node *np;
		np=(struct node *)malloc(sizeof(struct node));
		temp=(struct node *)malloc(sizeof(struct node));
		temp=s[pos];
		while(temp->next!=NULL)
			temp=temp->next;
		np->next=NULL;
		np->data=no;
		temp->next=np;
	}
}
void print(int n)
{
int i;
for(i=0;i<n;i++)
	{	
		if(s[i]==NULL)
			{
				printf("empty\n");continue;
			}
		temp=s[i];
		while(temp->next!=NULL)
			{
				printf("%d\t",temp->data);
				temp=temp->next;
			}
		printf("%d\n",temp->data);
	}
}

int search(int n,int no)
{
	int pos;
	pos=no%n;
	temp=s[pos];
	if(s[pos]==NULL)
	{
		printf("\nElement not found");
		return 0;
	}
	
	while(temp!=NULL)
	{
		if(temp->data==no)
		{
			printf("\nelement found");
			return 1;
		}
		temp=temp->next;
	}
	printf("\nelement not found");
	return 0;
}

void delete(int n,int no)
{
	struct node *temp2;
	temp2=(struct node *)malloc(sizeof(struct node));
	int pos=no%n;
	temp=s[pos];
	if(s[pos]->data==no)
		{       if(temp->next==NULL)
			{	
				s[pos]=NULL;
				return;
			}
			s[pos]=temp->next;
			while(temp==NULL)
				temp=temp->next;
			
			
			return;
		}
	temp2=NULL;
	while(temp->next!=NULL)
		{
			if(temp->data==no)
			{
				temp2->next=temp->next;
				return;
			}
			temp2=temp;
			temp=temp->next;
		}
	temp2->next=NULL;		
}
void main()
{
	int n,c,no,r;
	printf("\nEnter the no of buckets  ");
	scanf("%d",&n);
	init(n);
	while(1)
	{
		printf("\nmenu\n1.insert\n2.print\n3.exit\n4.search\n5.del\t");
		scanf("%d",&c);	
		switch(c)
		{
			case 1:insert(n);
				break;
			case 2:print(n);
				break;
			case 3:exit(0);
			case 4:printf("\nEnter the no to be searched  ");
				scanf("%d",&no);
				search(n,no);
				break;
			case 5:printf("\nEnter the no to be deleted  ");
				scanf("%d",&no);
				r=search(n,no);
				if(r==1)
				{	
					delete(n,no);
					printf("\nDeleted");
				}
				break;
			default:printf("\ninvalid entry");
		}
	}
}
//End of program

/*
   OUTPUT  
-----------------
Enter the no of buckets  3

menu
1.insert
2.print
3.exit
4.search
5.del	1

Enter the element to be inserted  :87

menu
1.insert
2.print
3.exit
4.search
5.del	1

Enter the element to be inserted  :2

menu
1.insert
2.print
3.exit
4.search
5.del	1

Enter the element to be inserted  :12

menu
1.insert
2.print
3.exit
4.search
5.del	1

Enter the element to be inserted  :5

menu
1.insert
2.print
3.exit
4.search
5.del	1

Enter the element to be inserted  :4

menu
1.insert
2.print
3.exit
4.search
5.del	2
87	12
4
2	5

menu
1.insert
2.print
3.exit
4.search
5.del	5

Enter the no to be deleted  87

element found
Deleted
menu
1.insert
2.print
3.exit
4.search
5.del	2
12
4
2	5

menu
1.insert
2.print
3.exit
4.search
5.del	3
*/
