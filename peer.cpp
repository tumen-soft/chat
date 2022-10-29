/*		server
		  |
		  |
	     	  |
     ________\	loop(without staitment(infinite)),
    |	     /	sets socket for listening.          /______________________________________|
    |		  |                                 \                                      |
    |		  |                                                                        |
    |		 \|/                                                                       |
    |	select() /return descriptor(s) if incomming, holds if nothing(waiting for)         |
    |	  |						|                                  |
    |	  |				    		|                                  |
    |	 \|/			                       \|/                                 |
    |	if select returns 	   for staitment(check for returned(select()) socket(s))   |	
    |	servers socketi:  				|                                  |
    |	accept new connection				|                                  |
    |		|		       		       \|/                                 |
    |		|		if socket in returned massive  read() from it              |
    |___________|			|			|                          |
					|			|                          |
				       \|/	      	       \|/                         |
				message not present: 	 message present:                  |
				send Host Disconnect	 send message to                   |
				erase from socket	 other sockets                     |
				from sockets massive		|			   |
					|_______________________|__________________________|



*/

#include "peer.h"

void Server::run(Server *peer)
{

	//socket creation
        peer->sock=socket(AF_INET, SOCK_STREAM, 0);
	//output socket file descriptor
	printf("server fd %i \n", peer->sock);
	//initialisation
        bind(peer->sock, (struct sockaddr*)&peer->addres, sizeof(peer->addres));
	//waiting for connection
        listen(peer->sock, 300);

	peer->nicknames.insert({0,s});
	
        for(;;){
        FD_ZERO(&peer->read_fd);      
        //comm->max_sd = comm->sock; 
      //  for (auto it1 = self->nicknames.begin(); it1!=self->nicknames.end();  ++it1)
    //std::cout << it1->first << "->" << it1->second << std::endl;  
	for (auto itr = peer->nicknames.begin(); itr != peer->nicknames.end(); ++itr)FD_SET(itr->first, &peer->read_fd);
        FD_SET(peer->sock, &peer->read_fd);  
	//wait for connection/recive message
        select(300, &peer->read_fd, NULL, NULL, NULL);
	
	if (FD_ISSET(peer->sock, &peer->read_fd)) 
                {	
			//acepting connection	
			peer->new_socket = accept(peer->sock,NULL,NULL);
			//close(peer->sock);
			peer->new_socket = accept(peer->sock,NULL,NULL);
			char g[80]={0};
			read(peer->new_socket,g,1024);
			peer->nicknames.insert({peer->new_socket,g});
			printf("New connection %s\n", peer->nicknames.find(peer->new_socket)->second);
			dprintf(peer->new_socket,"welcome %d\n", peer->new_socket);  
                }
		//for (auto it2 = self->nicknames.begin(); it2!=self->nicknames.end();  ++it2)
    //std::cout << it2->first << "->" << it2->second << std::endl; 
		for (auto itr2 = peer->nicknames.begin(); itr2 != peer->nicknames.end(); ++itr2)
                { 
			peer->sd = itr2->first; 
			if (FD_ISSET(peer->sd , &peer->read_fd)) 
                        { 
				if ((peer->valread = read(peer->sd, peer->buffer, 1024))==0) 
				{ 
                                        printf("Host disconnected %s \n" ,itr2->second); 
                                        close(peer->sd); 
					peer->nicknames.erase(itr2); 
                                	break;				
				} 
                                else
				{ 
	  				peer->buffer[peer->valread] = '\0';
					for (auto itr1 = peer->nicknames.begin(); itr1 != peer->nicknames.end(); ++itr1)
					dprintf(itr1->first,"%s says: %s\n",itr2->second, peer->buffer);
					
                                 }  
                        } 
                } 
        
	          //  for (auto it3 = self->nicknames.begin(); it3!=self->nicknames.end();  ++it3)
   // std::cout << it3->first << "->" << it3->second << std::endl; 

	}
        close(peer->sd2);
	//closing socket
	close(peer->sock);

//std::cout<<"ser"<<std::endl;
}
void Client::run(Client * peer)
{

        peer->sock=socket(AF_INET, SOCK_STREAM, 0);
        printf("client fd %i \n", peer->sock);
        connect(peer->sock, (struct sockaddr*)&peer->addres, sizeof(peer->addres));
        dprintf(peer->sock, s);
        for(;;)
        {
                memset(peer->buffer, 0, sizeof(peer->buffer));
                FD_ZERO(&peer->read_fd);
                FD_SET(0, &peer->read_fd);
                FD_SET(peer->sock, &peer->read_fd);
 		select(300, &peer->read_fd, NULL, NULL, NULL);
                if(FD_ISSET(0, &peer->read_fd)){read(0, peer->buffer,sizeof(peer->buffer));dprintf(peer->sock, peer->buffer);}  
                if(FD_ISSET(peer->sock, &peer->read_fd)){read(peer->sock, peer->buffer, sizeof(peer->buffer));dprintf(0, peer->buffer);}
        }   
        close(peer->sock);
 

//std::cout<<"cli"<<std::endl;
}


//funkcii visokogo urovnya
/*
*/
template <class T> void init(T *peer){

        peer->addres.sin_family = AF_INET;
        peer->addres.sin_port = htons(PORT);
        peer->addres.sin_addr.s_addr = htonl(INADDR_ANY); 
        //comm->Client::addres.sin_addr.s_addr = inet_addr(CLIIP);

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










void Peers::run(enum PeerType chat){
switch (chat){
        case _Client:
	{
	peers->client=new Client();
	init(peers->client);
	peers->client->run(peers->client);
	}
        case _Server:
	{
	peers->server=new Server();
	init(peers->server);
	peers->server->run(peers->server);
        }
 }
}




void check(){


//  init(self);

if(isserver==_Client){
char a[256] = "192.168.1.";
 char b[10];
 sprintf(b,"%d",pclient->x);
  strcat(a,b);

}

std::cout << "nick:";
std::cin >> s;

peers->run(isserver);
//init(peers->peer);
//peers->run();

}
