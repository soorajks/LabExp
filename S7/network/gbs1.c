#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<assert.h>
#define PORT 4000
main()
{
	char buff[100];
	int min=0,max, cur=0,ack=0,n,wait=0;
	int old,new,size=sizeof(struct sockaddr_in);
	char po[16];
	struct sockaddr_in x,y;
	old=socket(AF_INET,SOCK_STREAM,0);
	x.sin_family=AF_INET;
	printf("Enter the port no : ");
	scanf("%s",po);
	x.sin_port=atoi(po);
	x.sin_addr.s_addr=INADDR_ANY;
	assert(bind(old,(struct sockaddr *)&x,sizeof(x))>=0);
	printf("Enter the no of packets to be send   :");
	scanf("%d",&n); 
	printf("Enter the window size  :");
	scanf("%d",&max); 	
	listen(old,1);
	new=accept(old,(struct sockaddr *)&y,&size);
	while(ack<n)
	{
		if(wait<0 && cur<n)
		{
		send(new,&cur,sizeof(cur),0);
		printf("Packet %d send \n",cur++);
		}
		if(wait==min-max)
		{
			wait = 10;
			cur = min;
		}
		
		if(recv(new,&ack,sizeof(ack),MSG_DONTWAIT)>1)
		{
			if(ack==max)
				wait=0;
			max+=ack-min;
			min=ack;
			if(cur<min)		
				cur=min;
			printf("Ack %d received \n ",ack);
			
			
		}
				usleep(40000);
				wait--;
		if(wait==0)
				printf(" Packet %d timed out \n",cur);
	}
		ack=-999;
		send(new,&ack,sizeof(ack),0);
		printf("Finished\n");
		close(new);
		close(old);
}
/*
OUTPUT
---------
Enter the port no : 4545
Enter the no of packets to be send   :8
Enter the window size  :3
Packet 0 send 
Packet 1 send 
Packet 2 send 
Ack 3 received 
 Packet 3 send 
Packet 4 send 
Packet 5 send 
Ack 5 received 
 Ack 6 received 
  Packet 6 timed out 
Packet 6 send 
Packet 7 send 
 Packet 6 timed out 
Packet 6 send 
Packet 7 send 
Ack 8 received 
 Finished
*/
