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
class Server:virtual public AbstractPeer{
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
	int sd,new_socket, client_socket[30], max_clients=30, activity, i, max_sd, valread;
	std::vector<std::pair<int, char*>> nicknames;
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
        server->nicknames.push_back({0,"test"});
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
        FD_SET(0, &server->read_fd);
        FD_SET(server->sock, &server->read_fd);

}
        void sel(Server *server) override{
std::cout<<__FUNCTION__<<std::endl;
/*for (auto itr = nicknames.begin(); itr != nicknames.end(); ++itr)
FD_SET(itr->first, &read_fd);
//                select(300, &peer->read_fd, NULL, NULL, NULL);

return this;
*/
};///<\param void  \return void
        void conn(Server *server) override{
std::cout<<__FUNCTION__<<std::endl;
 /*                       //peer->new_socket = accept(peer->sock,NULL,NULL);
                        //accepting connection
                        new_socket = accept(sock,NULL,NULL);
                        //char g[80]={"sos"};
                        //g="sos";
                        //read(peer->new_socket,g,1024);
                        nicknames.push_back({new_socket,"test"});
                        std::cout<< "New connection "<<new_socket<<std::endl;
                        //printf("New connection %s\n", peer->new_socket);
                        dprintf(new_socket,"welcome %d\n", new_socket);  
*/
};///<\param void  \return void
        void sendmes(Server *server) override{
std::cout<<__FUNCTION__<<std::endl;

#if 0

	for (auto itr2 = nicknames.begin(); itr2 != nicknames.end(); ++itr2)
                { 
			sd = itr2->first; 
			if (FD_ISSET(sd , &read_fd)) 
                        { 
				if ((valread = read(sd, buffer, 1024))) 
				/*{ 
                                        printf("Host disconnected %s \n" ,itr2->second); 
                                        close(peer->sd); 
					peer->nicknames.erase(itr2); 
                                	break;				
				} 
                                else
					*/
				{ 
	  				buffer[valread] = '\0';
					for (auto itr1 = nicknames.begin(); itr1 != nicknames.end(); ++itr1)
					dprintf(itr1->first,"%s says: %s\n",itr2->second, buffer);
					
                                 }  
                        } 
             
        	}


#endif
};///<\param void  \return void

};
