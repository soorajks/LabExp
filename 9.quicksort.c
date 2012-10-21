//Recursive Implementation of Quick Sort
#include<stdio.h>
 
void swap (int a[], int left, int right)
{
	 int temp;
	 temp=a[left];
	 a[left]=a[right];
	 a[right]=temp; 
}//end swap
 
void quicksort( int a[], int low, int high )
{
	 int pivot;
 // Termination condition! 
	 if ( high > low )
	 {
		  pivot = partition( a, low, high );
		  quicksort( a, low, pivot-1 );
		  quicksort( a, pivot+1, high );
	 }
} //end quicksort
 
int partition( int a[], int low, int high )
{
	 int left, right;
	 int pivot_item;
	 int pivot = left = low; 
	 pivot_item = a[low]; 
	 right = high;
	 while ( left < right ) 
	 {
  // Move left while item < pivot 
		  while( a[left] <= pivot_item ) 
			   left++;
  // Move right while item > pivot 
		  while( a[right] > pivot_item ) 
			   right--;
		  if ( left < right ) 
			   swap(a,left,right);
	 }
 // right is final position for the pivot 
	 a[low] = a[right];
	 a[right] = pivot_item;
	 return right;
}//end partition
 
// void quicksort(int a[], int, int);
void printarray(int a[], int);
 
int main()
{
	 int a[50], i, n;
	 printf("\nEnter no. of elements: "); 
	 scanf("%d", &n);
	 printf("\nEnter the elements: \n");
	 for (i=0; i<n; i++)
		  scanf ("%d", &a[i]);
	 printf("\nUnsorted elements: \n");
	 printarray(a,n);
	 quicksort(a,0,n-1);
	 printf("\nSorted elements: \n");
	 printarray(a,n);
 
}//end main
 
 
void printarray(int a[], int n)
{
	 int i;
	 for (i=0; i<n; i++)
		  printf(" %d ", a[i]);
	 printf("\n");
}//end printarray

/*
  OUTPUT
----------------
Enter no. of elements: 6

Enter the elements: 
43
12
98
56
23
39

Unsorted elements: 
 43  12  98  56  23  39 

Sorted elements: 
 12  23  39  43  56  98 

*/
