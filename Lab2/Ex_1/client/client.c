#include<string.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<sys/stat.h>

int main()
{
	int i =0, j=0 , k=0, p=0;
	int arr[1024] ;
	int b[1024] ;

	int s=0,r=0,recb=0,sntb=0,x=0;
	int sa=0;
	socklen_t len;
	struct sockaddr_in server,client;
	char buff[1024] = "";
	char buf[1024] = "";
	printf("INPUT port number: ");
	scanf("%d", &x);

	s=socket(AF_INET,SOCK_DGRAM,0);
	if(s==-1)
	{printf("\nSocket creation error.");exit(0);}
	printf("\nSocket created.");

	server.sin_family=AF_INET;server.sin_port=htons(x);server.sin_addr.s_addr=inet_addr("127.0.0.1");sa=sizeof(server);len=sizeof(server);

/*
	printf("\n\nType Message: ");
	scanf("%s", buff);

	sntb=sendto(s,buff,sizeof(buff),0,(struct sockaddr *)&server, len);
	if(sntb==-1)
	{close(s);printf("\nMessage sending Failed");exit(0);}

	recb=recvfrom(s,buff,sizeof(buff),0,(struct sockaddr *)&server,&sa);
	if(recb==-1)
	{printf("\nMessage Recieving Failed");close(s);exit(0);}
	
	printf("\nMessage Recieved: ");
	printf("%s", buff);
*/

	sprintf(buff,"1st message");
	sntb=sendto(s,buff,sizeof(buff),0,(struct sockaddr *)&server, len);
	if(sntb==-1)
	{close(s);printf("\nMessage sending Failed");exit(0);}

	char opt[1024];
	r = recvfrom(s,opt,sizeof(opt),0,(struct sockaddr *)&server,&sa);
	printf("Option - %s\n", opt);
	printf("%s", "Enter Choice : ");
	scanf("%d" , &j);
	char op[3];
	sprintf(op , "%d" , j);
	int f = sendto(s , op , sizeof(op) , 0,(struct sockaddr *)&server, len);
	if( j == 4)
	{
	exit(0);
	}
	printf("%s", "Enter file name : ");
	scanf("%s" , buf);
	int sd = sendto(s , buf , sizeof(buf) , 0,(struct sockaddr *)&server, len);
	printf("\n\n");
	recvfrom(s , buf , 1024 , 0,(struct sockaddr *)&server, &len);
	printf("%s\n\n", buf);
	if(strcmp(buf,"File Not Present !")==0)
	{
		exit(0);
	}
	if( j == 1 )
	{
	printf("Enter String to be searched : ");
	char src[1024];
	scanf("%s" , src);
	printf("\n");
	sendto(s , src ,sizeof(src) , 0,(struct sockaddr *)&server, len);
	recvfrom(s , buf , sizeof(buf) , 0,(struct sockaddr *)&server, &len);
	printf("%s\n", buf);
	}
	if (j == 2)
	{
	printf("Enter the string that is to be replaced : ");
	char str1[1024] , str2[1024];
	scanf("%s" , str1);
	printf("\nEnter New String : ");
	scanf("%s" , str2);
	sendto(s , str1 , sizeof(str1) , 0,(struct sockaddr *)&server, len);
	sendto(s , str2 , sizeof(str2) , 0,(struct sockaddr *)&server, len);
	recvfrom(s , buf , 1024 , 0,(struct sockaddr *)&server, &len);
	printf("\nModified String is \n\n%s\n\n", buf);
	}
	if(j == 3)
	{
	recvfrom(s , buf , 1024 , 0,(struct sockaddr *)&server, &len);
	printf("The Sorted String is : \n\n%s\n\n",buf);
	}
	close(s);

}
