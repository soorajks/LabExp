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
	struct sockaddr_in x;
	char buf[100],ch;
	int cur=0,ack=0,n,r,rcv;
	int sock, size=sizeof(struct sockaddr_in);
	sock=socket(AF_INET, SOCK_STREAM,0);
	x.sin_family= AF_INET;
	x.sin_port= PORT;
	x.sin_addr.s_addr= INADDR_ANY;
	assert(connect(sock,(struct sockaddr *)&x,sizeof(x))>=0);
	while(1)
	{
		r=recv(sock,&rcv,sizeof(rcv),MSG_DONTWAIT);
		if(r>1 &&rcv==cur)
		{
			if(random()%8!=0)
			printf("Packet %d received \n",cur++);
			else
			printf("Packet %d damaged \n",cur);
			ack=1;
		}
		if((ack)&&(random()%2==0))
		{
			send(sock,&cur,sizeof(cur),0);
			printf("Ack %d send \n",cur-1);
			ack=0;
		}	
		usleep(300000);
		if(rcv==-999)
		break;
		}
		close(sock);
	}

/* OUTPUT
-----------
Packet 0 received 
Ack 0 send 
Packet 1 received 
Ack 1 send 
Packet 2 received 
Ack 2 send 
Packet 3 received 
Ack 3 send 
Packet 4 received 
Ack 4 send 
*/









