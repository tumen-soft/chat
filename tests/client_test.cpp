#include <arpa/inet.h>  
#include "../include/client.h" 
#include "../include/policy.h"
#include <iostream>

int main(int argc, char* argv[]){

ClientPolicy *pol= new TCPClientPolicy();

Client *cli_ = new Client(pol);

//cli_->createSocket();

//if(argv[1])cli_->connectInit(argv[1]);
//else cli_->connectInit();
///std::cout<<argv[1]<<std::endl;

return 0;
}
