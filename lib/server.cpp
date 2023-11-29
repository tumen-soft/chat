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
#include "server.h"
#include <iostream>;
#include <typeinfo>;
#include <vector>
#define MAXLINE 1024
#define PORT 8080 


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

	Server::Server(){};
#if 0
void Server::createSocket(){
        sock=socket(AF_INET, SOCK_STREAM, 0);
        std::cout << typeid(this).name() << " fd " << sock << std::endl;
        
}








void Server::connectInit(const char* addr) 
        {
	addres.sin_family = AF_INET;
        addres.sin_port = htons(PORT);
        addres.sin_addr.s_addr = htonl(INADDR_ANY);

        bind(sock, (struct sockaddr*)&addres, sizeof(addres));
        //waiting for connection
        listen(sock, 300);
        //std::cout <<"test" <<std::endl;
        nicknames.push_back({0,"test"});
        return this;

	}



void Server::selinit() {

                memset(buffer, 0, sizeof(buffer));
                FD_ZERO(&read_fd);
                FD_SET(0, &read_fd);
                FD_SET(sock, &read_fd);

}







void Server::sel() {
for (auto itr = nicknames.begin(); itr != nicknames.end(); ++itr)
FD_SET(itr->first, &read_fd);
//                select(300, &peer->read_fd, NULL, NULL, NULL);

return this;
}




void Server::conn() {
                        //peer->new_socket = accept(peer->sock,NULL,NULL);
                        //accepting connection
                        new_socket = accept(sock,NULL,NULL);
                        //char g[80]={"sos"};
                        //g="sos";
                        //read(peer->new_socket,g,1024);
                        nicknames.push_back({new_socket,"test"});
                        std::cout<< "New connection "<<new_socket<<std::endl;
                        //printf("New connection %s\n", peer->new_socket);
                        dprintf(new_socket,"welcome %d\n", new_socket);  

return this;
}











void Server::sendmes(){
//#if 0
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
return this;
}
#endif

