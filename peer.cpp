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



#include <peer.h>

void Server::run()
{
	//std::cout<<c<<std::endl;
	//socket creation
        sock=socket(AF_INET, SOCK_STREAM, 0);
	//output socket file descriptor
	printf("server fd %i \n", sock);
	//initialisation
        bind(sock, (struct sockaddr*)&addres, sizeof(addres));
	//waiting for connection
        listen(sock, 300);

	nicknames.insert({0,s});
	
        for(;;){
        FD_ZERO(&read_fd);      
        //comm->max_sd = comm->sock; 
      //  for (auto it1 = self->nicknames.begin(); it1!=self->nicknames.end();  ++it1)
    //std::cout << it1->first << "->" << it1->second << std::endl;  
	for (auto itr = nicknames.begin(); itr != nicknames.end(); ++itr)FD_SET(itr->first, &read_fd);
        FD_SET(sock, &read_fd);  
	//wait for connection/recive message
        select(300, &read_fd, NULL, NULL, NULL);
	
	if (FD_ISSET(sock, &read_fd)) 
                {	
			//furst for scanner	
			new_socket = accept(sock,NULL,NULL);
			//accepting connection
			new_socket = accept(sock,NULL,NULL);
			char g[80]={0};
			read(new_socket,g,1024);
			nicknames.insert({new_socket,g});
			printf("New connection %s\n", nicknames.find(new_socket)->second);
			dprintf(new_socket,"welcome %d\n", new_socket);  
                }
		//for (auto it2 = self->nicknames.begin(); it2!=self->nicknames.end();  ++it2)
    //std::cout << it2->first << "->" << it2->second << std::endl; 
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
        
	          //  for (auto it3 = self->nicknames.begin(); it3!=self->nicknames.end();  ++it3)
   // std::cout << it3->first << "->" << it3->second << std::endl; 

	}
        close(sd2);
	//closing socket
	close(sock);
//return this;
//std::cout<<"ser"<<std::endl;
}
void Client::run()
{

        sock=socket(AF_INET, SOCK_STREAM, 0);
        printf("client fd %i \n", sock);
        connect(sock, (struct sockaddr*)&addres, sizeof(addres));
        dprintf(sock, s);
        for(;;)
        {
                memset(buffer, 0, sizeof(buffer));
                FD_ZERO(&read_fd);
                FD_SET(0, &read_fd);
                FD_SET(sock, &read_fd);
 		select(300, &read_fd, NULL, NULL, NULL);
                if(FD_ISSET(0, &read_fd)){read(0, buffer,sizeof(buffer));dprintf(sock, buffer);}  
                if(FD_ISSET(sock, &read_fd)){read(sock, buffer, sizeof(buffer));dprintf(0, buffer);}
        }   
        close(sock);
 
//return this;
//std::cout<<"cli"<<std::endl;
}


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


args ar[256]={};



void spawnThreads()
{

    for (int i = 0; i < 255; i++) {
        ar[i].x=i;
        ar[i].tid = std::thread(connector,&ar[i]);
        qq.push(&ar[i]); 
   }


}

//enum  PeerType isserver=_Server;
args *pclient;



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






class Base{
public:
        virtual Base *clone(){std::cout<<"base"<<std::endl;return this;}

char* c ="base";

};
class Derived:public Base{
public:

        Derived *clone(){std::cout<<"derived"<<std::endl;return this;}


char* c ="der";


};



class three: Server{
        public:
        //using Base::clone;
        //using Derived::clone;

void run(){

//Derived chat;// = Derived();
//Derived *d = &chat;
Client *b =new Server;


std::cout<< b->c<<std::endl;
std::cout<< dynamic_cast <Server*>(b)->c<<std::endl;

}};

/*three t=three();

t.run();*/








void Peers::run(enum PeerType chat){

//Server chA=Server();
//
//Server cha;
//Client ch=(Client)chA;

cHAt->addres.sin_family = AF_INET;
    cHAt->addres.sin_port = htons(PORT);
       cHAt->addres.sin_addr.s_addr = htonl(INADDR_ANY);
three t=three();

 t.run();



//chAt->running();

std::cout<<cHAt->c<<std::endl;
std::cout<<dynamic_cast<Server*>(cHAt)->c<<std::endl;

switch (chat){
        case _Client:
	{
	//chAt->run();
	//struct OpNew<Client> type;
	//std::cout<<(dynamic_cast<Derived*>(chA->r()))->c<<std::endl;
	//std::cout<<chA->c<<std::endl;
	//struct OpNew<Client> type;
	break;
	}
        case _Server:
	{
	//peer=new Server;
        //dynamic_cast<Server*>(chAt)->run();
	break;
	}
}

//init(peer);
//return peer;
}



void check(){

if(isserver==_Client){
char a[256] = "192.168.1.";
 char b[10];
 sprintf(b,"%d",pclient->x);
  strcat(a,b);

}

std::cout << "nick:";
std::cin >> s;

peers.run(isserver);

}
