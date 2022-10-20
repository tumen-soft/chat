#include <iostream>
#include <string>
#include <arpa/inet.h>  //inet_addr define
#include <stdio.h>  //printf()
#include <sys/socket.h> //socket(), connect(), bind(), listen(), accept(), select(); 
#include <unistd.h>  //close(), fread()
#include <cstring>
struct sockaddr_in addr;

static bool port_is_open(const char * address, int port)
{

 int socke = socket(AF_INET, SOCK_STREAM, 0);
 
addr.sin_family = AF_INET;
 addr.sin_port = htons(port);
 addr.sin_addr.s_addr =  inet_addr(address);
 
 return (connect(socke, (struct sockaddr*)&addr, sizeof(addr))==0);




}

int main()
{
    std::cout << "Scaning..." <<std::endl;
    //for (int i=70;i<81;i++)
    int i = 80;
    if (port_is_open("108.177.14.94", i))
        std::cout << "Port "<< i <<":"<<"OPEN" << std::endl;
    else
        std::cout << "Port "<< i <<":"<<"CLOSED" << std::endl;
    return 0;
}
