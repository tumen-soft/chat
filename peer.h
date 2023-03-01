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
//вводим определение клиента и сервера
class Client{
        public:
	int sock;
        struct sockaddr_in addres;
        char buffer[MAXLINE];
        fd_set read_fd;
	virtual Client *run(){return this;}	
	void conn(Client * peer);
	void init(auto peer);
	virtual void funct(){std::cout<<"pass"<<std::endl;};
	private:
	//int sock;

};


class Server:public Client{
	public:
        int  sd, sd2, new_socket, client_socket[30], max_clients=30, activity, i, max_sdi, valread;
        nmap nicknames;
	void funct () {std::cout<<"fail"<<std::endl;};
	Server *run(){return this;}
	void conn(Server *peer);
//using Client::socke;
        //sock=socket(AF_INET, SOCK_STREAM, 0);
        //std::cout<< typeid(this).name() << " fd " << sock << std::endl;
        //};

	private:
};
//class Peers:public Server{
//public:
	//Server::run;
	//using Server::run;
	//Client *b=new Client;
	Client * peer = new Server;
	Client * fun(auto*peer){return peer;};
	void run(auto * peer);
	auto *runn(){return peer->run();}
//private:
	//Client * peer = new Server;
//};
//Peers peers;
enum PeerType isserver=_Server;
