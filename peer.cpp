/*		<сервер>									
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


//программа ждет большую часть времени

//ехать f1 min max => f2 min max  экономика

#include <peer.h>

void conn(Client * peer)
        {
        connect(peer->sock, (struct sockaddr*)&peer->addres, sizeof(peer->addres));
        dprintf(peer->sock, s);

        }
void conn(Server* peer)
        {

        bind(peer->sock, (struct sockaddr*)&peer->addres, sizeof(peer->addres));
        //waiting for connection
        listen(peer->sock, 300);

        peer->nicknames.insert({0,s});
        }

auto init(auto *peer){
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












//функция вообше для типов дынных и аргумент в частности
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


    int posix_handle = 2;//fileno(::fopen("test.txt", "r"));

    __gnu_cxx::stdio_filebuf<char> filebuf(posix_handle, std::ios::in); // 1
    istream is(&filebuf); // 2

    string line;
    //getline(is, line);





//peer->sock=socket(AF_INET, SOCK_STREAM, 0);
//std::cout<< typeid(peer).name() << " fd " << peer->sock << std::endl;
init(peer);
conn(peer);

/*
for(;;)
{

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



//for(;;)
}
*/

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
