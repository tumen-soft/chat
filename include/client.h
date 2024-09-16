/**
 *\file client.h
 *\author Денис Вергун
 *\brief  Файл содержит описание класса клиента
 *\version
 *\date 20-07-2023
 *
 *
 */

#include <memory>
#define MAXLINE 1024
#define PORT 8080 
#include "chat.h"
#include <iostream>
#include <cstring>
#include <unistd.h>  //close(), fread()
//#define DEBUG



extern "C"{
int createSocket(void);
struct sockaddr_in connectInit(const char* addr);
fd_set selinit(int sock);
int connect_(int sock, struct sockaddr_in addres);
fd_set  sel(fd_set read_fd);
void conn(int sock);
void sendmes(fd_set read_fd, int sock);
//void sendmes();

}








class TCPClientPolicy;
class ClientPolicy;
class NetClient;
class ClientPolicy: protected  NetNode{
        public:  
        //void setSock(int sock_){sock=sock_;}	
	//int getSock(){return valread;}
	ClientPolicy(){};
        virtual void _createSocket() = 0;
        //virtual void connectInit(const char* addr) = 0;
        virtual void connectInit() = 0;
        virtual void selinit() = 0;///<\param void  \return void
        virtual void sel()=0;///<\param void  \return void
        virtual void conn()=0;///<\param void  \return void
        virtual void sendmes()=0;///<\param void  \return void
	private:
	auto _valread()->int&{};
};

class NetClient: public Chat{//Сетевой клиент
        public:
        NetClient(){}
        //Client(const char* addr);
        NetClient(ClientPolicy *policy):clie((policy)){}
	void createSocket() override{
	clie->_createSocket();
        }; 
        //void connectInit(const char* addr) override{};
        void connectInit() override{
        //foo(&ClientPolicy::connectInit);
	};
        void selinit() override{
	//foo(&ClientPolicy::selinit);
	}; 
        void sel() override{
        //foo(&ClientPolicy::sel);
	};
        void conn() override{
        //foo(&ClientPolicy::conn);
	};
        void sendmes() override{
        //foo(&ClientPolicy::sendmes);
	};
        ClientPolicy *clie;
};


class TCPClientPolicy:public ClientPolicy{

public:        
TCPClientPolicy(){};
void _createSocket() override{
	Trace((stderr, __FUNCTION__));
        std::cout<<std::endl;
	sock=(createSocket());
	//std::cout<<valread<<std::endl;
}

///void connectInit(const char* addr) override{
        //addres.sin_family = AF_INET;
        //addres.sin_port = htons(PORT);
        //addres.sin_addr.s_addr = inet_addr(addr);
        //connect(sock, (struct sockaddr*)&addres, sizeof(addres));
//}
void connectInit() override{
        Trace((stderr, __FUNCTION__));
        ///std::cout<<std::endl;
	///addres.sin_family = AF_INET;
        ///addres.sin_port = htons(PORT);
        ///addres.sin_addr.s_addr = inet_addr("127.0.0.1");
	//connect(sock, (struct sockaddr*)&addres, sizeof(addres));
	//dprintf(0, "test");
}

void selinit() override{
        Trace((stderr, __FUNCTION__));
        std::cout<<std::endl;
        //memset(buffer, 0, sizeof(buffer));
        ///FD_ZERO(&read_fd);
        ///FD_SET(0, &read_fd);
        ///FD_SET(sock, &read_fd);
}

void sel() override{
        Trace((stderr, __FUNCTION__));
        std::cout<<std::endl;
           //select(300, &client->read_fd, NULL, NULL, NULL);
//        return this;
}



void conn() override{
        Trace((stderr, __FUNCTION__));
        std::cout<<std::endl;
//	read(client->sock, client->buffer, sizeof(client->buffer));dprintf(0, client->buffer);
        //return this;
}
void sendmes() override{
        Trace((stderr, __FUNCTION__));
        std::cout<<std::endl;
        ///if(FD_ISSET(0, &read_fd)){read(0, buffer,sizeof(buffer));dprintf(sock, buffer);}  
        ///if(FD_ISSET(sock, &read_fd)){read(sock, buffer, sizeof(buffer));dprintf(0, buffer);}
 //       return this;
}


};

/*
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
*/





