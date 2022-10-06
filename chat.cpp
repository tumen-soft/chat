/* Async multiclient net chat  by Vergun Denis <blu.eagle@mail.ru>
 * Four structures : Client, Server, Chat, Self. 
 * main() function. 
 * init() func.
 * Functions: creation create_socket(), closing socket close_socket(), 
 * connecting connect_to_socket(), initialisation bind_socket(), 
 * waiting for connection listen_socket() and accept_connection(), 
 * select_connection().
 */

//enum PeerType (55) consist of two members - Client & Server. There two state: Client or Server in programm.
//Client: functions resive messages(including from stdin), send messages to server, send nickname on start
//Server: functions registering(unregistering) clients, resive messages(including from stdin), send messages to all registered clients resive nick from client & register it
//ip scaner, avtomaticheskiy vibor regima raboti.

/*
                (begin)
                   |
                   |    
                  \|/   
        create threads   loop(256(ip 192.168.1.*))(check for connect)
                   |    (threads massive)
                   |
                  \|/
        wait threads ends
                   |
                   |
                  \|/   
        check for client(susess connection) loop  yes ----> end  (client)
                   |
                no |               
                  \|/
                server


*/


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
#define PORT 3111 
#define MAXLINE 1024
#define SOCKETERROR (-1)

namespace net {

typedef std::map<int,char*> nmap;
//enimeration for ip scaner
enum PeerType{
	Server,
	Client
};
char s[80];

using Func = void (*)(struct Self *self);


struct Net{
        int sock;
        struct sockaddr_in addres;
	char* message;
        char buffer[MAXLINE];
	fd_set read_fd;
	Func crt_sock, cls_sock, sel_conn;
	int run(void);
};

struct Client : virtual Net{
        ~Client(){printf("clidestroy");};
	Func cnt_to_sock;
	int run(void);
};

struct Server : virtual Net{
        Func bnd_sock, lsn_sock, acpt_conn;
	int run(void);
        int  sd, sd2, new_socket, client_socket[30], max_clients=30, activity, i, max_sd;
	int valread;
        nmap nicknames;
	

};


struct Peers{

        
        struct Server *server;
        struct Client *client;



};









struct Self : Server, Client{};




//funkcii visokogo urovnya

void create_socket(struct Self *self){
	self->sock=socket(AF_INET, SOCK_STREAM, 0);
}
void close_socket(struct Self *self){
	close(self->sock);
}
void connect_to_socket(struct Self * self){
	connect(self->sock, (struct sockaddr*)&self->Client::addres, sizeof(self->Client::addres));
}
void bind_socket(struct Self* self){
	bind(self->sock, (struct sockaddr*)&self->addres, sizeof(self->addres));
}
void listen_socket(struct Self * self){
	listen(self->sock, 300);
}
void accept_connection(struct Self * self){
	self->new_socket = accept(self->sock,NULL,NULL);
}
void select_connection(struct Self *self){
	select(300, &self->read_fd, NULL, NULL, NULL);
}


void init(struct Self *self){

	self->crt_sock=create_socket;
	self->cls_sock=close_socket;
	self->sel_conn=select_connection;
	self->addres.sin_family = AF_INET;
	self->addres.sin_port = htons(PORT);
	self->lsn_sock=listen_socket;
	self->bnd_sock=bind_socket;
	self->acpt_conn=accept_connection;
	self->cnt_to_sock=connect_to_socket;
        self->sel_conn=select_connection;
	self->Server::addres.sin_addr.s_addr = htonl(INADDR_ANY); 
	//comm->Client::addres.sin_addr.s_addr = inet_addr(CLIIP);
}

}
using namespace net;

struct Self _self;
struct Self *self=&_self;


