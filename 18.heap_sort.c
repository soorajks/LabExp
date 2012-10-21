/* C program to implement Heap sort*/
#include<stdio.h>
int a[20];
void deletemax(int a[],int root,int bottom)
{
   int maxchild,temp;
   while((root*2<=bottom))
    {
	if(root*2==bottom)
	   maxchild=root*2;
	else if(a[root*2]>a[root*2+1])
	   maxchild=root*2;
	else
	   maxchild=root*2+1;
	if(a[root]<a[maxchild])
	   {
	     temp=a[root];
	     a[root]=a[maxchild];
             a[maxchild]=temp;
             root=maxchild;
	   }
	else
	   break;
    }
}
void heapsort(int a[],int n)
{
  int i,temp;
  for(i=(n/2)-1;i>=0;i--)
    deletemax(a,i,n);
  for(i=n-1;i>=1;i--)
    {
      temp=a[0];
      a[0]=a[i];
      a[i]=temp;
      deletemax(a,0,i-1);
    }
}
void main()
{
  int i,n;
  printf("Enter the array size:");
  scanf("%d",&n);
  printf("Enter the elements of array:\n");
  for(i=0;i<n;i++)
     scanf("%d",&a[i]);
  heapsort(a,n);
  printf("Sorted elements using heap sort:\n");
  for(i=0;i<n;i++)
      printf("%d \t",a[i]);
  printf("\n");

}// End of program
/*
 Output
------------
Enter the array size:6
Enter the elements of array:
6 5 7 4 8 3   
Sorted elements using heap sort:
3 	4 	5 	6 	7 	8 	
*/
