#include <arpa/inet.h>  //inet_addr define
#include <ext/stdio_filebuf.h>
#include <stdio.h>  //printf()
#include <unistd.h>  //close(), fread()
#include <iostream>
#include <typeinfo>
#include <cstring>
#include "abspeer.h"

#define MAXLINE 1024
#define PORT 8080 

/**
 *\file client.h
 *\author Денис Вергун
 *\brief  Файл содержит описание конкретного клиента
 *\version
 *\date 20-07-2023
 *
 *
 */






//вводим определение клиента и сервера
class Client{
        public:
	Client(){};
	//Client(int _sock, struct sockaddr_in _addres):AbstractPeer(_sock, _addres){}


       int sock;///<Переменная для хранения сокета
        struct sockaddr_in addres;///<Структура для хранения адреса и типа узла
        char buffer[MAXLINE]={0};///<Хранит сообщение
        fd_set read_fd={0};///<Массив дескрапторов для храненния сокета





void createSocket() {
	sock=socket(AF_INET, SOCK_STREAM, 0);
	std::cout << typeid(this).name() << " fd " << sock << std::endl;
}

void connectInit()  ///<клиентская часть
        {

	addres.sin_family = AF_INET;
        addres.sin_port = htons(PORT);
        addres.sin_addr.s_addr = inet_addr("127.0.0.1");

        connect(sock, (struct sockaddr*)&addres, sizeof(addres));
        //dprintf(peer->sock, s);
	//std::cout <<"test" <<std::endl;

        }


void selinit() {

                memset(buffer, 0, sizeof(buffer));
                FD_ZERO(&read_fd);
                FD_SET(0, &read_fd);
                FD_SET(sock, &read_fd);

}






void sel() {
//                select(300, &peer->read_fd, NULL, NULL, NULL);

	return this;
}



void conn() {
read(sock, buffer, sizeof(buffer));dprintf(0, buffer);//}
return this;
}


void sendmes(){

if(FD_ISSET(0, &read_fd)){read(0, buffer,sizeof(buffer));dprintf(sock, buffer);}  
//if(FD_ISSET(sock, &read_fd)){read(sock, buffer, sizeof(buffer));dprintf(0, buffer);}

return this;



}

};

class cli:public Client, public Peer{public: cli(){}};

