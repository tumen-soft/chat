#include <arpa/inet.h>  
#include "server.h" 
#include <vector>
int main(void){

	ServerPolicy *pol= new TCPServerPolicy();
	Server *ser_=new Server(pol);
	ser_->createSocket();
	//ser_->connectInit();
	//ser_->connectInit("123");
	//ser_->selinit();
        //select(300, &ser_->read_fd, NULL, NULL, NULL);
	//ser_->sel();///<\param void  \return void
	//ser_->conn();///<\param void  \return void
	//ser_->sendmes();///<\param void  \return void
        std::vector<std::pair<int, char*>> nicknames;       	
	int sock=createSocket();
	connectInit_(sock); 
	nicknames.push_back({0,"test"});
	for(;;){
	fd_set read_fd = selinit(sock);
	//перенести селект суда
	for (auto itr = nicknames.begin(); itr != nicknames.end(); ++itr)
	FD_SET(itr->first, &read_fd);
	read_fd=sel_(read_fd);
	int new_socket= conn_(sock);
	nicknames.push_back({new_socket,"test"});
	}
return 0;
}
