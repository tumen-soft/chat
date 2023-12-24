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
class Server;
class ServerPolicy{
        public:  
        ServerPolicy(){};
        virtual void createSocket(Server *server) = 0;
        //virtual void connectInit(const char* addr) = 0;
        virtual void connectInit(Server *server) = 0;
        virtual void selinit(Server *server) = 0;///<\param void  \return void
        virtual void sel(Server *server)=0;///<\param void  \return void
        virtual void conn(Server *server)=0;///<\param void  \return void
        virtual void sendmes(Server *server)=0;///<\param void  \return void

};



typedef void (ServerPolicy::*func)(Server*);
class Server: public AbstractPeer{
	public:
	Server();
	void foo(func);
	Server(ServerPolicy *policy):serv(policy){}
        void createSocket()override{
        foo(&ServerPolicy::createSocket);
        }; 
        //void connectInit(const char* addr) override{
	//foo(&Server::connectInit);
	//};
        void connectInit() override{
        foo(&ServerPolicy::connectInit);
        };
        void selinit() override{
        foo(&ServerPolicy::selinit);
        }; 
        void sel() override{
	foo(&ServerPolicy::sel);
	};
        void conn() override{
	foo(&ServerPolicy::conn);
	}; 
        void sendmes() override{
	foo(&ServerPolicy::sendmes);
	};
	int getSock(){return sock;}
        void setSock(int _sock){sock=_sock;}
        //private:
	ServerPolicy *serv;
	        auto x()->int&  override{return sock;}	
        OVER(int, sock1);
	///int getsock()override{return sock;};
        //void setsock(int x)override{sock=x;};   
	//int sd,new_socket, client_socket[30], max_clients=30, activity, i, max_sd, valread;
	//std::vector<std::pair<int, char*>> nicknames;
	//int sock;///<Переменная для хранения сокета
        //struct sockaddr_in addres;///<Структура для хранения адреса и типа узла
        //char buffer[MAXLINE]={0};///<Хранит сообщение
        //fd_set read_fd={0};///<Массив дескрапторов для храненния сокета
};
class TCPServerPolicy:public ServerPolicy{

public:        
TCPServerPolicy(){};
void createSocket(Server *server) override{
        server->setSock(socket(AF_INET, SOCK_STREAM, 0));
        if(server->getSock())
        std::cout <<"TCP " <<typeid(server).name() << " fd " << server->getSock() << std::endl;
        else
        std::cout << "creation socket error" << std::endl;

//std::cout<<__FUNCTION__<<std::endl;

}
void connectInit(Server *server) override{
//        std::cout << "no ip addres specified" << std::endl;
//std::cout<<__FUNCTION__<<std::endl;

        server->addres.sin_family = AF_INET;
        server->addres.sin_port = htons(PORT);
        server->addres.sin_addr.s_addr = htonl(INADDR_ANY);

        bind(server->sock, (struct sockaddr*)&server->addres, sizeof(server->addres));
        //waiting for connection
        listen(server->sock, 300);
        //std::cout <<"test" <<std::endl;
        //server->nicknames.push_back({0,"test"});
	//server->new_socket = accept(server->sock,NULL,NULL);
	//read(server->new_socket, server->buffer, 1024);
        //std::cout<<server->buffer<<std::endl;;  

}
//void connectInit(const char* addr) override{
/*
	addres.sin_family = AF_INET;
        addres.sin_port = htons(PORT);
        addres.sin_addr.s_addr = htonl(INADDR_ANY);

        bind(sock, (struct sockaddr*)&addres, sizeof(addres));
        //waiting for connection
        listen(sock, 300);
        //std::cout <<"test" <<std::endl;
        nicknames.push_back({0,"test"});
        return this;
*/
//}

void selinit(Server *server) override{
//std::cout<<__FUNCTION__<<std::endl;
	memset(server->buffer, 0, sizeof(server->buffer));
        FD_ZERO(&server->read_fd);
        //FD_SET(0, &server->read_fd);
        FD_SET(server->sock, &server->read_fd);

}
        void sel(Server *server) override{
//std::cout<<__FUNCTION__<<std::endl;
server->nicknames.push_back({0,"me"});

for (auto itr = server->nicknames.begin(); itr != server->nicknames.end(); ++itr)
FD_SET(itr->first, &server->read_fd);
               // select(300, &server->read_fd, NULL, NULL, NULL);

};///<\param void  \return void
        void conn(Server *server) override{
//std::cout<<__FUNCTION__<<std::endl;
			server->new_socket = accept(server->sock,NULL,NULL);
                        //accepting connection
                        //new_socket = accept(sock,NULL,NULL);
                        //char g[80]={"sos"};
                        //g="sos";
                        //read(peer->new_socket,g,1024);
                        server->nicknames.push_back({server->new_socket,"test"});
                        std::cout<< "New connection "<<server->new_socket<<std::endl;
                        //printf("New connection %s\n", server->new_socket);
                        dprintf(server->new_socket,"welcome %d\n", server->new_socket);  

};///<\param void  \return void
        void sendmes(Server *server) override{
//std::cout<<__FUNCTION__<<std::endl;


	for (auto itr2 = server->nicknames.begin(); itr2 != server->nicknames.end(); ++itr2)
                {//std::cout<<itr2->first; 
			server->sd = itr2->first;
			//std::cout<<itr2->first<<std::endl; 
			if (FD_ISSET(server->sd , &server->read_fd)) 
                        {//std::cout<<"test"; 
				(server->set(read(server->sd, server->buffer, 1024))); 
				if (server->get())
				/*{ 
                                        printf("Host disconnected %s \n" ,itr2->second); 
                                        close(peer->sd); 
					peer->nicknames.erase(itr2); 
                                	break;				
				} 
                                else
					*/
				{ 
	  				server->buffer[server->get()] = '\0';
					for (auto itr1 = server->nicknames.begin(); itr1 != server->nicknames.end(); ++itr1)
					dprintf(itr1->first,"%s says: %s\n",itr2->second, server->buffer);
					
                                 }  
                        } 
             
        	}


};///<\param void  \return void

};
