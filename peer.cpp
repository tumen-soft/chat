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
export module peer;



export std::ofstream out("/dev/stdout");
export std::ifstream in("/dev/stdin");


#define MAXLINE 1024
#define PORT 3111 
//наследование функции гены мужчина
pthread_t tid[256];


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
namespace fix{
struct arg{
        pthread_t tid;
        int x;
        char y[256];
        enum PeerType isServer;
};
};

typedef struct arg args;
args ar[256]={};
args *pclient;
std::queue<args*> qq;
struct sockaddr_in addr;
namespace fix{
typedef struct arg args;
args ar[256]={};
args *pclient;
std::queue<args*> qq;
struct sockaddr_in addr;
};



//вводим определение клиента и сервера
class Client{
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


class Server:public Client{
	public:
        int  sd, sd2, new_socket, client_socket[30], max_clients=30, activity, i, max_sdi, valread;
        nmap nicknames;
	//void conn(Server *peer);
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
	//Client * fun(auto*peer){return peer;};
	//void run(Server *peer);
	void run(auto *peer);
	//auto *runn(){return peer->run();}
//private:
	//Client * peer = new Server;
//};
//Peers peers;
enum PeerType isserver=_Server;
/*		<Ñ�ÐµÑ€Ð²ÐµÑ€>									
		  |
	Ð¸Ð½Ð¸Ñ†Ð¸Ð°Ð»Ð¸Ð·Ð°Ñ†Ð¸Ñ� Ñ�Ð¾ÐµÐ´Ð¸Ð½ÐµÐ½Ð¸Ñ� Ñ„ÑƒÐ½ÐºÑ†Ð¸Ð¸ bind(), listen()
		  |
		Ñ†Ð¸ÐºÐ» (Ð±ÐµÑ�ÐºÐ¾Ð½ÐµÑ‡Ð½Ñ‹Ð¹)
	     	  |
     ________\	 \|/ 
    |	     / ÑƒÑ�Ñ‚Ð°Ð½Ð¾Ð²ÐºÐ° Ñ�Ð¾ÐºÐµÑ‚Ð¾Ð² Ð´Ð»Ñ� Ð¿Ñ€Ð¾Ñ�Ð»ÑƒÑˆÐ¸Ð²Ð°Ð½Ð¸Ñ�. /______________________________________|
    |		Ð¿Ð¾Ñ‚Ð¾Ðº Ð²Ñ‹Ð²Ð¾Ð´Ð°, Ñ�Ð²Ð¾Ð¹ Ð¸ ÐºÐ»Ð¸ÐµÐ½Ñ‚Ñ�ÐºÐ¸Ðµ     \                                      |
    |		  |                                                                        |
    |		 \|/                                                                       |
    |	<select() Ð²Ð¾Ð·Ð²Ñ€Ñ‹Ñ‰Ð°ÐµÑ‚ Ð¼Ð°Ñ�Ñ�Ð¸Ð² Ð´ÐµÑ�ÐºÑ€Ð¸Ð¿Ñ‚Ð¾Ñ€Ð¾Ð²     Ñ€ÐµÐ¶Ð¸Ð¼ Ð¾Ð¶Ð¸Ð´Ð°Ð½Ð¸Ñ�>  		           |
    |	  |	Ð¿Ñ€Ð¸ Ð·Ð°Ð¿Ð¸Ñ�Ð¸ Ð²Ð½Ð¸Ñ…		   	   	|                                  |
    |	  |				    		|                                  |
    |	 \|/			                       \|/                                 |
    |	ÐµÑ�Ð»Ð¸ select Ð²Ð¾Ð·Ð²Ñ€Ð°Ñ‰Ð°ÐµÑ‚ 	     			|				   |	
    |	Ñ�Ð¾ÐºÐµÑ‚ Ñ�ÐµÑ€Ð²ÐµÑ€Ð°:  				|                                  |
    |	accept() Ð½Ð¾Ð²Ð¾Ð³Ð¾ Ñ�Ð¾ÐµÐ´Ð¸Ð½ÐµÐ½Ð¸Ñ�			|                                  |
    |		|		       		       \|/                                 |
    |		|		ÐµÑ�Ð»Ð¸ select() Ð²Ð¾Ð·Ð²Ñ€Ð°Ñ‰Ð°ÐµÑ‚ Ð´ÐµÑ�ÐºÑ€Ð¸Ð¿Ñ‚Ð¾Ñ€Ñ‹  read() Ð¸Ð· Ð½Ð¸Ñ…        |
    |___________|			|			|                          |
					|			|                          |
				       \|/	      	       \|/                         |
				Ñ�Ð¾Ð¾Ð±ÑˆÐµÐ½Ð¸Ðµ Ð¾Ñ‚Ñ�ÑƒÑ‚Ñ�Ñ‚Ð²ÑƒÐµÑ‚: 	 Ñ�Ð¾Ð¾Ð±ÑˆÐµÐ½Ð¸Ðµ Ð¿Ñ€Ð¸Ñ�ÑƒÑ‚Ñ�Ñ‚Ð²ÑƒÐµÑ‚:           |
				send Host Disconnect	 send message to                   |
				erase from socket	 other sockets                     |
				from sockets massive		|			   |
					|_______________________|__________________________|


(stdin (Ð¿Ð¾Ñ‚Ð¾Ðº Ð²Ð²Ð¾Ð´Ð°) Ð½Ð° Ð´ÐµÑ�ÐºÑ€Ð¸Ð¿Ñ‚Ð¾Ñ€Ðµ 0) 


		<ÐºÐ»Ð¸ÐµÐ½Ñ‚>
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


//Ð¿Ñ€Ð¾Ð³Ñ€Ð°Ð¼Ð¼Ð° Ð¶Ð´ÐµÑ‚ Ð±Ð¾Ð»ÑŒÑˆÑƒÑŽ Ñ‡Ð°Ñ�Ñ‚ÑŒ Ð²Ñ€ÐµÐ¼ÐµÐ½Ð¸
//ÐµÑ…Ð°Ñ‚ÑŒ f1 min max => f2 min max  Ñ�ÐºÐ¾Ð½Ð¾Ð¼Ð¸ÐºÐ°

//module;


//#include "peer.h"

//export module netchat;
//init Ñ�Ð¾Ð·Ð´Ð°Ð½Ð¸Ðµ Ñ�Ð¾ÐºÐµÑ‚Ð° ÐºÐ»Ð¸ÐµÐ½Ñ‚Ð°/Ñ�ÐµÑ€Ð²ÐµÑ€Ð°

Client *conn(Client * peer)
        {
        connect(peer->sock, (struct sockaddr*)&peer->addres, sizeof(peer->addres));
        dprintf(peer->sock, s);
        return peer;

        }
Server *conn(Server* peer)
        {

        bind(peer->sock, (struct sockaddr*)&peer->addres, sizeof(peer->addres));
        //waiting for connection
        listen(peer->sock, 300);

        peer->nicknames.insert({0,s});
        return peer;

	}

auto init(auto *peer){
	//Ð² Ð¿Ð¾Ð»Ðµ sock Ð¾Ð±ÑŒÐµÐºÑ‚Ð° peer Ð·Ð°Ð¿Ð¸Ñ�Ñ‹Ð²Ð°ÐµÑ‚Ñ�Ñ� Ñ„Ð°Ð¹Ð»Ð¾Ð²Ñ‹Ð¹ Ð´ÐµÑ�ÐºÑ€Ð¸Ð¿Ñ‚Ð¾Ñ€,
	//Ñ�Ð¾Ð·Ð´Ð°Ð½Ð½Ñ‹Ð¹ Ñ„ÑƒÐ½ÐºÑ†Ð¸ÐµÐ¹ socket().
	peer->sock=socket(AF_INET, SOCK_STREAM, 0);
	out<< typeid(peer).name() << " fd " << peer->sock << std::endl;
	return peer;
}

namespace fix{
/*
struct node{
        struct node *next;
        args *ar;

};

typedef struct node node_t;
//typedef struct arg args;
node_t * head = NULL;
node_t * tail = NULL;
void enqueue(args * ar){
node_t * newnode = malloc(sizeof(node_t));
newnode->ar = ar;
newnode->next=NULL;
if(tail==NULL){
head=newnode;
}else{
tail->next = newnode;
}
tail=newnode;
}


args * dequeue(){
if(head==NULL){
return NULL;
}else{
args *result = head->ar;
node_t *temp = head;
head=head->next;
if (head==NULL){tail==NULL;};
free(temp);
return result;
}
}



*/












//Ñ„ÑƒÐ½ÐºÑ†Ð¸Ñ� Ð²Ð¾Ð¾Ð±ÑˆÐµ Ð´Ð»Ñ� Ñ‚Ð¸Ð¿Ð¾Ð² Ð´Ñ‹Ð½Ð½Ñ‹Ñ… Ð¸ Ð°Ñ€Ð³ÑƒÐ¼ÐµÐ½Ñ‚ Ð² Ñ‡Ð°Ñ�Ñ‚Ð½Ð¾Ñ�Ñ‚Ð¸
void *doSomeThing(void *arg)
{
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
 
 if(connect(socke, (struct sockaddr*)&addr, sizeof(addr))==0){sprintf(q->y,"%s",a);q->isServer=_Client;return 0;}
    return NULL;
}


void spawnThreads()
{

/*
args ar[256]={NULL,0,"127.0.0.1",server};
///ar[0].isServer=server;
//args ar;
//printf("waiting for connection...");

int j=0;

for (int i=0;i<255;i++){
ar[j].x=i;
  pthread_create(&(tid[j]), NULL, &doSomeThing, &ar[j]);
  ar->tid=tid[j];
  enqueue(&ar[j]); 
j++;
}
*/
}


};

void connector( args *argz) {
args* q=(args*)argz;

 int socke = socket(AF_INET, SOCK_STREAM, 0);
 
addr.sin_family = AF_INET;
 addr.sin_port = htons(PORT);
 char a[256] = "192.168.1.";
 char b[10];
 sprintf(b,"%d",q->x);
 strcat(a,b);
 addr.sin_addr.s_addr =  inet_addr(a);
 
 if(connect(socke, (struct sockaddr*)&addr, sizeof(addr))==0){sprintf(q->y,"%s",a);q->isServer=_Client;}

}


//args ar[256]={};



void spawnThreads()
{

    for (int i = 0; i < 1; i++) {
        ar[i].x=i;
        ar[i].tid = std::thread(connector,&ar[i]);
        qq.push(&ar[i]); 
   }


}

//enum  PeerType isserver=_Server;
//args *pclient;



void wait()
{
while(!qq.empty()){
pclient=qq.front();
if((pclient!=NULL)&&(pclient->tid.joinable())){
pclient->tid.join();}
if(pclient)if(pclient->isServer==_Client){isserver=_Client;break;}
qq.pop();
}

}
/*
void run(Client *peer){

conn(init(peer));
//conn(peer);


}


*/

void sendmessage(){
	/*
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
*/
}


void connect1(Server *peer){
/*			new_socket = accept(sock,NULL,NULL);
			//accepting connection
			new_socket = accept(sock,NULL,NULL);
			char g[80]={0};
			read(new_socket,g,1024);
			nicknames.insert({new_socket,g});
			printf("New connection %s\n", nicknames.find(new_socket)->second);
			dprintf(new_socket,"welcome %d\n", new_socket);  
*/
}
void connect1(Client *peer){
/*
 read(sock, buffer, sizeof(buffer));
	 dprintf(0, buffer);
*/



}




void run(auto *peer){


//Server chA=Server();
//
//Server cha;
//Client ch=(Client)chA;

//b->addres.sin_family = AF_INET;
//   b->addres.sin_port = htons(PORT);
 //      b->addres.sin_addr.s_addr = htonl(INADDR_ANY);
//three t=three();

//t.run();

//Client *b ;


//std::cout<< b->c<<std::endl;
//std::cout<< dynamic_cast <Server*>(b)->c<<std::endl;




//(Client*)run()->run();
//Client::run();
//run();


//std::cout<<cHAt->c<<std::endl;
//std::cout<<dynamic_cast<Server*>(cHAt)->c<<std::endl;

//Client * peer = new Server;
//std::cout<<typeid(peer).name()<<std::endl;
//bp->run()->ru();
//dynamic_cast<Server*>(peer->run())->fast();
//if (chat!=_Server)(Client*)run();else run();
//if (chat==_Client) Client::run();
//std::cout<<typeid((Server*)(peer->run())).name()<<std::endl;//->fast();

        //peer->sock=socket(AF_INET, SOCK_STREAM, 0);


enum PEER{
	P6Client,
	P6Server

};



enum PEER chat;

chat='P6Client';
std::string a = "P6Client", b = typeid(peer).name();
//Server *ss=new Server();
//ss->run()->sockett();

/*
    int posix_handle = 2;//fileno(::fopen("test.txt", "r"));

    __gnu_cxx::stdio_filebuf<char> filebuf(posix_handle, std::ios::in); // 1
    istream is(&filebuf); // 2

    string line;
    //getline(is, line);


*/


//peer->sock=socket(AF_INET, SOCK_STREAM, 0);
//std::cout<< typeid(peer).name() << " fd " << peer->sock << std::endl;
init(peer);
conn(peer);


for(;;)
{
/*
		memset(buffer, 0, sizeof(buffer));
                FD_ZERO(&read_fd);
                FD_SET(0, &read_fd);
                FD_SET(sock, &read_fd);


if(a!=b)for (auto itr = nicknames.begin(); itr != nicknames.end(); ++itr)FD_SET(itr->first, &read_fd);

 		select(300, &read_fd, NULL, NULL, NULL);






       if(a==b)if(FD_ISSET(0, &read_fd)){read(0, buffer,sizeof(buffer));dprintf(sock, buffer);}  
               // if(FD_ISSET(sock, &read_fd)){read(sock, buffer, sizeof(buffer));dprintf(0, buffer);}


	if (FD_ISSET(sock, &read_fd)) 
	connect1(peer);


*/
//for(;;)
}


//run()
}

namespace fix{
void check(){
/*
enum PeerType isserver=server;
args *pclient;
pclient=dequeue();
while(pclient){
pclient=dequeue();
if((pclient!=NULL)&&(pclient->tid!=NULL)){
//if(tid[s]!=NULL)
pthread_join(pclient->tid,NULL);}
if(pclient)if(pclient->isServer==client){isserver=client;break;}
}
*/
}

};










void check(){

if(isserver==_Client){
char a[256] = "192.168.1.";
 char b[10];
 sprintf(b,"%d",pclient->x);
  strcat(a,b);

}

out << "nick: " << std::endl;;
in >> s;

//fun(peer)->funct();
//ofstream out("/dev/stdout");
//ifstream in("/dev/stdin");

out << "0.server"<<std::endl;
out << "1.client"<<std::endl;
int p;
in >> p;
//peer = new Server;

//run((Server *)peer);

switch(p){
	case 0: {run((Server*)peer);break;}
	case 1: {run(peer);break;}
}



//run(.runn());
}
export void spawn(){out<<"hello module"<<std::endl;}


enum choice {
    END, RUN
};

export int m(){
choice ch;
st:;
out<<"0.end"<<std::endl;
out<<"1.run"<<std::endl;
int c;
in>>c;
ch=(int)c;
switch(ch){

        case END:
                return 0;
                break;

        case RUN:
                out<< "wait..."<<std::endl;
                spawnThreads();
                wait();
                check();
        default:
                goto st;
}
}

