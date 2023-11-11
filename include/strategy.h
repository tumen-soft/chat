#include "client.h"
//class Client;
#include <iostream>

class ClientStrategy{
        public:  
        ClientStrategy(){};
        virtual void createSocket(Client const& client)const = 0;
        //void connectInit_(const char* addr)override{connectInit(addr);};
        //void connectInit_()override{connectInit();};
        //void selinit();///<\param void  \return void
        ///void sel();///<\param void  \return void
        //void conn();///<\param void  \return void
        //void sendmes();///<\param void  \return void

};




class TestClientStrategy:public ClientStrategy{

public:        
TestClientStrategy(){}
void createSocket(Client const& client)const override{
//Client *clien=new Client();



std::cout<<client.sock;
};
//void createSocket(Client const& client)const override
//{}
/*
        client.sock=socket(AF_INET, SOCK_STREAM, 0);
        if(client.sock)
        std::cout << typeid(client).name() << " fd " << client.sock << std::endl;
        else
        std::cout << "creation socket error" << std::endl;





}
*/

};

