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

class TCPClientPolicy;
class ClientPolicy;
class Client:public Peer{
        public:
        Client(){}
        //Client(const char* addr);
        Client(ClientPolicy *policy):clie((policy)){}
        void foo();
	void foo1();
	void createSocket()const override{
        //std::cout<<"end"; 
        //const Client &clien=Client();
        //clie->createSocket(*this);
	foo();
        }; 
        void connectInit(const char* addr)const override{};
        void connectInit()const override{
	foo1();
	};
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

class ClientPolicy{
        public:  
        ClientPolicy(){};
        virtual void createSocket(Client *client)const = 0;
        virtual void connectInit(const char* addr)const = 0;
        virtual void connectInit()const = 0;
        //void selinit();///<\param void  \return void
        ///void sel();///<\param void  \return void
        //void conn();///<\param void  \return void
        //void sendmes();///<\param void  \return void

};

class TCPClientPolicy:public ClientPolicy{

public:        
TCPClientPolicy(){};
void createSocket(Client *client)const override{
        client->sock=socket(AF_INET, SOCK_STREAM, 0);
        if(client->sock)
        std::cout <<"TCP " <<typeid(client).name() << " fd " << client->sock << std::endl;
        else
        std::cout << "creation socket error" << std::endl;
}

void connectInit(const char* addr)const override{
        //addres.sin_family = AF_INET;
        //addres.sin_port = htons(PORT);
        //addres.sin_addr.s_addr = inet_addr(addr);
        //connect(sock, (struct sockaddr*)&addres, sizeof(addres));
}
void connectInit()const override{
        std::cout << "no ip addres specified" << std::endl;
}
/*
void selinit(){
        memset(buffer, 0, sizeof(buffer));
        FD_ZERO(&read_fd);
        FD_SET(0, &read_fd);
        FD_SET(sock, &read_fd);
}
void sel(){
//                select(300, &peer->read_fd, NULL, NULL, NULL);
        return this;
}



void conn(){
        read(sock, buffer, sizeof(buffer));dprintf(0, buffer);
        return this;
}
void sendmes(){
        if(FD_ISSET(0, &read_fd)){read(0, buffer,sizeof(buffer));dprintf(sock, buffer);}  
        //if(FD_ISSET(sock, &read_fd)){read(sock, buffer, sizeof(buffer));dprintf(0, buffer);}
        return this;
}
*/


};


class UDPClientPolicy:public ClientPolicy{

public:        
UDPClientPolicy();
void createSocket(Client *client)const override{ 
	client->sock=socket(AF_INET, SOCK_DGRAM, 0);
        if(client->sock)
        std::cout <<"UDP " <<typeid(client).name() << " fd " << client->sock << std::endl;
        else
        std::cout << "creation socket error" << std::endl;

}


};






#endif
