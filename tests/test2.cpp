#include <arpa/inet.h>  
//#include <sys/socket.h> 

int main(void){


if(int sock=socket(AF_INET, SOCK_STREAM, 0))return 0;
else return 4;
}
