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
export module peer:client;




#define MAXLINE 1024
#define PORT 8080 
//наследование функции гены мужчина

//вводим определение клиента и сервера
export class Client{
        public:
	int sock;
        struct sockaddr_in addres;
        char buffer[MAXLINE];
        fd_set read_fd;
	//void conn(Client * peer);
	//void init(auto *peer);
	Client *sel(Client*);
	auto *init1(auto *peer);
	auto *init(auto *peer);
	private:
	//int sock;

};


Client *conn(Client * peer)
        {
        connect(peer->sock, (struct sockaddr*)&peer->addres, sizeof(peer->addres));
        //dprintf(peer->sock, s);
        return peer;

        }
void connect1(Client *peer){
/*
 read(sock, buffer, sizeof(buffer));
	 dprintf(0, buffer);
*/

/*





       if(a==b)if(FD_ISSET(0, &read_fd)){read(0, buffer,sizeof(buffer));dprintf(sock, buffer);}  
               // if(FD_ISSET(sock, &read_fd)){read(sock, buffer, sizeof(buffer));dprintf(0, buffer);}

*/


}

export Client *Client::sel(Client *peer){
return this;
}

export auto *Client::init1(auto *peer){

	        memset(buffer, 0, sizeof(buffer));
                FD_ZERO(&read_fd);
                FD_SET(0, &read_fd);
                FD_SET(sock, &read_fd);

return this;




}
export auto *Client::init(auto *peer){
        sock=socket(AF_INET, SOCK_STREAM, 0);
        std::cout<< typeid(peer).name() << " fd " << sock << std::endl;
        return this;
}

