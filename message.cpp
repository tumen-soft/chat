module;
#include <arpa/inet.h>  //inet_addr define
#include <stdio.h>  //printf()
#include <sys/socket.h> //socket(), connect(), bind(), listen(), accept(), select(); 
#include <unistd.h>  //close(), fread()
#include <string>  //string type
#include <cstring>
#include <iostream>
#include <typeinfo>
#include <ext/stdio_filebuf.h>
#include <fstream>
export module message;
//using namespace std;

export import message:client;
export import message:server;
import ipscan;

        auto ser = [](auto *pee){return (Server *)pee;};
        auto cli = [](auto *pee){return pee;};

template <class FUN>
auto f(FUN fp, auto a)
{
        return fp(a);
}





class message{
	public:
	int from;
	int to;
	std::string buffer;
	void operator()(Server *peer){	
#if 0
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

#endif
		}




	void operator()(Client *peer){}


};










#define MAXLINE 1024
#define PORT 8080 


//typedef std::map<int,char*> nmap;
enum PeerType{
        _Server,
        _Client
};
//	Client * peer = new Server;


void run(auto *peer){
//peer->addres.sin_family = AF_INET;
//peer->addres.sin_port = htons(PORT);
//peer->addres.sin_addr.s_addr = htonl(INADDR_ANY);
message mess;
mess(peer);


#if 0
    int posix_handle = 2;//fileno(::fopen("test.txt", "r"));

    __gnu_cxx::stdio_filebuf<char> filebuf(posix_handle, std::ios::in); // 1
    istream is(&filebuf); // 2

    string line;
    //getline(is, line);

#endif



peer->init(peer);

    int posix_handle = peer->sock;//fileno(::fopen("test.txt", "r"));

    __gnu_cxx::stdio_filebuf<char> filebuf(posix_handle, std::ios::in); // 1
    std::istream is(&filebuf); // 2

    std::string line;
    //getline(is, line);









peer->init1(peer);

//peer->conn(peer);


for(;;)
{
		peer->selinit(peer);
		peer->sel(peer);

 		select(300, &peer->read_fd, NULL, NULL, NULL);

		if(FD_ISSET(peer->sock, &peer->read_fd))peer->conn(peer);



//for(;;)
}


//run()
}



enum choice {
    END, RUN
};
std::ostream& os = std::cout;

export void m(){
choice ch;
st:;
 //  std::cout<<"0.end"<<std::endl;
  // std::cout<<"1.run"<<std::endl;
int c,p;
Client * peer = new Server;
//std::cin>>c;
c=1;
ch=(int)c;
switch(ch){

        case END:
                return 0;
                break;

        case RUN:
		//std::cout<< "wait..."<<std::endl;
                spawnThreads();
                //wait();
                check();
		p=check1();
		switch(p){
	case 0: {run(f(ser, peer));break;}
        case 1: {run(f(cli, peer));break;}
		}

        default:
                goto st;
}
}