#define STATIC_CHECK(expr, msg) \
                {\
  class ERROR_##msg {} ;\
  (void) CompileTimeChecker<(expr) != 0> (ERROR_##msg());\
}
template <bool> struct CompileTimeChecker
{
CompileTimeChecker(...);
};
template<> struct CompileTimeChecker<false> {
CompileTimeChecker(...){
self->Server::run();
}
};
template<> struct CompileTimeChecker<true> {   
CompileTimeChecker(...){
self->Client::run();
}
};


Server::run(){
	//socket creation
	self->crt_sock(self);
	//output socket file descriptor
	printf("server fd %i \n", self->sock);
	//initialisation
	self->bnd_sock(self);
	//waiting for connection
	self->lsn_sock(self);

	self->nicknames.insert({0,s});
	
        for(;;){
        FD_ZERO(&self->read_fd);      
        //comm->max_sd = comm->sock; 
      //  for (auto it1 = self->nicknames.begin(); it1!=self->nicknames.end();  ++it1)
    //std::cout << it1->first << "->" << it1->second << std::endl;  
	for (auto itr = self->nicknames.begin(); itr != self->nicknames.end(); ++itr)FD_SET(itr->first, &self->read_fd);
        FD_SET(self->sock, &self->read_fd);  
	//wait for connection/recive message
        self->sel_conn(self);
	
	if (FD_ISSET(self->sock, &self->read_fd)) 
                {	
			//acepting connection	
       			self->acpt_conn(self);
			self->acpt_conn(self);
			char g[80]={0};
			read(self->new_socket,g,1024);
			self->nicknames.insert({self->new_socket,g});
			printf("New connection %s\n",self->nicknames.find(self->new_socket)->second);
			dprintf(self->new_socket,"welcome %d\n",self->new_socket);  
                }
		//for (auto it2 = self->nicknames.begin(); it2!=self->nicknames.end();  ++it2)
    //std::cout << it2->first << "->" << it2->second << std::endl; 
		for (auto itr2 = self->nicknames.begin(); itr2 != self->nicknames.end(); ++itr2)
                { 
			self->sd = itr2->first; 
			if (FD_ISSET(self->sd , &self->read_fd)) 
                        { 
				if ((self->valread = read( self->sd , self->buffer, 1024))==0)//man read 
				{ 
                                        printf("Host disconnected %s \n" ,itr2->second); 
                                        close(self->sd); 
					self->nicknames.erase(itr2); 
                                	break;				
				} 
                                else
				{ 
	  				self->buffer[self->valread] = '\0';
					for (auto itr1 = self->nicknames.begin(); itr1 != self->nicknames.end(); ++itr1)
					dprintf(itr1->first,"%i says: %s\n",self->sd,self->buffer);
					
                                 }  
                        } 
                } 
        
	          //  for (auto it3 = self->nicknames.begin(); it3!=self->nicknames.end();  ++it3)
   // std::cout << it3->first << "->" << it3->second << std::endl; 

	}
        close(self->sd2);
	//closing socket
	self->cls_sock(self);









}
 



Client::run(){
	self->crt_sock(self); 
	printf("client fd %i \n", self->sock);
	self->cnt_to_sock(self);
	dprintf(self->sock,s);
        for(;;)
	{
        	memset(self->buffer, 0, sizeof(self->buffer));
        	FD_ZERO(&self->read_fd);
        	FD_SET(0, &self->read_fd);
        	FD_SET(self->sock, &self->read_fd);
        	self->sel_conn(self);
        	if (FD_ISSET(0, &self->read_fd)){read(0,self->buffer,sizeof(self->buffer));dprintf(self->sock, self->buffer);}  
        	if(FD_ISSET(self->sock, &self->read_fd)){read(self->sock, self->buffer, sizeof(self->buffer));dprintf(0,self->buffer);}
	}   
	self->cls_sock(self);




}




struct arg;
typedef struct arg args;
std::queue<args*> qq;
using namespace std;
struct arg{
	thread tid;
	int x;
	char y[256];
	enum PeerType isServer;
};

struct sockaddr_in addr;

  ///      args ar[256]={NULL,0,"127.0.0.1",Server};

void connector( args *arg) {
 //cout << id << "\n";

//ar.y="test";
args* q=(args*)arg;

//sprintf(q->y,"%s","test");
//q->y="test";
// struct sockaddr_in addr;
 int socke = socket(AF_INET, SOCK_STREAM, 0);
 
addr.sin_family = AF_INET;
 addr.sin_port = htons(PORT);
// pthread_create(&(tid[0]), NULL, &doSomeThing, NULL);
 //for(int i=202;i<204;i++){
 char a[256] = "192.168.1.";
 char b[10];
 //int c = i;
 sprintf(b,"%d",q->x);
 //a="192.168.1."
 strcat(a,b);
 //puts(a);
 addr.sin_addr.s_addr =  inet_addr(a);
 
 if(connect(socke, (struct sockaddr*)&addr, sizeof(addr))==0){sprintf(q->y,"%s",a);q->isServer=Client;}
    //return NULL;

}

 args ar[256]={};

/**
 * Spawns n threads
 */
void spawnThreads()
{
//	args ar[256]={NULL,0,"127.0.0.1",Server};

    //std::vector<thread> threads(256);
    // spawn n threads:
    for (int i = 0; i < 255; i++) {
        ar[i].x=i;
	ar[i].tid = thread(connector,&ar[i]);
	//enqueue(&ar[i]);
	qq.push(&ar[i]); 
   }

   // for (auto& th : threads) {
 	//for(int j=0;j<255;j++)if(ar[j].tid.joinable())ar[j].tid.join();
    //}


}





int main(){
//args ar[256]={NULL,0,"127.0.0.1",Server};

//        STATIC_CHECK(sizeof(AB) <= sizeof(A), Destination_Too_Narrow);


cout<< "wait..."<<endl;
spawnThreads();




enum  PeerType isserver=Server;
args *pclient;
//pclient=dequeue();
while(!qq.empty()){
pclient=qq.front();
if((pclient!=NULL)&&(pclient->tid.joinable())){
//if(tid[s]!=NULL)
pclient->tid.join();}
if(pclient)if(pclient->isServer==Client){isserver=Client;break;}
qq.pop();
}























  init(self);

//int y=self->Chat::run();
if(isserver==Client){
char a[256] = "192.168.1.";
 char b[10];
 //int c = i;
 sprintf(b,"%d",pclient->x);
 //a="192.168.1."
  strcat(a,b);
 self->Client::addres.sin_addr.s_addr = inet_addr(a);}

std::cout << "nick:";
std::cin >> s;

if(isserver){STATIC_CHECK(1, Destination_Too_Narrow);}else {STATIC_CHECK(0, Destination_Too_Narrow);}
}

