#include <arpa/inet.h>  //inet_addr define
#include <ext/stdio_filebuf.h>
#include <stdio.h>  //printf()
#include <unistd.h>  //close(), fread()
#include <iostream>
#include <typeinfo>
#include <cstring>
//#include "abspeer.h"
#include "client.h"


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






Client::Client(){};
Client::Client(const char* addr){}


void Client::createSocket(){
	sock=socket(AF_INET, SOCK_STREAM, 0);
	if(sock)
	std::cout << typeid(this).name() << " fd " << sock << std::endl;
	else
	std::cout << "creation socket error" << std::endl;
}

void Client::connectInit(const char* addr){
	addres.sin_family = AF_INET;
        addres.sin_port = htons(PORT);
        addres.sin_addr.s_addr = inet_addr(addr);
        connect(sock, (struct sockaddr*)&addres, sizeof(addres));
}
void Client::connectInit(){
	std::cout << "no ip addres specified" << std::endl;
}
void Client::selinit(){
	memset(buffer, 0, sizeof(buffer));
	FD_ZERO(&read_fd);
	FD_SET(0, &read_fd);
	FD_SET(sock, &read_fd);
}
void Client::sel(){
//                select(300, &peer->read_fd, NULL, NULL, NULL);
	return this;
}



void Client::conn(){
	read(sock, buffer, sizeof(buffer));dprintf(0, buffer);
	return this;
}
void Client::sendmes(){
	if(FD_ISSET(0, &read_fd)){read(0, buffer,sizeof(buffer));dprintf(sock, buffer);}  
	//if(FD_ISSET(sock, &read_fd)){read(sock, buffer, sizeof(buffer));dprintf(0, buffer);}
	return this;
}



