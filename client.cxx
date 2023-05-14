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
	Client(int _sock, struct sockaddr_in _addres, char _buffer[MAXLINE], fd_set _read_fd):sock(_sock), addres(_addres), buffer(_buffer), read_fd(_read_fd){}
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
read(peer->sock, peer->buffer, sizeof(peer->buffer));dprintf(0, peer->buffer);//}
return this;
}
template<>Client *Client::sendmes(Client *peer){



if(FD_ISSET(0, &peer->read_fd)){read(0, peer->buffer,sizeof(peer->buffer));dprintf(peer->sock, peer->buffer);}  
//if(FD_ISSET(sock, &read_fd)){read(sock, buffer, sizeof(buffer));dprintf(0, buffer);}

return this;



}




