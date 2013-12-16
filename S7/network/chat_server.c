#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc,char *argv[])
{
    int sockfd,newsockfd,portno;
    socklen_t clielen;
    char buffer[256];
    struct sockaddr_in serv_addr,cli_addr;
    int n;
    if(argc<2)
    {
        fprintf(stderr,"Error,no port provided\n");
        exit(1);
    }
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0)
        error("Error opening socket");
    bzero((char *)&serv_addr,sizeof(serv_addr));
    portno=atoi(argv[1]);
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=INADDR_ANY;
    serv_addr.sin_port=htons(portno);
    if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
        error("ERROR on binding");
    listen(sockfd,5);
    clielen=sizeof(cli_addr);
    newsockfd=accept(sockfd,(struct sockaddr *)&cli_addr,&clielen);
    if(newsockfd<0)
        error("ERROR on ACCEPT");
    while(1)
    {
        bzero(buffer,256);
        n=read(newsockfd,buffer,255);
        if(n<0)
            error("ERROR reading from socket");
        printf("Client : %s \n",buffer);
        if(buffer[0]=='b'&&buffer[1]=='y'&&buffer[2]=='e')
        {
            close(sockfd);
            return 0;
        }
        bzero(buffer,256);
        printf("server :");
        fgets(buffer,255,stdin);
        n=write(newsockfd,buffer,18);
        if(n<0)
            error("ERROR writing to socket");
        if(buffer[0]=='b'&&buffer[1]=='y'&&buffer[2]=='e')
        {
            close(sockfd);
            return 0;
        }
    }
    close(newsockfd);
    close(sockfd);
    return 0;
}
