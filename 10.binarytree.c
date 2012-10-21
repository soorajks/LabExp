//Binary Search Tree
#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
}*root;
//Searching
find(int item,struct node **par,struct node **loc)
{
	struct node *ptr,*ptrsave;
	if(root==NULL)
	{
		*loc=NULL;
		*par=NULL;
		return;
	}
	if(item==root->data) //root contains item
	{
		*loc=root;
		*par=NULL;
		return;
	}
	if(item<root->data)
		ptr=root->lchild;
	else
		ptr=root->rchild;
	ptrsave = root;
	while(ptr!=NULL)
	{
		if(item==ptr->data)
		{
			*loc = ptr;
			*par = ptrsave;
			return;
		}
		ptrsave = ptr;
		if(item<ptr->data)
			ptr=ptr->lchild;
		else
			ptr=ptr->rchild;
			
	}
	*loc = NULL;
	*par = ptrsave;
}
//Insertion
void insert(int item)
{
	int search;
	struct node *temp,*parent,*location;
	find(item,&parent,&location);
	if(location!=NULL)
	{
		printf("\nItem already present!!!\n");
		return;
	}
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->lchild=NULL;
	temp->rchild=NULL;
	if(parent==NULL)
		root=temp;
	else
	{
		if(item<parent->data)
			parent->lchild=temp;
		else
			parent->rchild=temp;
	}
	printf("\nItem inserted\n");
}
//Deletion
void del(int item)
{
	struct node *parent,*location;
	if(root==NULL)
	{
		printf("Tree empty!!!\n");
		return;
	}
	find(item,&parent,&location);
	if(location==NULL)
	{
		printf("\nItem not present!!!\n");
		return;
	}
	if((location->lchild==NULL)&&(location->rchild==NULL))
		case_a(parent,location);
	if((location->lchild!=NULL)&&(location->rchild==NULL))
		case_b(parent,location);
	if((location->lchild==NULL)&&(location->rchild!=NULL))
		case_b(parent,location);
	if((location->lchild!=NULL)&&(location->rchild!=NULL))
		case_c(parent,location);
	free(location);
}
/*case A of deletion
if node to be deleted is a leaf*/
case_a(struct node *par,struct node *loc)
{
	if(par==NULL) //only one node present
		root=NULL;
	else
	{
		if(loc==par->lchild)
			par->lchild=NULL;
		else
			par->rchild=NULL;
	}
}
/*case B of deletion
if node contains only one child*/
case_b(struct node *par,struct node *loc)
{
	struct node *child;
	if(loc->lchild!=NULL)
		child=loc->lchild;
	else
		child=loc->rchild;
	if(par==NULL)
		root=child;
	else
	{
		if(loc==par->lchild)
			par->lchild=child;
		else
			par->rchild=child;
	}
}
/*case C of deletion
if node contains both children*/
case_c(struct node *par,struct node *loc)
{
	struct node *parsuc,*suc;
	parsuc=loc;
	suc=loc->rchild;
	while(suc->lchild!=NULL)
	{
		parsuc=suc;
		suc=suc->lchild;
	}
	if((suc->lchild==NULL)&&(suc->rchild==NULL))
		case_a(parsuc,suc);
	else
		case_b(parsuc,suc);
	if(par==NULL)
		root=suc;
	else
	{
		if(loc==par->lchild)
			par->lchild=suc;
		else
			par->rchild=suc;
	}
	suc->lchild=loc->lchild;
	suc->rchild=loc->rchild;
}
//Inorder traversal
inorder(struct node *ptr)
{
	if(root==NULL)
	{
		printf("\nTree Empty!!!\n");
		return;
	}
	if(ptr!=NULL)
	{
		inorder(ptr->lchild);
		printf("%d ",ptr->data);
		inorder(ptr->rchild);
	}
}
//Preorder traversal
preorder(struct node *ptr)
{
	if(root==NULL)
	{
		printf("\nTree Empty!!!\n");
		return;
	}
	if(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
}
//Postorder traversal
postorder(struct node *ptr)
{
	if(root==NULL)
        {
                printf("\nTree Empty!!!\n");
                return;
        }
	if(ptr!=NULL)
        {       
                postorder(ptr->lchild);
                postorder(ptr->rchild);
                printf("%d ",ptr->data);
        }
}
main()
{
	int n,x;
	struct node *location,*parent;
	do
	{
		printf("\n1.Insertion\n2.Deletion\n3.Search\n4.Inorder Traversal\n5.Preorder raversal\n6.Postorder Treaversal\n7.Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: printf("Enter element to be inserted : "); 
				scanf("%d",&x);
				insert(x);
				break;
			case 2: printf("Enter element to be deleted : ");
				scanf("%d",&x);
				del(x);
				break;
			case 3: printf("Enter element to be searched : ");
				scanf("%d",&x);
				find(x,&parent,&location);
				if(location)	
					printf("\nSearch successfull!!!\n");
				else
					printf("\nItem not found!!!\n");
				break;
			case 4: inorder(root);
				break;
			case 5: preorder(root);
				break;
			case 6: postorder(root);
				break;
			case 7: exit(0);
			default : printf("\nWrong Entry!!!\n");
		}
	}while(n!=7);
}  //End of Program

/*
   OUTPUT
----------------------
1.Insertion
2.Deletion
3.Search
4.Inorder Traversal
5.Preorder raversal
6.Postorder Treaversal
7.Exit
Enter your choice : 3
Enter element to be searched : 5

Item not found!!!

1.Insertion
2.Deletion
3.Search
4.Inorder Traversal
5.Preorder raversal
6.Postorder Treaversal
7.Exit
Enter your choice : 1
Enter element to be inserted : 78

Item inserted

1.Insertion
2.Deletion
3.Search
4.Inorder Traversal
5.Preorder raversal
6.Postorder Treaversal
7.Exit
Enter your choice : 1
Enter element to be inserted : 54

Item inserted

1.Insertion
2.Deletion
3.Search
4.Inorder Traversal
5.Preorder raversal
6.Postorder Treaversal
7.Exit
Enter your choice : 1
Enter element to be inserted : 98

Item inserted

1.Insertion
2.Deletion
3.Search
4.Inorder Traversal
5.Preorder raversal
6.Postorder Treaversal
7.Exit
Enter your choice : 4
54 78 98 
1.Insertion
2.Deletion
3.Search
4.Inorder Traversal
5.Preorder raversal
6.Postorder Treaversal
7.Exit
Enter your choice : 2
Enter element to be deleted : 78

1.Insertion
2.Deletion
3.Search
4.Inorder Traversal
5.Preorder raversal
6.Postorder Treaversal
7.Exit
Enter your choice : 5
98 54 
1.Insertion
2.Deletion
3.Search
4.Inorder Traversal
5.Preorder raversal
6.Postorder Treaversal
7.Exit
Enter your choice : 7
*/
