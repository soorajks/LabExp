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
	struct sockaddr_in x;
	
	int min=0,cur=0,ack=0,sock,max,r,rcv;
	int old,new, size=sizeof(struct sockaddr_in);
	sock=socket(AF_INET, SOCK_STREAM,0);
	char po[16];
	x.sin_family= AF_INET;
	printf("Enter the port no : ");
	scanf("%s",po);
	x.sin_port=atoi(po);
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
			{
				printf("Packet %d damaged \n",rcv);
				rcv=-1;
			}
			ack=cur;
		}
		if(rcv==-1||(ack>=0)&&(random()%10==0))
		{
			send(sock,&ack,sizeof(ack),0);
			printf("Ack %d send \n",ack);
			max+=cur-min; min=cur; ack=-1; rcv=0;
		}
		if(rcv==-999)		break;	
		usleep(30000);
	
		}
		close(sock);
	}


/*OUTPUT
-----------
Enter the port no : 4545
Packet 0 received 
Packet 1 received 
Packet 2 received 
Ack 3 send 
Packet 3 received 
Packet 4 received 
Ack 5 send 
Packet 5 received 
Ack 6 send 
Packet 6 received 
Packet 7 received 
Ack 8 send 
*/








