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
int sock=createSocket();
struct sockaddr_in addres=connectInit(argv[1]);
//fd_set s=selinit(3);
std::cout<< connect_(sock, addres)<<std::endl;
conn(sock);
for(;;){
fd_set read_fd=selinit(sock);
fd_set read_fd1=sel(read_fd);

//conn(sock);
//std::cout<<"test"<<std::endl;
sendmes(read_fd1, sock);
}

return 0;
}
