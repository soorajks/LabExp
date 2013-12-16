#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<errno.h>
#include<netinet/in.h>
#include<sys/socket.h>

int main(int argc,char argv[])
{
	int sock,new_socket,j=0,rval,port,c,count=0,ch;
	char *msg,buff[2000];
	struct sockaddr_in server,client;
	sock=socket(AF_INET,SOCK_STREAM,0);
	char *t,*tmp,*temp;
	t="RF";
	tmp="RcvdF";
	temp="RcvdFile";
	

	if(sock==-1)
		printf("\n couldnot create socket");
	server.sin_addr.s_addr=inet_addr("127.0.0.1");
	server.sin_family=AF_INET;
	printf("\n port : ");
	scanf("%d",&port);
	server.sin_port=htons(port);
	if(connect(sock,(struct sockaddr *)&server,sizeof(server))<0)
	{
		puts("\n connection failed");
		return 1;
	}
		puts("\n connected ");
		do
		{
			bzero(buff,2000);
			puts("\n command \n\t?ls\n\t?pwd\n\t?get\n\t?exit\n");
			printf("Enter the command   :    ");
			scanf("%s",buff);
			printf("\n");
			if(write(sock,buff,sizeof(buff))<0)
			{
				puts("\nsend failed :");
				return 1;
			}
						
			if(!strcmp(buff,"exit"))
				goto ex;
			if(!strcmp(buff,"get"))
				
			{
			
			
				sleep(2);
			if(recv(sock,buff,sizeof(buff),0)<0)
			{
				puts("\n Recieved failed");
			}
			else
			{
				puts(buff);
				bzero(buff,2000);
				scanf("%s",buff);
			printf("\n");
			if(write(sock,buff,sizeof(buff))<0)
			{
				puts("\nsend failed :");
				return 1;
			}
			else
			{
				bzero(buff,2000);
				FILE *file=fopen(t,"wb");
				rval=recv(sock,buff,sizeof(buff),0);
				fwrite(buff,1,rval,file);
				fopen(t,"rb");
				fread(buff,1,rval,file);
				puts(buff);
				bzero(buff,rval);
				close(file);
			}
				
		}
	}
	
	 if(!strcmp(buff,"pwd"))
	{
		bzero(buff,2000);
		FILE *file=fopen(tmp,"wb");
		rval=recv(sock,buff,sizeof(buff),0);
		fwrite(buff,1,rval,file);
		fopen(tmp,"rb");
		fread(buff,1,rval,file);
		puts(buff);
		close(file);
	}
	 if(!strcmp(buff,"ls"))
		{
		bzero(buff,2000);
		FILE *file=fopen(temp,"wb");
		recv(sock,buff,sizeof(buff),0);
		fwrite(buff,1,sizeof(buff),file);
		count++;
		fopen(temp,"rb");
		fread(buff,1,sizeof(buff),file);
		puts(buff);
		close(file);
		}
	
		printf("Do u want to continue ? (1/0) : ");
		scanf("%d",&ch);
	}while(ch==1);
	if(ch!=1)
	{
		bzero(buff,2000);
		strcpy(buff,"exit");
		write(sock,buff,sizeof(buff));
		
	}
	
	ex :	
		
	
	close(sock);
	return 0;
}
		
