/* C program to implement Kruskal Algorithm*/
#include<stdio.h>
#include<stdlib.h>
int i,j,k,a,b,u,v,n,ne=1;
int min,mincost=0,cost[9][9],parent[9];
int find(int i)
{  while(parent[i])
   i=parent[i];
   return i;
}
int uni(int i,int j)
{  if(i!=j)
	{  parent[j]=i;
	    return 1;
	}	
	return 0;
}
void main()
{
    printf("\n\n\tImplementation of Kruskal's algorithm\n\n");
    printf("\nEnter the no. of vertices\n");
    scanf("%d",&n);
    printf("\nEnter the cost adjacency matrix\n");
    for(i=1;i<=n;i++)
      {
	for(j=1;j<=n;j++)
	  {
	     scanf("%d",&cost[i][j]);
	     if(cost[i][j]==0)
	        cost[i][j]=999;
	  }
      }
    printf("\nThe edges of Minimum Cost Spanning Tree are\n\n");
    while(ne<n)
      {
	 for(i=1,min=999;i<=n;i++)
	 {   for(j=1;j<=n;j++)
		{  if(cost[i][j]<min)
		     {
		       min=cost[i][j];
		       a=u=i;
		       b=v=j;
		     }
		 }
	  }
       u=find(u);
       v=find(v);
       if(uni(u,v))
        {
   	  printf("\n%d edge (%d,%d) =%d\n",ne++,a,b,min);
     	  mincost +=min;
        }
       cost[a][b]=cost[b][a]=999;
     }
    printf("\n\tMinimum cost = %d\n",mincost);
} // End of program
/*	
Implementation of Kruskal's algorithm
Enter the no. of vertices
6
Enter the cost adjacency matrix
0 6 1 5 999 999
6 0 5 999 3 999
1 5 0 5 6 4
5 999 5 0 999 2  
999 3 6 999 0 6
999 999 4 2 6 0
The edges of Minimum Cost Spanning Tree are
1 edge (1,3) =1
2 edge (4,6) =2
3 edge (2,5) =3
4 edge (3,6) =4
5 edge (2,3) =5
Minimum cost = 15
*/
