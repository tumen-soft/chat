#include <arpa/inet.h>  //inet_addr define
//#include <ext/stdio_filebuf.h>
#include <stdio.h>  //printf()
#include <unistd.h>  //close(), fread()
//#include <iostream>
//#include <typeinfo>
//#include <cstring>
//#include "abspeer.h"
//#include "client.h"
//#include "policy.h"
//#include <unistd.h>  //close(), fread()
//#include <string.h>
#define MAXLINE 1024
#define PORT 8080 
/**
 *\file client.cpp
 *\author Денис Вергун
 *\brief  Файл содержит описание конкретного клиента
 *\version
 *\date 20-07-2023
 *
 *
 */




/*
void TestClient::createSocket(Client const& client)const override
{

        client.sock=socket(AF_INET, SOCK_STREAM, 0);
        if(client.sock)
        std::cout << typeid(client).name() << " fd " << client.sock << std::endl;
        else
        std::cout << "creation socket error" << std::endl;





}

*/


//void Client::foo(){clie->createSocket(this);};
//Client::Client(const char* addr){}

//void Client::foo1(){/*clie->connectInit()*/;};

//void Client::foo2(){clie->selinit(this);};

//typedef void (ClientPolicy::*func)();
//void Client::foo(func f){ClientPolicy *CP=clie;(CP->*f)();};








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
return connect(sock, (struct sockaddr*)&addres, sizeof(addres));	
//std::cout << "no ip addres specified" << std::endl;
}

fd_set selinit(int sock){
	//memset(buffer, 0, sizeof(buffer));
	fd_set read_fd;	
	FD_ZERO(&read_fd);
	FD_SET(0, &read_fd);
	FD_SET(sock, &read_fd);
	return read_fd;
}

void sel(fd_set read_fd){
	select(300, &read_fd, NULL, NULL, NULL);
	//return this;
}



void conn(int sock){
        char buffer[1024]={0};
	read(sock, buffer, sizeof(buffer));
	printf("%s\n",buffer);
	//return this;
}
void sendmes(){
	//if(FD_ISSET(0, &read_fd)){read(0, buffer,sizeof(buffer));dprintf(sock, buffer);}  
	//if(FD_ISSET(sock, &read_fd)){read(sock, buffer, sizeof(buffer));dprintf(0, buffer);}
}



