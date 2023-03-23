module;
#include <arpa/inet.h>  //inet_addr define
#include <stdio.h>  //printf()
#include <sys/socket.h> //socket(), connect(), bind(), listen(), accept(), select(); 
#include <unistd.h>  //close(), fread()
#include <string>  //string type
#include <map>
#include <cstring>
#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <typeinfo>
#include <ext/stdio_filebuf.h>
#include <fstream>
//export module peer;
//using namespace std;
export module message:client;




#define MAXLINE 1024
#define PORT 8080 

/*
<клиент>
		  |
		  |
	connect() to server
		 \|/
	 send nick to server 
		 \|/
 _____________\	loop(infinite)
 |	      /	  |
 |		  |
 |		 \|/
 |	set sockets to listen(stdin and self (client))
 |		  |
 |		  |
 |		 \|/
 |	select() wait for messages(0 fd is stdin, and other fd is connection descriptor)
 |					|				|
 |					|				|
 |		      		       \|/			       \|/
 |				stdin - send messg to server	  recive mess from server
 |					|				|
 |______________________________________|_______________________________|



*/






//вводим определение клиента и сервера
export class Client{
        public:
	int sock;
        struct sockaddr_in addres;
        char buffer[MAXLINE];
        fd_set read_fd;
	Client *conn(Client *peer);
	auto *init(auto *peer);
	Client *sel(Client*);
	Client *init1(Client *peer);
	auto *selinit(auto *peer);
};
auto *Client::init(auto *peer){
        sock=socket(AF_INET, SOCK_STREAM, 0);
        std::cout<< typeid(peer).name() << " fd " << sock << std::endl;
        return this;
}


Client *Client::init1(Client * peer)
        {
	addres.sin_family = AF_INET;
        addres.sin_port = htons(PORT);
        addres.sin_addr.s_addr = inet_addr("127.0.0.1");

        connect(sock, (struct sockaddr*)&addres, sizeof(addres));
        //dprintf(peer->sock, s);
	//std::cout <<"test" <<std::endl;
	return peer;

        }

auto *Client::selinit(auto *peer){

                memset(buffer, 0, sizeof(buffer));
                FD_ZERO(&read_fd);
                FD_SET(0, &read_fd);
                FD_SET(sock, &read_fd);

return this;
}






export Client *Client::sel(Client *peer){
return this;
}



Client *Client::conn(Client *peer){

 read(sock, buffer, sizeof(buffer));
	 dprintf(0, buffer);


/*





       if(a==b)if(FD_ISSET(0, &read_fd)){read(0, buffer,sizeof(buffer));dprintf(sock, buffer);}  
*/


}

