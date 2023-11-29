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

class Server:virtual public Peer{
	public:
	Server(){};
        void createSocket()const;///<Прообраз функции создания сокета для инициализации клиента/сервера. Запись в переменную sock \param void  \return void
        void connectInit(const char* addr)const;///<Запись в переменную addres и подготовка соединения \param void  \return void
        void connectInit()const;///\param void  \return void
        void selinit()const;///<\param void  \return void
        void connectInit(const char* addr);
        int *getSock(){return *sock;}
	void setSock(int _sock){sock=_sock;}
	private:
        void selinit();
        void sel();
        void conn(); 
        void sendmes();
	int sd,new_socket, client_socket[30], max_clients=30, activity, i, max_sd, valread;
	std::vector<std::pair<int, char*>> nicknames;
	int *sock;///<Переменная для хранения сокета
        struct sockaddr_in addres;///<Структура для хранения адреса и типа узла
        char buffer[MAXLINE]={0};///<Хранит сообщение
        fd_set read_fd={0};///<Массив дескрапторов для храненния сокета
};

class ServerPolicy{
        public:  
        ServerPolicy();
        virtual void createSocket(Server *server)const = 0;
        //void connectInit_(const char* addr)override{connectInit(addr);};
        //void connectInit_()override{connectInit();};
        //void selinit();///<\param void  \return void
        ///void sel();///<\param void  \return void
        //void conn();///<\param void  \return void
        //void sendmes();///<\param void  \return void

};
class TCPServerPolicy:public ServerPolicy{

public:        
TCPServerPolicy(){};
void createSocket(Server *client)const override{
        client->setSock(socket(AF_INET, SOCK_STREAM, 0));
        //if(client->sock)
        //std::cout <<"TCP " <<typeid(client).name() << " fd " << client->sock << std::endl;
        //else
        //std::cout << "creation socket error" << std::endl;
}
};
