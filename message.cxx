#include <arpa/inet.h>  //inet_addr define
#include <sys/socket.h> //socket(), connect(), bind(), listen(), accept(), select(); 
#include <ext/stdio_filebuf.h>
#include <stdio.h>  //printf()
#include <unistd.h>  //close(), fread()
import <cstring>;

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
//template<class U>
void run(auto *peer){

peer->init(peer);
//       peer->sock=socket(AF_INET, SOCK_STREAM, 0);
  //     std::cout << typeid(peer).name() << " fd " << peer->sock << std::endl;

peer->init1(peer);


for(;;)
{
		//peer->selinit(peer);
                memset(peer->buffer, 0, sizeof(peer->buffer));
                FD_ZERO(&peer->read_fd);
                FD_SET(0, &peer->read_fd);
                FD_SET(peer->sock, &peer->read_fd);

		peer->sel(peer);

		select(300, &peer->read_fd, NULL, NULL, NULL);

		if(FD_ISSET(peer->sock, &peer->read_fd))peer->conn(peer);

		peer->sendmes(peer);

//for(;;)
}

//}//operator
 return peer;
//run()
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
		case 0: {run((Server *)((*singleton0).instance));break;}
		case 1: {run((*singleton1).instance);break;}
		}

        default:
                goto st;
}
}


