/* Async net chat  by Vergun Denis <blu.eagle@mail.ru>
 * Four structures : Client, Server, Chat, Self. 
 * main() function. 
 * init() func.
 * Functions: create_socket(), close_socket(), connect_to_socket(),
 * bind_socket(), listen_socket(), accept_connection(), 
 * select_connection()  -  struct  interface.
 */

#include <arpa/inet.h>  //inet_addr define
#include <stdio.h>  //printf()
#include <sys/socket.h> //socket(), connect(), bind(), listen(), accept(), select(); 
#include <unistd.h>  //close(), fread()
#include <string>  //string type
#include <map>
#include <cstring>
#include <iostream>
#define PORT 3111 
#define MAXLINE 1024
#define SOCKETERROR (-1)

pthread_t tid[256];

typedef std::map<int,char*> nmap;

enum PeerType{
	server,
	client
};

using Func = void (*)(struct Self *self);

class Chat{
	public:
	Chat(){};
        int sock;
        struct sockaddr_in addres;
	char* message;
        char buffer[MAXLINE];
	fd_set read_fd;
	Func crt_sock, cls_sock, sel_conn;
	int run(void){
  	struct sockaddr_in addr;
	int socke = socket(AF_INET, SOCK_STREAM, 0);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	struct timeval timeout;
	timeout.tv_sec=3;
	timeout.tv_usec=0;
	//setsockopt(socke, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof timeout);

	//setsockopt(socke, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof timeout);
	int i;
	for(i=202;i<204;i++){
	char a[256] = "192.168.1.";
	char b[10];
	//int c = i;
	sprintf(b,"%d",i);
	//a="192.168.1."
	strcat(a,b);
	puts(a);
	addr.sin_addr.s_addr =  inet_addr(a);
	
	if(connect(socke, (struct sockaddr*)&addr, sizeof(addr))==0)return i;
	}
	return 0;
};
};
class Client : virtual public Chat{
        public:
	Client(){};
	~Client(){printf("clidestroy");};
	Func cnt_to_sock;
	int run(void){return 0;};
};






class Server : virtual public Chat{
	public:
	Server(){};
        Func bnd_sock, lsn_sock, acpt_conn;
	int run(void){return 0;};
        int  sd, sd2, new_socket, client_socket[30], max_clients=30, activity, i, max_sd;
	int valread;
        nmap nicknames;
	

};

class Self : public Server, public Client{};




//funkcii visokogo urovnya

void create_socket(class Self *self){
	self->sock=socket(AF_INET, SOCK_STREAM, 0);
}
void close_socket(class Self *self){
	close(self->sock);
}
void connect_to_socket(class Self * self){
	connect(self->sock, (struct sockaddr*)&self->Client::addres, sizeof(self->Client::addres));
}
void bind_socket(class Self* self){
	bind(self->sock, (struct sockaddr*)&self->addres, sizeof(self->addres));
}
void listen_socket(class Self * self){
	listen(self->sock, 10);
}
void accept_connection(class Self * self){
	self->new_socket = accept(self->sock,NULL,NULL);
}
void select_connection(class Self *self){
	select(10, &self->read_fd, NULL, NULL, NULL);
}


void init(class Self *self){

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



  class Self _self;
  class Self *self;
char s[80];
///PeerType isServer;
/*int main(){
self=&_self;
  init(self);
int y=self->Chat::run();
printf("%i\n",y);
char ip[10];
if (y>0){sprintf(ip,"%d",y);
char a[256] = "192.168.1.";
strcat(a,ip);
self->Client::addres.sin_addr.s_addr = inet_addr(a);}
bool isServer;
if (y)isServer=Client; else isServer=Server;

std::cout << "nick:";
std::cin >> s;

class chat<isServer> _chat;
}
*/

template <bool S> class chat
{
public:
chat(){
switch(S)
{
    case PeerType::server:
{
	self->crt_sock(self);
	printf("server fd %i \n", self->sock);
	self->bnd_sock(self);
	self->lsn_sock(self);

	self->nicknames.insert({0,s});
	
        for(;;){
        FD_ZERO(&self->read_fd);      
        //comm->max_sd = comm->sock; 
        for (auto it1 = self->nicknames.begin(); it1!=self->nicknames.end();  ++it1)
    std::cout << it1->first << "->" << it1->second << std::endl;  
	for (auto itr = self->nicknames.begin(); itr != self->nicknames.end(); ++itr)FD_SET(itr->first, &self->read_fd);
        FD_SET(self->sock, &self->read_fd);  
        self->sel_conn(self);
	if (FD_ISSET(self->sock, &self->read_fd)) 
                {
       			self->acpt_conn(self);
			self->acpt_conn(self);
			char g[80]={0};
			read(self->new_socket,g,1024);
			self->nicknames.insert({self->new_socket,g});
			printf("New connection %s\n",self->nicknames.find(self->new_socket)->second);
			dprintf(self->new_socket,"welcome %d\n",self->new_socket);  
                }
		for (auto it2 = self->nicknames.begin(); it2!=self->nicknames.end();  ++it2)
    std::cout << it2->first << "->" << it2->second << std::endl; 
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
        
	            for (auto it3 = self->nicknames.begin(); it3!=self->nicknames.end();  ++it3)
    std::cout << it3->first << "->" << it3->second << std::endl; 

	}
        close(self->sd2);
	self->cls_sock(self);

  }
    case PeerType::client:

{ 
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
}
}
};
template <int v> class Int2Type{
public:
enum{value=v};
};
void funswitch(auto _switch){

chat<_switch.value> _chat;

}

int check(int exp, const char *msg){
if (exp == SOCKETERROR){
	printf("%s\n",msg);
	exit(1);
}
return exp;
}

/*enum PeerType{
 server,
 client
};*/
struct arg;
typedef struct arg args;
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

struct arg{
	pthread_t tid;
	int x;
	char y[256];
	enum PeerType isServer;
};

Client cli;
struct sockaddr_in addr;
//args ar;

void* doSomeThing(void *arg)
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
 
 if(connect(socke, (struct sockaddr*)&addr, sizeof(addr))==0){sprintf(q->y,"%s",a);q->isServer=client;return 0;}
    return NULL;
}

int main(){
self=&_self;
    init(self);
  int y=self->Chat::run();
  

//enum PeerType isServer;
args ar[256]={NULL,"127.0.0.1",server};
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

//ar.y="test";
//printf("waiting for connection...");
//sleep(2);
//printf("%s\n",ar[0].y);
//if (ar.y!="test")isServer=client;
//enum PeerType isserver=server;
//int u;
//for(u=0;u<255;u++){
//if(ar[u].isServer==client){isserver=client;break;}
//}

switch(isserver)
{
    case client:
{
	printf("client...\n");

}
    case server:
{
	printf("server...\n");

}
}





printf("%i\n",y);
char ip[10];
if (y>0){sprintf(ip,"%d",y);
char a[256] = "192.168.1.";
strcat(a,ip);
self->Client::addres.sin_addr.s_addr = inet_addr(a);}
//isServer;
//Chat _chat;
if (y){Int2Type<PeerType::client> _switch;funswitch(_switch);}else{Int2Type<PeerType::server> _switch;funswitch(_switch);}



//Int2Type<PeerType::Server> a;

//std::cout << "nick:";
//std::cin >> s;

}

