/**
 *\file server.c 
 *\author Вергун Денис 
 *\brief  низкоуровневые функции для  класса сервера.
 *\version
 *\date 30-06-2023
 *
 *
 */

#include <arpa/inet.h>  //inet_addr 
#include <unistd.h>  //close(), fread()
#define MAXLINE 1024
#define PORT 8080 


void connectInit_(int sock) 
        {
	struct sockaddr_in addres;
	addres.sin_family = AF_INET;
        addres.sin_port = htons(PORT);
        addres.sin_addr.s_addr = htonl(INADDR_ANY);

        bind(sock, (struct sockaddr*)&addres, sizeof(addres));
        //waiting for connection
        listen(sock, 300);
        //std::cout <<"test" <<std::endl;
        //nicknames.push_back({0,"test"});
        //return this;

	}



fd_set selinit_(int sock) {
	//memset(buffer, 0, sizeof(buffer));
	fd_set read_fd;
        FD_ZERO(&read_fd);
        FD_SET(0, &read_fd);
        FD_SET(sock, &read_fd);
	return read_fd;
}







void sel_(fd_set read_fd) {
//for (auto itr = nicknames.begin(); itr != nicknames.end(); ++itr)
//FD_SET(itr->first, &read_fd);
select(300, &read_fd, NULL, NULL, NULL);
}




int conn_(int sock) {
                        //peer->new_socket = accept(peer->sock,NULL,NULL);
                        //accepting connection
                        int new_socket = accept(sock,NULL,NULL);
                        //char g[80]={"sos"};
                        //g="sos";
                        //read(peer->new_socket,g,1024);
                        ///nicknames.push_back({new_socket,"test"});
                        printf("New connection %i\n",new_socket);
                        //printf("New connection %s\n", peer->new_socket);
                        dprintf(new_socket,"welcome %d\n", new_socket);  

		return new_socket;
}


void sendmes_(){
#if 0
	for (auto itr2 = nicknames.begin(); itr2 != nicknames.end(); ++itr2)
                { 
			sd = itr2->first; 
			if (FD_ISSET(sd , &read_fd)) 
                        { 
				if ((valread = read(sd, buffer, 1024))) 
				/*{ 
                                        printf("Host disconnected %s \n" ,itr2->second); 
                                        close(peer->sd); 
					peer->nicknames.erase(itr2); 
                                	break;				
				} 
                                else
					*/
				{ 
	  				buffer[valread] = '\0';
					for (auto itr1 = nicknames.begin(); itr1 != nicknames.end(); ++itr1)
					dprintf(itr1->first,"%s says: %s\n",itr2->second, buffer);
					
                                 }  
                        } 
             
        	}
#endif
}
//с и с++  (один с)  разница между с и с++
