//Recursive implementation of Merge Sort
#include <stdio.h>
#include <stdlib.h>

void mergesort(int a[], int low, int high);

int main(void) {
 	int array[100],n;
 	int i = 0;

 /* reading the elements form the users*/
  	printf("\nEnter the number of elements to be sorted:");
 	scanf("%d",&n);
	printf("Enter the elements to be sorted:\n");
 	  for(i = 0; i < n; i++ ){
	 	  scanf("%d",&array[i]);
   	}

 /* array before mergesort */
 	printf("Before sorting:");
 	for(i = 0; i < n; i++)
 		 printf(" %d", array[i]);
	
	 printf("\n");

	 mergesort(array, 0, n - 1);

 /* array after mergesort */
	 printf("After Mergesort:");
	 for(i = 0; i < n; i++)
		  printf(" %d", array[i]);

	 printf("\n");
	 return 0;
}
/* Method to implement Merge Sort*/
void mergesort(int a[], int low, int high) {
	 int i = 0;
	 int length = high - low + 1;
	 int pivot  = 0;
	 int merge1 = 0;
 	 int merge2 = 0;
 	 int working[length];
	
	 if(low == high)
		  return;

 	pivot  = (low + high) / 2;

 	mergesort(a, low, pivot);
 	mergesort(a, pivot + 1, high);
 
	 for(i = 0; i < length; i++)
		  working[i] = a[low + i];

 	merge1 = 0;
 	merge2 = pivot - low + 1;

 	for(i = 0; i < length; i++) 
	{
 		 if(merge2 <= high - low)
   		 	if(merge1 <= pivot - low)
   		 		if(working[merge1] > working[merge2])
     					a[i + low] = working[merge2++];
    				else
     					a[i + low] = working[merge1++];
   			else
   				 a[i + low] = working[merge2++];
  		else
  			 a[i + low] = working[merge1++];
 	}
}  //End of Program

/*
   OUTPUT
------------------
Enter the number of elements to be sorted:6
Enter the elements to be sorted:
23
45
11
87
65
32
Before sorting: 23 45 11 87 65 32
After Mergesort: 11 23 32 45 65 87
*/
