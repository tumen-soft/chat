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
//	Client * peer = new Server;

//class run{
//        public:
        //int from;
        //int to;
        //std::string buffer;
//        void operator()(auto *peer){  
template<class U>
U *run(U *peer){
//peer->addres.sin_family = AF_INET;
//peer->addres.sin_port = htons(PORT);
//peer->addres.sin_addr.s_addr = htonl(INADDR_ANY);


peer->init(peer);
#if 0
    int posix_handle = peer->sock;//fileno(::fopen("test.txt", "r"));

    __gnu_cxx::stdio_filebuf<char> filebuf(posix_handle, std::ios::in); // 1
    std::istream is(&filebuf); // 2

    std::string line;
    //getline(is, line);

#endif




peer->init1(peer);

//peer->conn(peer);


for(;;)
{
		peer->selinit(peer);
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
peer = new Server;
std::cin>>c;
//c=1;
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
		//p=check1();
		switch(check1()){
	case 0: {run((Server *)peer);break;}
        case 1: {run(peer);break;}
		}

        default:
                goto st;
}
}


