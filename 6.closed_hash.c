#include<stdio.h>
#include<malloc.h>
struct hashtable
{
int *arr,len;
int *status;

}
;

void init(struct hashtable* chash,int len)	//funct for initialisin hash table
{
	int i;
	chash->len=len;
	chash->arr=(int *)malloc(sizeof(int)*len);
	chash->status=(int *)malloc(sizeof(int)*len);
	for(i=0;i<len;i++) 
	{
	        chash->status[i] = 0;
	}
}

int insert(struct hashtable *chash, int data)		//insertig function
 {
        int pos,hash;        
        int i=0;
        pos=data%chash->len;	//hash fuction
        while(i < chash->len) 
		{                //exiting case
                hash = (pos+i)%chash->len;
                if(chash->status[hash]!=1) 	
			{ 				// found an postion to insert
                              chash->arr[hash] = data;  //inserts the data
                              chash->status[hash]=1;   // changes the status to inserted
                              return 1;  
                	}
			 else 
			{
                        i++;
                }
        }
	printf("\nThe table is full\n Not inserted");
	return 1;

} 
               
int search(struct hashtable *chash,int data)
{
         int pos=0,hash,i;
         while(i<chash->len)
         {      hash=(pos+i)%chash->len;		//hash function
                if(chash->arr[hash]==data)
                return hash;             //found
                else
                        {
                                i++;
                        }
                
           }
           return -1;
 }              
 
 int delete(struct hashtable *chash,int data,int r)
 {
 int p=r;			//return value from search is in r
 if(p==-1) 
    printf("\n There is no such element");
 else
        {
        printf("The deleted element is :%d",data);
        chash->status[p]=2;		//changig status after deletion
        chash->arr[p]=-1;		//changing value to a nagative number
        }
return 1;
        
  }
        
 
 int display(struct hashtable *chash)		//function for displayin hash table
 {
        int i=0;
        printf("The elements are:\n");
        while(i<chash->len)
                {
                printf("\t%d\n",chash->arr[i]);
                i++;
                }
         return 1;
 
 }                                   


main()
{
	int n,q,data,r;
	printf("Enter the size of hash table");
	scanf("%d",&n);
	struct hashtable chash;
	init(&chash,n);
	while(1)
		{
			printf("\n\n1.insert\n2.search\n3.display\n4.delete\n5.exit\n");
			scanf("%d",&q);
			switch(q)
			{
        			case 1:printf("\nEnter the elements to be inseted\t");
                			scanf("%d",&data);
                			insert(&chash,data);
                			break;
        			case 2:printf("\nEnter the element to be searched\t");
               				 scanf("%d",&data);
                			r=search(&chash,data);
                			if(r!=-1)
                				printf("\nFound");
					else
						printf("\nNot found");
                			break;
                
        
        			case 3:display(&chash);
          			       break;
        			case 4:printf("\nenter the data to be deleted\t");
                			scanf("%d",&data);
					r=search(&chash,data);
                			delete(&chash,data,r);
                			break;
        			case 5:exit(0);
                
       				 default:printf("\nInvalid entry");                
			}
		}		
}


