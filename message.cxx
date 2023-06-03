#include <arpa/inet.h>  //inet_addr define
#include <sys/socket.h> //socket(), connect(), bind(), listen(), accept(), select(); 
#include <ext/stdio_filebuf.h>
#include <stdio.h>  //printf()
#include <unistd.h>  //close(), fread()
import <cstring>;
import client;
import server;
import ipscan;
import <iostream>;
#define MAXLINE 1024
#define PORT 8080 


//typedef std::map<int,char*> nmap;
enum PeerType{
        _Server,
        _Client
};



void run(auto* singleton){
singleton->init();
singleton->init1();
for(;;)
{
		singleton->selinit();

		singleton->sel();

		select(300, &singleton->read_fd, NULL, NULL, NULL);

		if(FD_ISSET(singleton->sock, &singleton->read_fd))singleton->conn();

		singleton->sendmes();

//for(;;)
}

};



enum choice {
    END, RUN
};
//std::ostream& os = std::cout;

int main(){
choice ch;
st:;
std::cout<<"0.end"<<std::endl;
std::cout<<"1.run"<<std::endl;
int c,p;
//peer = new Server;
std::cin>>c;
//c=1;
ch=(int)c;
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
		case 0: {run((new Server));break;}
		case 1: {run((new Client));break;}
		}

        default:
                goto st;
}
}


