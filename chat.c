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
#include <assert.h>
#include <string.h>
#include <pthread.h>
#define PORT 1311 
#define MAXLINE 1024
pthread_t tid[2];
/*
enum {
	server,
	client
}PeerType;
*/
void ConnectServer();
void ConnectClient();
typedef void (* Func)(struct Self *self);
struct Vtbl;

typedef struct {
	struct Vtbl const *vptr;


        int sock;
        struct sockaddr_in addres;
	char* message;
        char buffer[MAXLINE];
	fd_set read_fd;
	Func crt_sock, cls_sock, sel_conn;
} Peer;
static void _conn(Peer const * const me);
struct Vtbl {

    void (*conn)(Peer const * const me);
};


static void _conn(Peer const * const me) {
    assert(0); /* purely-virtual function should never be called */
}


void PeerCtr(Peer * const me) {
    static struct Vtbl const vtbl = { /* vtbl of the Shape class */
        &_conn
     };
     me->vptr = &vtbl; /* "hook" the vptr to the vtbl */
	
if ( me->sock=(socket(AF_INET, SOCK_STREAM, 0)))  {//man socket
}else{
printf("socket creation failed\n");}
   me->addres.sin_family = AF_INET;
   me->addres.sin_port = htons(PORT);

}



typedef struct{
	Peer peer;






	Func cnt_to_sock;
	//int run(void){return 0;};
}Client;


void ClientCtr(Client * const me){

    static struct Vtbl const vtbl = {&ConnectClient};
    PeerCtr(&me->peer);  
    me->peer.vptr = &vtbl;  
	//me->peer.addres.sin_addr.s_addr = inet_addr("127.0.0.1");

}


typedef struct {
        Peer peer;
	Func bnd_sock, lsn_sock, acpt_conn;
	//int run(void){return 0;};
        int  sd, sd2, new_socket, client_socket[30], max_clients, activity, i, max_sd;
	int valread;
        pthread_t tid[2];
 
	//nmap nicknames;
	

}Server;



ServerCtr(Server * const me){

    static struct Vtbl const vtbl = {&ConnectServer};
    PeerCtr(&me->peer);
    me->peer.vptr = &vtbl;
	me->peer.addres.sin_addr.s_addr = htonl(INADDR_ANY);
//me->max_clients=30;



 }
















//typedef struct {Server server; Client client;}Self;
void ConnectServer(){printf("starting server at ...(ip)\n");}
void ConnectClient(){printf("starting client at ...(ip)\n");}


void ConnectToChat(Peer const * const me) {
    (*me->vptr->conn)(me);
}

void* doSomeThing(void *arg)
{
    unsigned long i = 0;
    pthread_t id = pthread_self();

    if(pthread_equal(id,tid[0]))
    {
        printf("thread");
    }
    else
    {
        printf("\n Second thread processing\n");
    }


    return NULL;
}

