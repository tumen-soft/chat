#include <arpa/inet.h>  
#define DEBUG
#include "client.h" 
//#include "policy.h"
#include <iostream>




int main(int argc, char* argv[]){


//high level funct
/*
ClientPolicy *pol= new TCPClientPolicy();

Client *cli_ = new Client(pol);

cli_->createSocket();
//if(argv[1])cli_->connectInit(argv[1]);
//else 
cli_->connectInit();

cli_->selinit();
cli_->sel();///<\param void  \return void
cli_->conn();///<\param void  \return void
cli_->sendmes();///<\param void  \return void
*/



//low level funct
std::cout<<createSocket()<<std::endl;
struct sockaddr_in addr=connectInit("127.0.0.1");
fd_set s=selinit(3);
void sel();
void conn();
void sendmes();




return 0;
}
