/*C program to implement Breadth First Search */
#include<stdio.h>
int adj[10][10],visit[10],n,q[10],r=-1,f=0;
void bfs(int a)
{ int i;	
  for(i=0;i<n;i++)
    {	if(adj[a][i]==1 && visit[i]==0)
	   {	visit[i]=1;
		r++; 
		q[r]=i;
	    	printf("->%d",i);
	   }
    }
  while(f<=r)
    {	bfs(q[f++]);
    }	
}
void init_visit()
{   int i;
     for(i=0;i<n;i++)
       {  q[i]=0;
	   visit[i]=0;
       }
}
void main()
{   int i,j,start_node;
    system("clear");
    init_visit();
    printf("\nEnter the no. of vertices:");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix:\n");
    for(i=0;i<n;i++)
      {	for(j=0;j<n;j++)
       	  { scanf("%d",&adj[i][j]);
	  }
       }
   printf("\nThe adjacency matrix is:\n");
	for(i=0;i<n;i++)
	{   for(j=0;j<n;j++)
		{  printf("\t%d",adj[i][j]);
		}
		printf("\n");
	}
	
   printf("\nEnter the starting node:");
   scanf("%d",&start_node);
   printf("\nThe BFS Yields....\n");
   visit[start_node]=1;
   printf("\n%d",start_node);
   bfs(start_node);
   printf("\n");
}

/*
	OUTPUT
-----------------------
Enter the no. of vertices:4
Enter the adjacency matrix:
0 1 0 1
0 0 1 0
0 0 0 0
0 0 0 0
The adjacency matrix is:
	0	1	0	1
	0	0	1	0
	0	0	0	0
	0	0	0	0
Enter the starting node:0
The BFS Yields....
0->1->3->2
*/
