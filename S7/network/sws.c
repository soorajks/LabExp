#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<assert.h>
#define PORT 8060
main()
{
	char buff[100],ch;
	int cur=0,ack=0,nack=0,n,wait=-1;
	int old,new,size=sizeof(struct sockaddr_in),r;
	struct sockaddr_in x,y;
	old=socket(AF_INET,SOCK_STREAM,0);
	x.sin_family=AF_INET;x.sin_port=PORT;
	x.sin_addr.s_addr=INADDR_ANY;
	assert(bind(old,(struct sockaddr *)&x,sizeof(x))>=0);
	printf("Enter the no of packets to be send   :");
	scanf("%d",&n); listen(old,1);
	new=accept(old,(struct sockaddr *)&y,&size);
	while(ack<n)
	{
		send(new,&cur,sizeof(cur),0);
		printf("Packet %d send \n",cur);
		usleep(100000);
		r=recv(new,&ack,sizeof(ack),MSG_DONTWAIT);
		if(r>1 && (ack=cur+1))
		{
			printf("Ack %d received \n ",ack-1);
			cur=ack;
			usleep(200000);}
			else
			{
				usleep(400000);
				printf(" Packet %d timed out \n",cur);
			}
	}
		ack=-999;
		send(new,&ack,sizeof(ack),0);
		printf("Finished\n");
		close(new);
		close(old);
}

/*OUTPUT
----------
Enter the no of packets to be send   :5 
Packet 0 send 
 Packet 0 timed out 
Packet 0 send 
Ack 0 received 
 Packet 1 send 
 Packet 1 timed out 
Packet 1 send 
 Packet 1 timed out 
Packet 1 send 
Ack 1 received 
 Packet 2 send 
 Packet 2 timed out 
Packet 2 send 
 Packet 2 timed out 
Packet 2 send 
Ack 2 received 
 Packet 3 send 
 Packet 3 timed out 
Packet 3 send 
Ack 3 received 
 Packet 4 send 
 Packet 4 timed out 
Packet 4 send 
Ack 4 received 
 Finished
*/
