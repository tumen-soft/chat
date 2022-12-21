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
#define MAXLINE 1024
#define PORT 3111 
typedef std::map<int,char*> nmap;
//enimeration for ip scaner
enum PeerType{
        _Server,
        _Client
};
char s[80];
struct arg{
        std::thread tid;
        int x;
        char y[256];
        enum PeerType isServer;
};


typedef struct arg args;
std::queue<args*> qq;
struct sockaddr_in addr;


class Client{
        public:
	int sock;
        struct sockaddr_in addres;
        char buffer[MAXLINE];
        fd_set read_fd;
	//Client *running(){return this;};
	virtual void run();        
	char* c="cli";


};


class Server:public Client{
	public:
        int  sd, sd2, new_socket, client_socket[30], max_clients=30, activity, i, max_sd;
        int valread;
        nmap nicknames;
        void run();
	char * c = "ser";
};
class Peers: public Server{
public:
	using Client::run;
	using Server::run;
	Client *chAt=new Client();
	void run(enum PeerType chat);

};
Peers peers;
enum PeerType isserver=_Server;
