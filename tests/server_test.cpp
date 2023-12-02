#include <arpa/inet.h>  
#include "server.h" 

int main(void){

	ServerPolicy *pol= new TCPServerPolicy();
	Server *ser_=new Server(pol);
	ser_->createSocket();
	ser_->connectInit();
	ser_->connectInit("123");
	ser_->selinit();
return 0;
}
