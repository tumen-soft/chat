module;
#include <arpa/inet.h>  //inet_addr define
#include <sys/socket.h> //socket(), connect(), bind(), listen(), accept(), select(); 
#include <unistd.h>  //close(), fread()
#include <cstring>
#include <ext/stdio_filebuf.h>
export module server;
import <iostream>;
import <typeinfo>;
import <map>;
import client;
#define MAXLINE 1024
#define PORT 8080 
export Client *peer;
typedef std::map<int,char*> nmap;
#if 0	
		<сервер>									
		  |
	инициализация соединения функции bind(), listen()
		  |
		цикл (бесконечный)
	     	  |
     ________\	 \|/ 
    |	     / установка сокетов для прослушивания. /______________________________________|
    |		поток вывода, свой и клиентские     \                                      |
    |		  |                                                                        |
    |		 \|/                                                                       |
    |	<select() возврыщает массив дескрипторов     режим ожидания>  		           |
    |	  |	при записи вних		   	   	|                                  |
    |	  |				    		|                                  |
    |	 \|/			                       \|/                                 |
    |	если select возвращает 	     			|				   |	
    |	сокет сервера:  				|                                  |
    |	accept() нового соединения			|                                  |
    |		|		       		       \|/                                 |
    |		|		если select() возвращает дескрипторы  read() из них        |
    |___________|			|			|                          |
					|			|                          |
				       \|/	      	       \|/                         |
				сообшение отсутствует: 	 сообшение присутствует:           |
				send Host Disconnect	 send message to                   |
				erase from socket	 other sockets                     |
				from sockets massive		|			   |
					|_______________________|__________________________|


(stdin (поток ввода) на дескрипторе 0) 



#endif


export class Server:public Client{
	public:
        int sd,new_socket, client_socket[30], max_clients=30, activity, i, max_sd, valread;
        nmap nicknames;
};


template<> Server *Client::init1(Server* peer)
        {
        //char * ser = "Server fd ";
	std::cout << "server start" << std::endl;
	peer->addres.sin_family = AF_INET;
        peer->addres.sin_port = htons(PORT);
        peer->addres.sin_addr.s_addr = htonl(INADDR_ANY);

        bind(peer->sock, (struct sockaddr*)&peer->addres, sizeof(peer->addres));
        //waiting for connection
        listen(peer->sock, 300);
        //std::cout <<"test" <<std::endl;
        //peer->nicknames.insert({0,s});
        return peer;

	}






template<> Server *Client::sel(Server *peer){
//for (auto itr = peer->nicknames.begin(); itr != peer->nicknames.end(); ++itr)FD_SET(itr->first, &peer->read_fd);
return this;
}

void sendmessage(){
#if 0
	for (auto itr2 = nicknames.begin(); itr2 != nicknames.end(); ++itr2)
                { 
			sd = itr2->first; 
			if (FD_ISSET(sd , &read_fd)) 
                        { 
				if ((valread = read(sd, buffer, 1024))==0) 
				{ 
                                        printf("Host disconnected %s \n" ,itr2->second); 
                                        close(sd); 
					nicknames.erase(itr2); 
                                	break;				
				} 
                                else
				{ 
	  				buffer[valread] = '\0';
					for (auto itr1 = nicknames.begin(); itr1 != nicknames.end(); ++itr1)
					dprintf(itr1->first,"%s says: %s\n",itr2->second, buffer);
					
                                 }  
                        } 
             
        	}
#endif
}


template<> Server *Client::conn(Server *peer){
			//peer->new_socket = accept(peer->sock,NULL,NULL);
			//accepting connection
			peer->new_socket = accept(peer->sock,NULL,NULL);
			//char g[80]={0};
			//read(peer->new_socket,g,1024);
			//peer->nicknames.insert({peer->new_socket,g});
			std::cout<< "New connection"<<std::endl;
			//printf("New connection %s\n", peer->new_socket);
			dprintf(peer->new_socket,"welcome %d\n", peer->new_socket);  

return this;
}


