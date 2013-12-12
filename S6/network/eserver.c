#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main(int argc ,char *argv[])
{
	int sock_fd, new_fd,portno;
	
	socklen_t clilen;
	
	char buffer[50];
	struct sockaddr_in serv_addr,cli_addr;
	int n;
	if(argc < 2)
	{
		printf("ERROR ,no port provided\n");
		exit(1);
	}
	
	sock_fd=socket(AF_INET ,SOCK_STREAM,0);
	if(sock_fd<0)
		printf("ERROR Opening socket");
	
	bzero((char *)&serv_addr,sizeof(serv_addr));
	portno=atoi(argv[1]);
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=INADDR_ANY;
	serv_addr.sin_port=htons(portno);

	if(bind(sock_fd , (struct sockaddr *) &serv_addr,sizeof (serv_addr))<0)
		printf("ERROR on binding");
	listen (sock_fd,5);
	clilen = sizeof(cli_addr);

	new_fd=accept(sock_fd, (struct sockaddr *) &cli_addr,&clilen);
	if(new_fd <0)
 		printf ("\nERROR on accept");
	while(1)
	{
		bzero(buffer,50);
		n=read(new_fd,buffer,50);
		if(buffer[0]=='b'&&buffer[1]=='y'&&buffer[2]=='e')
			break;
		if(n<0)
			printf("ERROR from reading from  socket");
		
		printf("Client : %s \n",buffer);
		n= write(new_fd,buffer,strlen(buffer));
		if (n<0)
			printf("\nError writing to socket");
		
	}
close(new_fd);
close(sock_fd);
return 0;
}

