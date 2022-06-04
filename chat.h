/*

class CommChannel{
	public:
    CommChannel(){
 if ( SetSocket(socket(AF_INET, SOCK_STREAM, 0)))  {//man socket
}else{
  printf("socket creation failed");
  }
    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    }
    Peer peer;    
    fd_set read_fd;
    char* message;
    int  sd, sd2;
    struct sockaddr_in servaddr;
    virtual void run()=0;
    char buffer[MAXLINE];
int new_socket, client_socket[30], max_clients = 30, activity, i, valread; 
int max_sd;
	int GetSocket(){return name;}
	int SetSocket(int sock){name=sock;return name;}
	private:
    int name;
}* commchannel;

class Client: public CommChannel{
    public:
    Client(){
        servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
}
    void run()
    {
    connect(GetSocket(), (struct sockaddr*)&servaddr, sizeof(servaddr));
	for(;;){
	memset(buffer, 0, sizeof(buffer));
	FD_ZERO(&read_fd);
        FD_SET(0, &read_fd);
        FD_SET(GetSocket(), &read_fd);
        select(10, &read_fd, NULL, NULL, NULL);
	if (FD_ISSET(0, &read_fd)){read(0,buffer,sizeof(buffer));dprintf(GetSocket(),buffer);}  
        if(FD_ISSET(GetSocket(), &read_fd)){read(GetSocket(), buffer, sizeof(buffer));
	dprintf(0, "server: "); 	
	dprintf(0,buffer);	
	}
	}        
	close(GetSocket());

    }
    

};



class Server : public CommChannel{
		public:
	Server()
	{
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	bind(GetSocket(), (struct sockaddr *)&servaddr, sizeof(servaddr));
	listen(GetSocket(), 10);
 	for (i = 0; i < max_clients; i++) client_socket[i] = 0;  
	}
	void run(){
	for(;;){
	FD_ZERO(&read_fd);	
        max_sd = GetSocket(); 
	for ( i = 0 ; i < max_clients ; i++) 
		{ 
			//socket descriptor 
			sqd = client_socket[i]; 
			//if valid socket descriptor then add to read list 
			if(sd > 0) 
				FD_SET( sd , &read_fd); 
			//highest file descriptor number, need it for the select function 
			if(sd > max_sd) 
				max_sd = sd; 
		} 	
	FD_SET(0, &read_fd);
	FD_SET(GetSocket(), &read_fd);	
	select(max_sd+1, &read_fd, NULL, NULL, NULL);//man select
if (FD_ISSET(GetSocket(), &read_fd)) 
		{
	while ((new_socket = accept(GetSocket(),NULL,NULL))<=0)//man accept
			{ 
			}
			
while (new_socket = accept(GetSocket(),NULL,NULL)<=0) 
				{}

printf("New connection %d\n",new_socket);	

dprintf(new_socket,"welcome %d\n",new_socket);	
				
			puts("Channel open. Welcome message sent."); 
			//add new socket to array of sockets 
			for (i = 0; i < max_clients; i++) 
			{ 
				//if position is empty 
				if( client_socket[i] == 0) 
				{ 
					client_socket[i] = new_socket; 
					printf("Adding to list of sockets as %d\n" , i); 
					break; 
				} 
			} 
		} 
		//else its some IO operation on some other socket 
		for (i = 0; i < max_clients; i++) 
		{ 
			sd = client_socket[i]; 
			if (FD_ISSET( sd , &read_fd )) 
			{ 
				//Check if it was for closing , and also read the 
				//incoming message 
				if ((valread = read( sd , buffer, 1024)) == 0)//man read 
				{ 
					//Somebody disconnected , get his details and print 
					//getpeername(sd , (struct sockaddr*)&cliaddr , (socklen_t*)&addrlen); 
				
					printf("Host disconnected %d \n" , i); 
					close( sd ); 
					client_socket[i] = 0; 
				} 
				//Echo back the message that came in 
				else
				{ 
       buffer[valread] = '\0';  
          for ( i = 0 ; i < max_clients ; i++) 
                { 
                        //socket descriptor 
                        sd = client_socket[i]; 
                        //if valid socket descriptor then add to read list 
                      if(sd > 0)
dprintf(sd,buffer); 
       if (i==max_clients-1)printf("%s\n",buffer);
}       






				} 
			} 
		} 
	}
	close(sd2);
	close(GetSocket());
	}
};




*/

