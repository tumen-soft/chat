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


export class AbstractPeer{
	public:
        AbstractPeer()=default;
	virtual void init()=0;
	virtual void init1()=0;
	virtual void selinit()=0;
	virtual void sel()=0;
	virtual void conn()=0;
	virtual void sendmes()=0;
	//AbstractPeer(){};
        AbstractPeer(int _sock, struct sockaddr_in _addres):sock(_sock), addres(_addres){}
        int sock;
        struct sockaddr_in addres;
        char buffer[MAXLINE]={0};
        fd_set read_fd={0};

	

};










//вводим определение клиента и сервера
export class ConcreteClient:public AbstractPeer{
        public:
	ConcreteClient(){};
	//Client(int _sock, struct sockaddr_in _addres):AbstractPeer(_sock, _addres){}
	//int sock;
        //struct sockaddr_in addres;
        //char buffer[MAXLINE]={0};
        //fd_set read_fd={0};
	//template<class T> T *conn(T *);
	//auto *init(auto *);
	//template<class T> T *sel(T *);
	//template<class T> T *init1(T *);
	//auto *selinit(auto *);
	//template<class T> T *sendmes(T *);

void init() override{
	sock=socket(AF_INET, SOCK_STREAM, 0);
	std::cout << typeid(this).name() << " fd " << sock << std::endl;
        
	return this;
}

void init1() override
        {
	std::cout<<"client start "  << std::endl;

	addres.sin_family = AF_INET;
        addres.sin_port = htons(PORT);
        addres.sin_addr.s_addr = inet_addr("127.0.0.1");

        connect(sock, (struct sockaddr*)&addres, sizeof(addres));
        //dprintf(peer->sock, s);
	//std::cout <<"test" <<std::endl;

        }


void selinit() override{

                memset(buffer, 0, sizeof(buffer));
                FD_ZERO(&read_fd);
                FD_SET(0, &read_fd);
                FD_SET(sock, &read_fd);

}






void sel() override{
//                select(300, &peer->read_fd, NULL, NULL, NULL);

	return this;
}



void conn() override{
read(sock, buffer, sizeof(buffer));dprintf(0, buffer);//}
return this;
}


void sendmes() override{

if(FD_ISSET(0, &read_fd)){read(0, buffer,sizeof(buffer));dprintf(sock, buffer);}  
//if(FD_ISSET(sock, &read_fd)){read(sock, buffer, sizeof(buffer));dprintf(0, buffer);}

return this;



}

};


