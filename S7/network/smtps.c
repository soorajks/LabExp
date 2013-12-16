#include <stdio.h>
#include <string.h>
#include <netdb.h>

void parse(char *a,char b[50][50])
{
	int i=0,j=0,k=0;
	while(a[i]!=0 && a[i]!='\n' && a[i]!='\r')
	{
		if(a[i]==':')
		{
			b[j][k]='\0';
			j++;
			k=0;
		}
		else
		{
			b[j][k]=a[i];
			k++;
		}
		i++;
	}
	b[j][k]='\0';
}

int listento(int port)
{
	int s;
	struct sockaddr_in seraddr;
	bzero((char*)&seraddr,sizeof(seraddr));
	seraddr.sin_family=AF_INET;
	seraddr.sin_addr.s_addr=INADDR_ANY;
	seraddr.sin_port=htons(port);
	s=socket(AF_INET,SOCK_STREAM,0);
	if(bind(s,(struct sockaddr*)&seraddr,sizeof(seraddr))<0)
	{
		printf("Error binding\n");
		return -1;
	}
	listen(s,5);
	return s;
}

main(int argc,char* argv[])
{
	int s1,s2,port,clen,i=0;
	char buff[256];
	char b[50][50];
	char domain[80],from[80],to[80],fname[256];
	FILE* fp;
	struct sockaddr_in cliaddr;

	clen=sizeof(cliaddr);
	
	if(argc<2)
	{
		printf("Port? : ");
		scanf("%d",&port);
		gets(buff);
	}
	else
		port=atoi(argv[1]);
	s1=listento(port);
	s2=accept(s1, (struct sockaddr*)&cliaddr,&clen);
	printf("%d\n",s2);
	printf("Client connected,Client says ..... \n");
	strcpy(buff,"smtp.localhost\r\n");
	write(s2,buff,strlen(buff));
	
	bzero(&buff,256);
	read(s2,buff,255);
	printf("C:%s",buff);
	
	parse(buff,b);
	if(strcmp(b[0],"HELO")==0)
	{
		strcpy(domain,b[1]);
		sprintf(buff,"HELLP %s  \r\n",b[1]);
		write(s2,buff,strlen(buff));
	}

	bzero(&buff,256);
	read(s2,buff,255);
	printf("C:%s",buff);

	parse(buff,b);
	if(strcmp(b[0],"MAIL FROM")==0)
	{
		strcpy(from,b[1]);
		sprintf(buff,"OK \r\n");
		write(s2,buff,strlen(buff));
	}

	bzero(&buff,256);
	read(s2,buff,255);
	printf("C:%s",buff);
	
	parse(buff,b);
	if(strcmp(b[0],"RCPT TO")==0)
	{
		strcpy(to,b[1]);
		sprintf(buff,"OK\r\n");
		write(s2,buff,strlen(buff));
	}

	bzero(&buff,256);
	read(s2,buff,255);
	printf("%s",buff);

	parse(buff,b);
	if(strcmp(b[0],"DATA")==0)
	{
		sprintf(buff,"OK\r\n");
		write(s2,buff,strlen(buff));
		mkdir(to,0777);
		sprintf(fname,"%s/newmail.txt",to);
		fp=fopen(fname,"w");
		while(1)
		{
			bzero(&buff,256);
			read(s2,buff,255);
			if(strcmp(buff,".")==0)
				break;
			printf("C:%s\n",buff);
			fputs(buff,fp);
			sprintf(buff,"OK\r\n");
			write(s2,buff,strlen(buff));
		}
		fclose(fp);
	}
	
	bzero(&buff,256);
	read(s2,buff,255);
	printf("C:%s",buff);

	parse(buff,b);
	if(strcmp(b[0],"QUIT")==0)
	{
		strcpy(to,b[1]);
		sprintf(buff,"BYE\r\n");
		write(s2,buff,strlen(buff));
	}
	close(s2);
	close(s1);
	printf("Server Closed\n");
}
