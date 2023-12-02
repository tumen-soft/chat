#include <arpa/inet.h>  
#include "client.h" 
//#include "policy.h"
#include <iostream>

int main(int argc, char* argv[]){

ClientPolicy *pol= new TCPClientPolicy();

Client *cli_ = new Client(pol);

cli_->createSocket();
if(argv[1])cli_->connectInit(argv[1]);
else cli_->connectInit();

cli_->selinit();
cli_->sel();///<\param void  \return void
cli_->conn();///<\param void  \return void
cli_->sendmes();///<\param void  \return void

return 0;
}
