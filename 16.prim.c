/* C program to implement Prims algorithm*/
 #include<stdio.h>
 int a,b,u,v,n,i,j,ne=1;
 int visited[10]={0},min,mincost=0,cost[10][10];
 void main()
 {
   printf("\n Enter the number of nodes:");
   scanf("%d",&n);
   printf("\n Enter the adjacency matrix (cost):\n");
   for(i=1;i<=n;i++)
    {	for(j=1;j<=n;j++)
  	   {		
   	     scanf("%d",&cost[i][j]);
   	     if(cost[i][j]==0)
   	     cost[i][j]=999;
  	   }
    }
   visited[1]=1;
   printf("\n");
   while(ne<n)
    {
      for(i=1,min=999;i<=n;i++)
 	 {   for(j=1;j<=n;j++)
 		 {  if(cost[i][j]<min)
 		       if(visited[i]!=0)
 		         {
 			     min=cost[i][j];
 			     a=u=i;
 			     b=v=j;
         		  }
	         }
	 }
       if(visited[u]==0 || visited[v]==0)
 	 {
 	    printf("\n Edge %d:(%d %d) cost:%d",ne++,a,b,min);
 	    mincost+=min;
 	    visited[b]=1;
 	 }
       cost[a][b]=cost[b][a]=999;
     }
 printf("\n Minimun cost=%d",mincost);
} //End of program
/*
 Output
------------
 Enter the number of nodes:6
 Enter the adjacency matrix (cost):
 0 6 1 5 999 999
 6 0 5 999 3 999
 1 5 0 5 6 4
 5 999 5 0 999 2
 999 3 6 999 0 6 
 999 999 4 2 6 0

 Edge 1:(1 3) cost:1
 Edge 2:(3 6) cost:4
 Edge 3:(6 4) cost:2
 Edge 4:(3 2) cost:5
 Edge 5:(2 5) cost:3
 Minimun cost=15
*/
