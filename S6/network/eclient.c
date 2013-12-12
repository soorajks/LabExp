#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>

int main(int argc ,char *argv[])
{
	int sock_fd, n,portno;
	
	struct sockaddr_in server;
	struct hostent *host;
	
	char buffer[50];
	
	portno=atoi(argv[2]);
	
	sock_fd = socket(AF_INET,SOCK_STREAM,0);
	
	if(sock_fd<0)
	{	printf("\nOpening Socket");
	}
	host = gethostbyname(argv[1]);
	
	if(host==NULL)
	{	printf("Error, no such host\n");
		exit(0);
	}
	
	bzero( (char *) &server, sizeof(server));

	server.sin_family = AF_INET;
	
	bcopy((char *)host->h_addr,(char *)&server.sin_addr.s_addr,host->h_length);
	
	server.sin_port = htons(portno);
	if(connect(sock_fd,(struct sockaddr *) &server,sizeof(server))<0)
		printf("\nError connecting");
	while(1)
	{
		printf("Client: ");
		bzero(buffer,50);
		fgets(buffer,50,stdin);
		n= write(sock_fd,buffer,strlen(buffer));
		if (n<0)
			printf("\nError writing to socket");
		if(buffer[0]=='b'&&buffer[1]=='y'&&buffer[2]=='e')
			break;	
		bzero(buffer,50);
		n=read(sock_fd,buffer,50);
		if(n<0)
			printf("ERROR from reading from  socket");
			else
		printf("Server : %s \n",buffer);
	}
close(sock_fd);
return 0;
}

