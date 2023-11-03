/**
 *\file message.h
 *\author Денис Вергун 
 *\brief  
 *\version
 *\date 27-06-2023
 *
 *
 */

#include <arpa/inet.h>  //inet_addr define
#include <ext/stdio_filebuf.h>
#include <stdio.h>  //printf()
#include <unistd.h>  //close(), fread()
#include <memory>
#include <cstring>;
//#include "client.h"
//#include "server.h"
#include "ipscan.h";
#include "abspeer.h";
#include <iostream>;
#define MAXLINE 1024
#define PORT 8080 


//typedef std::map<int,char*> nmap;
//enum PeerType{
//        _Server,
//        _Client
//};

//extern int main_(void);

void run(Peer* singleton){
singleton->createSocket_();
singleton->connectInit_("127.0.0.1");
for(;;)
{
		//singleton->selinit();

		//singleton->sel();

		//select(300, &singleton->read_fd, NULL, NULL, NULL);

		//if(FD_ISSET(singleton->sock, &singleton->read_fd))singleton->conn();

		//singleton->sendmes();

//for(;;)
}

};



enum choice {
    END, RUN
};
//std::ostream& os = std::cout;

int main_(){
choice ch;
st:;
std::cout<<"0.end"<<std::endl;
std::cout<<"1.run"<<std::endl;
int c,p;
//peer = new Server;
std::cin>>c;
//c=1;
ch=(choice)c;
switch(ch){

        case END:
                return 0;
                break;

        case RUN:
                spawnThreads();
                check();
		//--------------
		switch(check1()){
		//--------------
		case 0: {Peer* a = new Server_();run(a);break;}
		case 1: {Peer* b = new Client_();run(b);break;}
		}

        default:
                goto st;
}
}


