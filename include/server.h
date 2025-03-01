/**
 *\file server.h
 *\author ИП Вергун Д.Н. 
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
#include "chat.h"
#include <iostream>
#include <typeinfo>
#include <vector>
#define MAXLINE 1024
#define PORT 8080 

extern "C"{
int createSocket(void);
void connectInit_(int sock);
fd_set selinit(int sock);
fd_set sel(fd_set read_fd);
int conn_(int sock);
void sendmes_();
}


class TCPE;
class E;
class С;
class E:public F{
        public:  
        E(){};
        virtual void _createSocket() = 0;
        //virtual void connectInit(const char* addr) = 0;
        virtual void connectInit(С *server) = 0;
        virtual void selinit(С *server) = 0;///<\param void  \return void
        virtual void sel(С *server)=0;///<\param void  \return void
        virtual void conn(С *server)=0;///<\param void  \return void
        virtual void sendmes(С *server)=0;///<\param void  \return void

};



//typedef void (E::*func)(Server*);
class С: public А{//Сетевой сервер
	public:
	С(){};
	//void foo(func);
	С(E *policy):serv(policy){}
        void соединение() override{}

	void создатьСокет()override{
        //foo(&E::создатьСокет);
        serv->_createSocket();
	}; 
        //void connectInit(const char* addr) override{
	//foo(&Server::connectInit);
	//};
        void connectInit() override{
        //foo(&E::connectInit);
        };
        void selinit() override{
        //foo(&E::selinit);
        }; 
        void sel() override{
	//foo(&E::sel);
	};
        void conn() override{
	//foo(&E::conn);
	}; 
        void sendmes() override{
	//foo(&E::sendmes);
	};
	E *serv;
};
class TCPE:public E{

public:        
TCPE(){};
void _createSocket() override{
        //sock=(socket(AF_INET, SOCK_STREAM, 0));
        //if(sock)
        //std::cout <<"TCP " <<typeid(server).name() << " fd " << sock << std::endl;
        //else
        //std::cout << "creation socket error" << std::endl;

	Trace((stderr, __FUNCTION__));
	std::cout<<std::endl;
	sock=createSocket();

}
void connectInit(С *server) override{
//        std::cout << "no ip addres specified" << std::endl;
//std::cout<<__FUNCTION__<<std::endl;

        ///server->addres.sin_family = AF_INET;
        ///server->addres.sin_port = htons(PORT);
        ///server->addres.sin_addr.s_addr = htonl(INADDR_ANY);

        ///bind(server->sock, (struct sockaddr*)&server->addres, sizeof(server->addres));
        //waiting for connection
        ///listen(server->sock, 300);
        //std::cout <<"test" <<std::endl;
        //server->nicknames.push_back({0,"test"});
	//server->new_socket = accept(server->sock,NULL,NULL);
	//read(server->new_socket, server->buffer, 1024);
        //std::cout<<server->buffer<<std::endl;;  

	 Trace((stderr, __FUNCTION__));
        std::cout<<std::endl;
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

void selinit(С *server) override{
//std::cout<<__FUNCTION__<<std::endl;
	/////memset(server->buffer, 0, sizeof(server->buffer));
        /////FD_ZERO(&server->read_fd);
        //FD_SET(0, &server->read_fd);
        //FD_SET(server->sock, &server->read_fd);

	 Trace((stderr, __FUNCTION__));
        std::cout<<std::endl;
}
        void sel(С *server) override{
//std::cout<<__FUNCTION__<<std::endl;
////server->nicknames.push_back({0,"me"});

///for (auto itr = server->nicknames.begin(); itr != server->nicknames.end(); ++itr)
///FD_SET(itr->first, &server->read_fd);
               // select(300, &server->read_fd, NULL, NULL, NULL);

};///<\param void  \return void
        void conn(С *server) override{
//std::cout<<__FUNCTION__<<std::endl;
			///server->new_socket = accept(server->sock,NULL,NULL);
                        //accepting connection
                        //new_socket = accept(sock,NULL,NULL);
                        //char g[80]={"sos"};
                        //g="sos";
                        //read(peer->new_socket,g,1024);
                        ////server->nicknames.push_back({server->new_socket,"test"});
                        ////std::cout<< "New connection "<<server->new_socket<<std::endl;
                        //printf("New connection %s\n", server->new_socket);
                        ////dprintf(server->new_socket,"welcome %d\n", server->new_socket);  
        std::cout<<std::endl;
};///<\param void  \return void



void sendmes(С *server) override{
std::cout<<_valread()<<std::endl;

/*
	for (auto itr2 = server->nicknames.begin(); itr2 != server->nicknames.end(); ++itr2)
                {//std::cout<<itr2->first; 
			server->sd = itr2->first;
			//std::cout<<itr2->first<<std::endl; 
			if (FD_ISSET(server->sd , &server->read_fd)) 
                        {//std::cout<<"test"; 
				(server->valread)=(read(server->sd, server->buffer, 1024)); 
				if (server->valread)
				//{ 
                                        printf("Host disconnected %s \n" ,itr2->second); 
                                        close(peer->sd); 
					peer->nicknames.erase(itr2); 
                                	break;				
				} 
                                else
					//
				{ 
	  				server->buffer[server->valread] = '\0';
					for (auto itr1 = server->nicknames.begin(); itr1 != server->nicknames.end(); ++itr1)
					dprintf(itr1->first,"%s says: %s\n",itr2->second, server->buffer);
					
                                 }  
                        } 
            
        	}

 Trace((stderr, __FUNCTION__));
        std::cout<<std::endl;*/
};///<\param void  \return void

};
