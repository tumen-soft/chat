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
export module server;
import client;
char s[80];
#define MAXLINE 1024
#define PORT 3111 
//наследование функции гены мужчина
typedef std::map<int,char*> nmap;
enum PeerType{
        _Server,
        _Client
};
class Server:public Client
{
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
	//Client * fun(auto*peer){return peer;};
	//void run(Server *peer);
	//auto *runn(){return peer->run();}
//private:
	//Client * peer = new Server;
//};
//Peers peers;


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

Server *conn(Server* peer)
        {

        bind(peer->sock, (struct sockaddr*)&peer->addres, sizeof(peer->addres));
        //waiting for connection
        listen(peer->sock, 300);

        peer->nicknames.insert({0,s});
        return peer;

	}

void sendmessage(){
/*	for (auto itr2 = nicknames.begin(); itr2 != nicknames.end(); ++itr2)
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