enum PT{
        server,
        client
};
int main(){

enum PT isServer;

        struct sockaddr_in addr;
        int socke = socket(AF_INET, SOCK_STREAM, 0);
        addr.sin_family = AF_INET;
        addr.sin_port = htons(PORT);
        pthread_create(&(tid[0]), NULL, &doSomeThing, NULL);
	for(int i=202;i<204;i++){
        char a[256] = "192.168.1.";
        char b[10];
        //int c = i;
        sprintf(b,"%d",i);
        //a="192.168.1."
        strcat(a,b);
        puts(a);
        addr.sin_addr.s_addr =  inet_addr(a);
        
        if(connect(socke, (struct sockaddr*)&addr, sizeof(addr))==0)isServer=client; else isServer=server;

}

switch(isServer)
{
    case client:
{

Client cli;
ClientCtr(&cli);
ConnectToChat(&cli);
cli.peer.addres.sin_addr.s_addr = addr.sin_addr.s_addr;
connect(cli.peer.sock, (struct sockaddr*)&cli.peer.addres, sizeof(cli.peer.addres));
	//cli.peer.sock=socke;
	//read(cli.peer.sock, cli.peer.buffer, sizeof(cli.peer.buffer));
        //printf("server: %s\n",cli.peer.buffer);
	for(;;){
	memset(cli.peer.buffer, 0, sizeof(cli.peer.buffer));
	FD_ZERO(&cli.peer.read_fd);
        FD_SET(0, &cli.peer.read_fd);
        FD_SET(cli.peer.sock, &cli.peer.read_fd);
        select(10, &cli.peer.read_fd, NULL, NULL, NULL);
	if(FD_ISSET(0, &cli.peer.read_fd)){
	read(0,cli.peer.buffer,sizeof(cli.peer.buffer));
	dprintf(cli.peer.sock,cli.peer.buffer);}  
        if(FD_ISSET(cli.peer.sock, &cli.peer.read_fd)){
	read(cli.peer.sock, cli.peer.buffer, sizeof(cli.peer.buffer));
	printf("server: %s\n", cli.peer.buffer);}
	}        
	close(cli.peer.sock);


return 0;
}



case server:
{


Server ser;
ServerCtr(&ser);
ConnectToChat(&ser);


ser.max_clients=10;
ser.sd=0;
ser.sd2=0;
        bind(ser.peer.sock, (struct sockaddr *)&ser.peer.addres, sizeof(ser.peer.addres));
        listen(ser.peer.sock, 10);
        for (int i = 0; i < ser.max_clients; i++) ser.client_socket[i] = -1;  

        for(;;){
        FD_ZERO(&ser.peer.read_fd);      
        ser.max_sd = ser.peer.sock; 
	ser.client_socket[0]=0;
	for (int i = 0 ; i < ser.max_clients ; i++){ 
        ser.sd = ser.client_socket[i]; 
        if(ser.sd >= 0)FD_SET( ser.sd , &ser.peer.read_fd); 
        if(ser.sd > ser.max_sd)ser.max_sd = ser.sd;}  
        //FD_SET(0, &ser.peer.read_fd);
        FD_SET(ser.peer.sock, &ser.peer.read_fd);  
        select(ser.max_clients, &ser.peer.read_fd, NULL, NULL, NULL);
	if (FD_ISSET(ser.peer.sock, &ser.peer.read_fd)){ 
	while((ser.new_socket = accept(ser.peer.sock,NULL,NULL))<=0){}
	while((ser.new_socket = accept(ser.peer.sock,NULL,NULL))<=0){}	
	printf("New connection %d\n",ser.new_socket);	
	dprintf(ser.new_socket,"welcome %d\n",ser.new_socket);	
	puts("Welcome message sent."); 
	for (int j = 0; j < ser.max_clients; j++) 
	{ 
	if( ser.client_socket[j] == -1) 
	{ 
	ser.client_socket[j] = ser.new_socket; 
	printf("Adding to list of sockets as %d\n" , j); 
	break; 
	} 
	} 
	} 

		for (int k = 0; k < ser.max_clients; k++) 
		{ 
			//ser.sd = ser.client_socket[k]; 
			if (FD_ISSET( ser.client_socket[k] , &ser.peer.read_fd )) 
			{ 
				if ((ser.valread = read(ser.client_socket[k], &ser.peer.buffer, sizeof(ser.peer.buffer))) == 0)//man read 
				{ 
				
					printf("Host disconnected %d \n" , ser.client_socket[k]); 
					close( ser.client_socket[k] ); 
					ser.client_socket[k] = -1; 
				} 
			else
				{ 
			//ser.peer.buffer[ser.valread] = '\0';  
         		for ( int l = 0 ; l < ser.max_clients ; l++){if(ser.client_socket[l]>=0)dprintf(ser.client_socket[l],"%i says: %s\n",ser.client_socket[k], ser.peer.buffer);

			//printf("%i says: %s\n",ser.client_socket[k],ser.peer.buffer);}
		        //if (l==ser.max_clients-1)printf("%s\n",ser.peer.buffer);
}
				}
			} 
		} 
	}
	close(ser.sd2);
	close(ser.peer.sock);

}
}

return 0;	
}












/*
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
*/
	//}
	//close(ser.sd2);
	//close(ser.peer.sock);










//Server ser1;
//ServerCtr(&ser1);
//ConnectToChat(&ser1);


/*init(self);
int y=self->Chat::run();
printf("%i\n",y);
char ip[10];
if (y>0){sprintf(ip,"%d",y);
char a[256] = "192.168.1.";
strcat(a,ip);
self->Client::addres.sin_addr.s_addr = inet_addr(a);}
PeerType isServer;
if (y)isServer=Client; else isServer=Server;
char s[80];
std::cout << "nick:";
std::cin >> s;


switch(isServer)
{
    case Server:
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
    case Client:
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
*/
//return 0;
//}

