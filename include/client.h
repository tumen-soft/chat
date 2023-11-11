/**
 *\file client.h
 *\author Денис Вергун
 *\brief  Файл содержит описание конкретного клиента
 *\version
 *\date 20-07-2023
 *
 *
 */

#ifndef cli
#define cli
#include <memory>
#define MAXLINE 1024
#define PORT 8080 
#include "abspeer.h"
#include <iostream>
//#include "strategy.h"
class TCPClientPolicy;
class ClientPolicy;
class Client:public Peer{
        public:
        Client(){}
        //Client(const char* addr);
        Client(ClientPolicy *policy):clie((policy)){}
        void foo();
	void createSocket()const override{
        //std::cout<<"end"; 
        //const Client &clien=Client();
        //clie->createSocket(*this);
	foo();
        }; 
        //void connectInit(const char* addr);
        //void connectInit();
        //private:
        //void selinit(); 
        //void sel();
        //void conn();
        //void sendmes();
        ClientPolicy *clie;
        int sock;///<Переменная для хранения сокета
        struct sockaddr_in addres;///<Структура для хранения адреса и типа узла
        char buffer[MAXLINE]={0};///<Хранит сообщение
        fd_set read_fd={0};///<Массив дескрапторов для храненния сокета
};


#endif
