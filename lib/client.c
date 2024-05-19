#include <arpa/inet.h>  //inet_addr define
#include <stdio.h>  //printf()
#include <unistd.h>  //close(), fread()
#define MAXLINE 1024
#define PORT 8080 
/**
 *\file client.c
 *\author Денис Вергун
 *\brief  низкоуровневые функции для класса клиента
 *\version
 *\date 20-07-2023
 *
 *
 */




int createSocket(){
	int sock=socket(AF_INET, SOCK_STREAM, 0);
	//if(sock)
	//std::cout <<  " fd " << sock << std::endl;
	//else
	//std::cout << "creation socket error" << std::endl;
	return sock;
}

struct sockaddr_in connectInit(const char* addr){
	struct sockaddr_in addres;
	addres.sin_family = AF_INET;
        addres.sin_port = htons(PORT);
        addres.sin_addr.s_addr = inet_addr(addr);
        return addres;
	//connect(sock, (struct sockaddr*)&addres, sizeof(addres));
}

int connect_(int sock, struct sockaddr_in addres){
printf("test");
return connect(sock, (struct sockaddr*)&addres, sizeof(addres));	
//std::cout << "no ip addres specified" << std::endl;
}

fd_set selinit(int sock){
	//memset(buffer, 0, sizeof(buffer));
	fd_set read_fd={0};	
	FD_ZERO(&read_fd);
	FD_SET(0, &read_fd);
	FD_SET(sock, &read_fd);
	return read_fd;
}

fd_set sel(fd_set read_fd){
	select(300, &read_fd, NULL, NULL, NULL);
	//return this;
	return read_fd;
}



void conn(int sock){
        char buffer[1024]={0};
	read(sock, buffer, sizeof(buffer));
	printf("%s\n",buffer);
	//return this;
}
void sendmes(fd_set read_fd, int sock){
        char buffer[1024]={0};
	//printf("trst1111");
	if(FD_ISSET(0, &read_fd)){read(0, buffer,sizeof(buffer));dprintf(sock, buffer);}  
	if(FD_ISSET(sock, &read_fd)){read(sock, buffer, sizeof(buffer));dprintf(0, buffer);}
}



