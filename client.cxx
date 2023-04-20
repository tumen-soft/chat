module;
#include <arpa/inet.h>  //inet_addr define
#include <sys/socket.h> //socket(), connect(), bind(), listen(), accept(), select(); 
#include <ext/stdio_filebuf.h>
#include <stdio.h>  //printf()
#include <unistd.h>  //close(), fread()
export module client;
import <iostream>;
import <typeinfo>;
import <cstring>;

#define MAXLINE 1024
#define PORT 8080 

#if 0
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



#endif






//вводим определение клиента и сервера
export class Client{
        public:
	int sock;
        struct sockaddr_in addres;
        char buffer[MAXLINE];
        fd_set read_fd;
	template<class T> T *conn(T *);
	auto *init(auto *);
	template<class T> T *sel(T *);
	template<class T> T *init1(T *);
	auto *selinit(auto *);
	template<class T> T *sendmes(T *);
};
auto *Client::init(auto *peer){
	peer->sock=socket(AF_INET, SOCK_STREAM, 0);
	std::cout << typeid(peer).name() << " fd " << sock << std::endl;
        
	return this;
}


template<> Client *Client::init1(Client *peer)
        {
	std::cout<<"client start "  << std::endl;

	peer->addres.sin_family = AF_INET;
        peer->addres.sin_port = htons(PORT);
        peer->addres.sin_addr.s_addr = inet_addr("127.0.0.1");

        connect(peer->sock, (struct sockaddr*)&peer->addres, sizeof(peer->addres));
        //dprintf(peer->sock, s);
	//std::cout <<"test" <<std::endl;
	return peer;

        }

auto *Client::selinit(auto *peer){

                memset(peer->buffer, 0, sizeof(peer->buffer));
                FD_ZERO(&peer->read_fd);
                FD_SET(0, &peer->read_fd);
                FD_SET(peer->sock, &peer->read_fd);

return peer;
}






template<> Client *Client::sel(Client *peer){
//                select(300, &peer->read_fd, NULL, NULL, NULL);

	return this;
}



template <> Client *Client::conn(Client *peer){
  //  int posix_handle = peer->sock;//fileno(::fopen("test.txt", "r"));

    //__gnu_cxx::stdio_filebuf<char> filebuf(posix_handle, std::ios::in); // 1
    //std::istream is(&filebuf); // 2
      //  char buff[1024] = { 0 };

    //char *line;
    //getline(is, line);
//	is >> buff;
// read(sock, buffer, sizeof(buffer));
	 //dprintf(0, buff);

//return this;
//#if 0
///if(FD_ISSET(0, &read_fd)){read(0, buffer,sizeof(buffer));dprintf(sock, buffer);}  
//if(FD_ISSET(sock, &read_fd)){
read(peer->sock, peer->buffer, sizeof(peer->buffer));dprintf(0, peer->buffer);//}
//#endif
return this;
}
template<>Client *Client::sendmes(Client *peer){



if(FD_ISSET(0, &peer->read_fd)){read(0, peer->buffer,sizeof(peer->buffer));dprintf(peer->sock, peer->buffer);}  
//if(FD_ISSET(sock, &read_fd)){read(sock, buffer, sizeof(buffer));dprintf(0, buffer);}

return this;



}




