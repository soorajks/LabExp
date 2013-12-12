#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<errno.h>
#include<netinet/in.h>
#include<sys/socket.h>

int main(int argc,char argv[])
{
	int sock,c,new_socket,j=0,rval,port;
	char *msg,buff[200],client_reply[2000];
	struct sockaddr_in server,client;
	sock=socket(AF_INET,SOCK_STREAM,0);
	char filename[50];
	fpos_t *r;
	if(sock==-1)
		printf("\n couldnot create socket");
	server.sin_addr.s_addr=inet_addr("127.0.0.1");
	server.sin_family=AF_INET;
	printf("\n port : ");
	scanf("%d",&port);
	server.sin_port=htons(port);
	if(bind(sock,(struct sockaddr *)&server,sizeof(server))<0)
	{
		puts("\n Bind failed");
	}
	else
	{
		puts("\n bind done");
		listen(sock,3);
		puts("\n witing for incoming connection");
		c=sizeof(struct sockaddr_in);
		new_socket=accept(sock,(struct sockaddr *)&client,(socklen_t *)&c);
	again:  sleep(5);
		bzero(client_reply,2000);
		recv(new_socket,client_reply,sizeof(client_reply),0);
		while(1)
		{
			if(!strcmp(client_reply,"exit"))
				goto ex;
			if(!strcmp(client_reply," "))
				goto again;
			puts("Reply recived \n");
			puts(client_reply);
			if(!strcmp(client_reply,"get"))
			{	msg="Which file do u want";
				if(send(new_socket,msg,strlen(msg),0)<0)
				{
					puts("SEnt Failed");
					return 1;
				}
			sleep(2);
			if(recv(new_socket,client_reply,sizeof(client_reply),0)<0)
			{
				puts("\n Recieved failed");
			}
			else
			{
				printf("Received %s \n",client_reply);
				FILE *file=fopen(client_reply,"rb");
				rval=fread(buff,1,sizeof(buff),file);
				if(send(new_socket,buff,sizeof(buff),0)<0)
				{
					puts("SEnt Failed");
					return 1;
				}
				close(file);
				puts("\n file transfered sucessfully \n");
			}
		}
		else if(!strcmp(client_reply,"pwd"))
		{
			system("pwd>temp0");
			FILE *file=fopen("temp0","rb");
			rval=fread(buff,1,sizeof(buff),file);
			if(send(new_socket,buff,sizeof(buff),0)<0)
				{
					puts("SEnt Failed");
					return 1;
				}
				close(file);
				puts("\n file transfered sucessfully \n");
			}
		else if(!strcmp(client_reply,"ls"))
		{
			system("ls>sentfile");
			FILE *file=fopen("sentfile","rb");
			rval=fread(buff,1,sizeof(buff),file);
			if(send(new_socket,buff,sizeof(buff),0)<0)
				{
					puts("SEnt Failed");
					return 1;
				}
				close(file);
				puts("\n file transfered sucessfully \n");
		}
		else
		{
			printf("Wrong command");
			goto ex;
		}
		sleep(5);
		bzero(client_reply,2000);
		if(recv(new_socket,client_reply,sizeof(client_reply),0)<0)
		{
			puts("\n Receive failed");
			return 1;
		}
	}
}
ex: printf("\n Exit");
	close(new_socket);
	close(sock);
	return 0;
}
		
