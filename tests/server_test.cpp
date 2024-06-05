#include <arpa/inet.h>  
#include "server.h" 
#include <vector>
int main(void){

	ServerPolicy *pol= new TCPServerPolicy();
	NetServer *ser_=new NetServer(pol);
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
	nicknames.push_back({0,"server"});
	for(;;){
	fd_set read_fd = selinit(sock);
	//перенести селект суда
        for (auto itr = nicknames.begin(); itr != nicknames.end(); ++itr)
        FD_SET(itr->first, &read_fd);
        //select(300, &read_fd, NULL, NULL, NULL);	
	read_fd=sel(read_fd);
        if (FD_ISSET(sock , &read_fd)) {    
	int new_socket= conn_(sock);
	nicknames.push_back({new_socket,"client"});}
	for (auto itr2 = nicknames.begin(); itr2 != nicknames.end(); ++itr2)
                {
			//std::cout<<itr2->first<<std::endl; 
                        
			int sd = itr2->first;
		        char buffer[MAXLINE]={0};///<Хранит сообщение 
                        if (FD_ISSET(sd , &read_fd)) 	
				{
				int valread; 
                                if (!(valread = read(sd, buffer, 1024))) 
                               { 
                                        printf("Host disconnected %s \n" ,itr2->second); 
                                        close(sd); 
                                        nicknames.erase(itr2); 
                                        break;                          
                                } 
                                else
                                       
                                { 
                                        buffer[valread] = '\0';
                                        for (auto itr1 = nicknames.begin(); itr1 != nicknames.end(); ++itr1)
                                        dprintf(itr1->first,"%s says: %s\n",itr2->second, buffer);
                                        
                                 }  
                        } 
            			 
                }


	}
return 0;
}
