#include <arpa/inet.h>  
#include "../include/client.h" 
#include <iostream>

int main(int argc, char* argv[]){

Client *cli_ = new Client();

cli_->createSocket();

cli_->connectInit();

std::cout<<argv[1]<<std::endl;

return 0;
}
