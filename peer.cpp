/*		server									
		  |
	initialisation of connection(bind(), listen())
		  |
		 loop (imfinite)
	     	  |
     ________\	 \|/ 
    |	     /	sets socket for listening.          /______________________________________|
    |		stdin, self and clients             \                                      |
    |		  |                                                                        |
    |		 \|/                                                                       |
    |	select() /return descriptor(s) if incomming, holds if nothing(waiting for)         |
    |	  |						|                                  |
    |	  |				    		|                                  |
    |	 \|/			                       \|/                                 |
    |	if select returns 	   for staitment(check for returned(select()) socket(s))   |	
    |	servers socket:  				|                                  |
    |	accept() new connection				|                                  |
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


(stdin is at descriptor 0) 


		client
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


//programm waits most of time



#include <peer.h>

void Server::run()
{

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
 

//std::cout<<"cli"<<std::endl;
}


//funkcii visokogo urovnya
/*
*/
template <class T1> void init(T1 peer){

        peer.addres.sin_family = AF_INET;
        peer.addres.sin_port = htons(PORT);
        peer.addres.sin_addr.s_addr = htonl(INADDR_ANY); 
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







template<class T>
struct OpNew
{
        OpNew(){
        T a = T();
        //init(&a);
        
	a.addres.sin_family = AF_INET;
        a.addres.sin_port = htons(PORT);
        a.addres.sin_addr.s_addr = htonl(INADDR_ANY); 



	a.run();
        //std::cout<<Create()<<std::endl;
        }
        //T Create()
        //{
          //      return T();
        //}

};



Client *Peers::run(enum PeerType chat){
Client peer;
switch (chat){
        case _Client:
	{
	struct OpNew<Client> type;
	//peer=new Client;
	break;
	}
        case _Server:
	{
	//peer=new Server;
	struct OpNew<Server> type;
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

peers->run(isserver);

}
