#include<stdio.h>
int bin(int a[],int,int,int);
main()
{
	int a[50],i,j,n,high,low;
	printf("\nEnter the no of elements\t");
	scanf("%d",&n);
	printf("\nEnter the elements\t");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{for(j=i;j<n;j++)
		if(a[j]>a[j+1])
		{
		int t=a[j];
		a[j]=a[j+1];
		a[j+1]=t;
		}
	}
	low=0;high=n;
	printf("\nEnter the no to be searched\t");
	scanf("%d",&j);
	bin(a,high,low,j);

}
int bin(int a[],int high,int low,int j)
{
	int mid;
	mid=(high+low)/2;
	if(a[mid]==j)
	{
		printf("found\n");
		return j;
	}
	if(high==low)
	{
		printf("NOt found\n");
		return(1);
	}
	if(j<a[mid])
	{
		high=mid-1;
	}
	if(j>a[mid])
	{
		low=mid+1;
	}
	bin(a,high,low,j);
}
