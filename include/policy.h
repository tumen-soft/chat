#include "client.h"
//class Client;
#include <iostream>

class ClientPolicy{
        public:  
        ClientPolicy();
        virtual void createSocket(Client *client)const = 0;
        //void connectInit_(const char* addr)override{connectInit(addr);};
        //void connectInit_()override{connectInit();};
        //void selinit();///<\param void  \return void
        ///void sel();///<\param void  \return void
        //void conn();///<\param void  \return void
        //void sendmes();///<\param void  \return void

};




class TCPClientPolicy:public ClientPolicy{

public:        
TCPClientPolicy();
void createSocket(Client *client)const override{
        client->sock=socket(AF_INET, SOCK_STREAM, 0);
        if(client->sock)
        std::cout << typeid(client).name() << " fd " << client->sock << std::endl;
        else
        std::cout << "creation socket error" << std::endl;
}
/*
void connectInit(const char* addr){
        addres.sin_family = AF_INET;
        addres.sin_port = htons(PORT);
        addres.sin_addr.s_addr = inet_addr(addr);
        connect(sock, (struct sockaddr*)&addres, sizeof(addres));
}
void connectInit(){
        std::cout << "no ip addres specified" << std::endl;
}

void selinit(){
        memset(buffer, 0, sizeof(buffer));
        FD_ZERO(&read_fd);
        FD_SET(0, &read_fd);
        FD_SET(sock, &read_fd);
}
void sel(){
//                select(300, &peer->read_fd, NULL, NULL, NULL);
        return this;
}



void conn(){
        read(sock, buffer, sizeof(buffer));dprintf(0, buffer);
        return this;
}
void sendmes(){
        if(FD_ISSET(0, &read_fd)){read(0, buffer,sizeof(buffer));dprintf(sock, buffer);}  
        //if(FD_ISSET(sock, &read_fd)){read(sock, buffer, sizeof(buffer));dprintf(0, buffer);}
        return this;
}
*/


};


class UDPClientPolicy:public ClientPolicy{

public:        
UDPClientPolicy();
void createSocket(Client *client)const override{ 
	client->sock=socket(AF_INET, SOCK_DGRAM, 0);
        if(client->sock)
        std::cout << typeid(client).name() << " fd " << client->sock << std::endl;
        else
        std::cout << "creation socket error" << std::endl;

}


};




