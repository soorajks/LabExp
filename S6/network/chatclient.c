#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc,char *argv[])
{
    int sockfd,portno;
    char buffer[256];
    struct sockaddr_in serv_addr;
    struct hostent *server;
    int n;
    
    if(argc<3)
    {
        fprintf(stderr,"Usage %s host name port\n",argv[0]);
        exit(0);
        
    }
    portno=atoi(argv[2]);
    sockfd=socket(AF_INET,SOCK_STREAM,0);
   
   if(sockfd<0)
        error("Error opening Socket");
         
    server=gethostbyname(argv[1]);
    if(server==NULL)
    {
        fprintf(stderr,"Error no such host\n");
        exit(0);
    }
         
    bzero((char *)&serv_addr,sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
    serv_addr.sin_port=htons(portno);
    if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
            error("Error connecting\n");
    while(1)
    { 
    printf("Client : ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);
    n=write(sockfd,buffer,strlen(buffer));
    if(n<0)
        error("Error writing to socket");
    if(buffer[0]=='b'&&buffer[1]=='y'&&buffer[2]=='e')
    {
         close(sockfd);
         return 0;
    }
    bzero(buffer,256);
    n=read(sockfd,buffer,255);
    if(n<0)
       error("Error reading from socket");
   printf("Server :%s\n",buffer);
   }
   if(buffer[0]=='b'&&buffer[1]=='y'&&buffer[2]=='e')
   {
        close(sockfd);
        return 0;
   }
   close(sockfd);
   return 0;
}
