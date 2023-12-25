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
#include <cstring>
#include <unistd.h>  //close(), fread()


class TCPClientPolicy;
class ClientPolicy;
class Client;
class ClientPolicy{
        public:  
        ClientPolicy(){};
        virtual void createSocket(Client *client) = 0;
        //virtual void connectInit(const char* addr) = 0;
        virtual void connectInit(Client *client) = 0;
        virtual void selinit(Client *client) = 0;///<\param void  \return void
        virtual void sel(Client *client)=0;///<\param void  \return void
        virtual void conn(Client *client)=0;///<\param void  \return void
        virtual void sendmes(Client *client)=0;///<\param void  \return void

};

typedef void (ClientPolicy::*funcC)(Client*);
class Client: protected AbstractPeer{
        public:
        Client(){}
        //Client(const char* addr);
        Client(ClientPolicy *policy):clie((policy)){}
	void foo(funcC);
	void createSocket() override{
	foo(&ClientPolicy::createSocket);
        }; 
        //void connectInit(const char* addr) override{};
        void connectInit() override{
        foo(&ClientPolicy::connectInit);
	};
        void selinit() override{
	foo(&ClientPolicy::selinit);
	}; 
        void sel() override{
        foo(&ClientPolicy::sel);
	};
        void conn() override{
        foo(&ClientPolicy::conn);
	};
        void sendmes() override{
        foo(&ClientPolicy::sendmes);
	};
        ClientPolicy *clie;
	//auto _sock()->int&  override{return sock;}
	OVER(int, sock);
	//int sock;///<Переменная для хранения сокета
        //struct sockaddr_in addres;///<Структура для хранения адреса и типа узла
        //char buffer[MAXLINE]={0};///<Хранит сообщение
        //fd_set read_fd={0};///<Массив дескрапторов для храненния сокета
};

#define sock _sock()

/*
class ClientPolicy{
        public:  
        ClientPolicy(){};
        virtual void createSocket(Client *client) = 0;
        virtual void connectInit(const char* addr) = 0;
        virtual void connectInit(Client *client) = 0;
        virtual void selinit(Client *client) = 0;///<\param void  \return void
        virtual void sel(Client *client)=0;///<\param void  \return void
        virtual void conn(Client *client)=0;///<\param void  \return void
        virtual void sendmes(Client *client)=0;///<\param void  \return void

};
*/
class TCPClientPolicy:public ClientPolicy{

public:        
TCPClientPolicy(){};
void createSocket(Client *client) override{
	client->sock=(socket(AF_INET, SOCK_STREAM, 0));
        if(client->_sock())
        std::cout <<"TCP " <<typeid(client).name() << " fd " << client->_sock() << std::endl;
        else
        std::cout << "creation socket error" << std::endl;

//std::cout<<__FUNCTION__<<std::endl;

}

///void connectInit(const char* addr) override{
        //addres.sin_family = AF_INET;
        //addres.sin_port = htons(PORT);
        //addres.sin_addr.s_addr = inet_addr(addr);
        //connect(sock, (struct sockaddr*)&addres, sizeof(addres));
//}
void connectInit(Client *client) override{
//        std::cout << "no ip addres specified" << std::endl;
//std::cout<<__FUNCTION__<<std::endl;

	///client->addres.sin_family = AF_INET;
        ///client->addres.sin_port = htons(PORT);
        ///client->addres.sin_addr.s_addr = inet_addr("127.0.0.1");
	///connect(client->sock, (struct sockaddr*)&client->addres, sizeof(client->addres));
	//dprintf(0, "test");
}

void selinit(Client *client) override{
//std::cout<<__FUNCTION__<<std::endl;
        ///memset(client->buffer, 0, sizeof(client->buffer));
        ///FD_ZERO(&client->read_fd);
        ///FD_SET(0, &client->read_fd);
        ///FD_SET(client->sock, &client->read_fd);
}

void sel(Client *client) override{
//std::cout<<__FUNCTION__<<std::endl;

           //select(300, &client->read_fd, NULL, NULL, NULL);
//        return this;
}



void conn(Client *client) override{
//std::cout<<__FUNCTION__<<std::endl;
//	read(client->sock, client->buffer, sizeof(client->buffer));dprintf(0, client->buffer);
        //return this;
}
void sendmes(Client *client) override{
//std::cout<<__FUNCTION__<<std::endl;
        ///if(FD_ISSET(0, &client->read_fd)){read(0, client->buffer,sizeof(client->buffer));dprintf(client->sock, client->buffer);}  
        ///if(FD_ISSET(client->sock, &client->read_fd)){read(client->sock, client->buffer, sizeof(client->buffer));dprintf(0, client->buffer);}
 //       return this;
}


};


class UDPClientPolicy:public ClientPolicy{

public:        
UDPClientPolicy();
void createSocket(Client *client) override{ 
	client->_sock()=(socket(AF_INET, SOCK_DGRAM, 0));
        if(client->_sock())
        std::cout <<"UDP " <<typeid(client).name() << " fd " << client->_sock() << std::endl;
        else
        std::cout << "creation socket error" << std::endl;

}


};






#endif
