module;
#include <arpa/inet.h>  //inet_addr define
#include <sys/socket.h> //socket(), connect(), bind(), listen(), accept(), select(); 
#include <unistd.h>  //close(), fread()
#include <cstring>
#include <ext/stdio_filebuf.h>
import client;
export module server;
import <iostream>;
import <typeinfo>;
import <vector>;
//import client;
#define MAXLINE 1024
#define PORT 8080 
#if 0	
		<сервер>									
		  |
	инициализация соединения функции bind(), listen()
		  |
		цикл (бесконечный)
	     	  |
     ________\	 \|/ 
    |	     / установка сокетов для прослушивания. /______________________________________|
    |		поток вывода, свой и клиентские     \                                      |
    |		  |                                                                        |
    |		 \|/                                                                       |
    |	<select() возврыщает массив дескрипторов     режим ожидания>  		           |
    |	  |	при записи вних		   	   	|                                  |
    |	  |				    		|                                  |
    |	 \|/			                       \|/                                 |
    |	если select возвращает 	     			|				   |	
    |	сокет сервера:  				|                                  |
    |	accept() нового соединения			|                                  |
    |		|		       		       \|/                                 |
    |		|		если select() возвращает дескрипторы  read() из них        |
    |___________|			|			|                          |
					|			|                          |
				       \|/	      	       \|/                         |
				сообшение отсутствует: 	 сообшение присутствует:           |
				send Host Disconnect	 send message to                   |
				erase from socket	 other sockets                     |
				from sockets massive		|			   |
					|_______________________|__________________________|


(stdin (поток ввода) на дескрипторе 0) 



#endif

export class Server : public AbstractPeer{
	public:
	Server(){};
	//Server(int _sock, struct sockaddr_in _addres):AbstractPeer(_sock, _addres){}
	int sd,new_socket, client_socket[30], max_clients=30, activity, i, max_sd, valread;
	std::vector<std::pair<int, char*>> nicknames;


virtual void init() override{
        sock=socket(AF_INET, SOCK_STREAM, 0);
        std::cout << typeid(this).name() << " fd " << sock << std::endl;
        
        return this;
}








void init1()
        {
        //char * ser = "Server fd ";
	std::cout << "server start" << std::endl;
	addres.sin_family = AF_INET;
        addres.sin_port = htons(PORT);
        addres.sin_addr.s_addr = htonl(INADDR_ANY);

        bind(sock, (struct sockaddr*)&addres, sizeof(addres));
        //waiting for connection
        listen(sock, 300);
        //std::cout <<"test" <<std::endl;
        nicknames.push_back({0,"test"});
        return this;

	}



void selinit(){

                memset(buffer, 0, sizeof(buffer));
                FD_ZERO(&read_fd);
                FD_SET(0, &read_fd);
                FD_SET(sock, &read_fd);

}







void sel(){
for (auto itr = nicknames.begin(); itr != nicknames.end(); ++itr)
FD_SET(itr->first, &read_fd);
//                select(300, &peer->read_fd, NULL, NULL, NULL);

return this;
}




void conn(){
                        //peer->new_socket = accept(peer->sock,NULL,NULL);
                        //accepting connection
                        new_socket = accept(sock,NULL,NULL);
                        //char g[80]={"sos"};
                        //g="sos";
                        //read(peer->new_socket,g,1024);
                        nicknames.push_back({new_socket,"test"});
                        std::cout<< "New connection "<<new_socket<<std::endl;
                        //printf("New connection %s\n", peer->new_socket);
                        dprintf(new_socket,"welcome %d\n", new_socket);  

return this;
}











void sendmes(){
//#if 0
	for (auto itr2 = nicknames.begin(); itr2 != nicknames.end(); ++itr2)
                { 
			sd = itr2->first; 
			if (FD_ISSET(sd , &read_fd)) 
                        { 
				if ((valread = read(sd, buffer, 1024))) 
				/*{ 
                                        printf("Host disconnected %s \n" ,itr2->second); 
                                        close(peer->sd); 
					peer->nicknames.erase(itr2); 
                                	break;				
				} 
                                else
					*/
				{ 
	  				buffer[valread] = '\0';
					for (auto itr1 = nicknames.begin(); itr1 != nicknames.end(); ++itr1)
					dprintf(itr1->first,"%s says: %s\n",itr2->second, buffer);
					
                                 }  
                        } 
             
        	}
//#endif
return this;
}
};

//<D0><A1><D0><B8><D0><BD><D0><B3><D0><BB><D0><B5><D1><82><D0><BE><D0><BD> <D0><9C><D0><B0><D0><B9><D0><B5><D1><80><D1><81><D0><B0>
export class Singleton
{
public:
   static Singleton* Instance();
   //Client* instance = new Server(); 
   int data;
protected:
   Singleton(){};
   //Singleton(int _sock, struct sockaddr_in _addres):Server(_sock, _addres){};
private:
   static Singleton* _instance;
};

Singleton* Singleton::_instance = 0;
Singleton* Singleton::Instance() {
 if(_instance == 0)_instance = new Singleton;//(socket(AF_INET, SOCK_STREAM, 0),(struct sockaddr_in)0);
  return _instance;
}




//Singleton* s(new Singleton);
//Singleton* singleton0(Singleton::Instance());
//Singleton* singleton1(Singleton::Instance()->data = 20);

//export singleton0;
//export singleton1;



