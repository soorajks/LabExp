#include <stdio.h>
#include <string.h>
#include <netdb.h>

int connectto(char* ip,int port)
{
	int s;
	struct sockaddr_in seraddr;
	bzero(&seraddr,sizeof(seraddr));
	seraddr.sin_family=AF_INET;
	seraddr.sin_addr.s_addr=inet_addr(ip);
	seraddr.sin_port=htons(port);

	s=socket(AF_INET,SOCK_STREAM,0);
	if(connect(s,(struct sockaddr*)&seraddr,sizeof(seraddr))<0)
	{
		printf("Connection Failed\n");
		return -1;
	}
	return s;
}

main(int argc,char* argv[])
{
	int s1,port,i=0,n;
	char buff[256],from[256],to[256],msg[256][256];

	if(argc<2)
	{
		printf("Port?: ");
		scanf("%d",&port);
		gets(buff);
	}
	else
		port=atoi(argv[1]);
	
	printf("Enter from address : ");
	gets(from);
	printf("Enter to address : ");
	gets(to);
	printf("Enter the message. \n. To Terminate\n");
	while(1)
	{
		gets(msg[i]);
		if(strcmp(msg[i],".")==0)
			break;
		i++;
	}
	n=i+1;

	s1=connectto("127.0.0.1",port);
printf("dsrerffgghdfghConnecting to server. Server says ....\n");
	printf("Connecting to server. Server says ....\n");
	strcpy(buff,"HELLO:localhost\r\n");
	write(s1,buff,strlen(buff));

	bzero(&buff,256);
	read(s1,buff,255);
	printf("%s",buff);

	sprintf(buff,"MAIL FROM : %s\r\n",from);
	write(s1,buff,strlen(buff));

	bzero(&buff,256);
	read(s1,buff,255);
	printf("S:%s",buff);
	
	sprintf(buff,"RCPT TO: %s\r\n",to);
	write(s1,buff,strlen(buff));

	bzero(&buff,256);
	read(s1,buff,255);
	printf("S:%s",buff);

	sprintf(buff,"DATA\r\n",to);
	write(s1,buff,strlen(buff));

	bzero(&buff,256);
	read(s1,buff,255);
	printf("S:%s",buff);

	for(i=0;i<n;i++)
	{
		write(s1,msg[i],strlen(msg[i]));
		bzero(&buff,256);
		read(s1,buff,255);
	}

	sprintf(buff,"QUIT\r\n",to);
	write(s1,buff,strlen(buff));

	bzero(&buff,256);
	read(s1,buff,255);
	printf("S:%s",buff);

	close(s1);
	printf("Client closed \n");
}
