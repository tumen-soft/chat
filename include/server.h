/**
 *\file message.h
 *\author Вергун Денис 
 *\brief  Вводит определение класса сервера.
 *\version
 *\date 30-06-2023
 *
 *
 */


#include <arpa/inet.h>  //inet_addr define
#include <unistd.h>  //close(), fread()
#include <cstring>
#include <ext/stdio_filebuf.h>
#include "abspeer.h"
#include <iostream>;
#include <typeinfo>;
#include <vector>
#define MAXLINE 1024
#define PORT 8080 


class TCPServerPolicy;
class ServerPolicy;

class Server:virtual public AbstractPeer{
	public:
	Server();
	void foo();
	void foo1();
	Server(ServerPolicy *policy):serv(policy){}
        void createSocket()const override{
        foo();
        }; 
        void connectInit(const char* addr)const override{};
        void connectInit()const override{
        foo1();
        };
        //private:
        void selinit()const override{
        //foo2();
        }; 
	int getSock(){return sock;}
	void setSock(int _sock){sock=_sock;}
	ServerPolicy *serv;
        //void selinit();
	//private:
        void sel()const override{};
        void conn()const override{}; 
        void sendmes()const override{};
	private:
	int sd,new_socket, client_socket[30], max_clients=30, activity, i, max_sd, valread;
	std::vector<std::pair<int, char*>> nicknames;
	//int sock;///<Переменная для хранения сокета
        //struct sockaddr_in addres;///<Структура для хранения адреса и типа узла
        //char buffer[MAXLINE]={0};///<Хранит сообщение
        //fd_set read_fd={0};///<Массив дескрапторов для храненния сокета
};

class ServerPolicy{
        public:  
        ServerPolicy(){};
        virtual void createSocket(Server *server)const = 0;
        virtual void connectInit(const char* addr)const = 0;
        virtual void connectInit()const = 0;
        virtual void selinit(Server *server)const = 0;///<\param void  \return void
	virtual void sel()const=0;///<\param void  \return void
        virtual void conn()const=0;///<\param void  \return void
        virtual void sendmes()const=0;///<\param void  \return void

};
class TCPServerPolicy:public ServerPolicy{

public:        
TCPServerPolicy(){};
void createSocket(Server *server)const override{
        server->setSock(socket(AF_INET, SOCK_STREAM, 0));
        if(server->getSock())
        std::cout <<"TCP " <<typeid(server).name() << " fd " << server->getSock() << std::endl;
        else
        std::cout << "creation socket error" << std::endl;
}
void connectInit()const override{
        std::cout << "no ip addres specified" << std::endl;
}
void connectInit(const char* addr)const override{}
void selinit(Server *server)const override{}
        void sel()const override{};///<\param void  \return void
        void conn()const override{};///<\param void  \return void
        void sendmes()const override{};///<\param void  \return void


};
