#include <arpa/inet.h>  
#include "../include/client.h" 

int main(void){

Client *cli_ = new Client();

cli_->createSocket();

return 0;
}
