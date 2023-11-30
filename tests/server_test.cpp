#include <arpa/inet.h>  
#include "server.h" 

int main(void){

	ServerPolicy *pol= new TCPServerPolicy();
	Server *ser_=new Server(pol);
	ser_->createSocket();
	ser_->connectInit();
return 0;
}
