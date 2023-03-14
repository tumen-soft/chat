module;
#include <arpa/inet.h>  //inet_addr define
#include <stdio.h>  //printf()
#include <sys/socket.h> //socket(), connect(), bind(), listen(), accept(), select(); 
#include <unistd.h>  //close(), fread()
#include <string>  //string type
#include <map>
#include <cstring>
//#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <typeinfo>
#include <ext/stdio_filebuf.h>
#include <fstream>
//export module peer;
//using namespace std;
export module client;




#define MAXLINE 1024
#define PORT 3111 
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



}
