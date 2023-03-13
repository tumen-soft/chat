/* Async multiclient net chat  by Vergun Denis <blu.eagle@mail.ru>
 * Four structures : Client, Server, Chat, Self. 
 * main() function. 
 * init() func.
 * Functions: creation create_socket(), closing socket close_socket(), 
 * connecting connect_to_socket(), initialisation bind_socket(), 
 * waiting for connection listen_socket() and accept_connection(), 
 * select_connection().
 */

//enum PeerType (55) consist of two members - Client & Server. There two state: Client or Server in programm.
//Client: functions resive messages(including from stdin), send messages to server, send nickname on start
//Server: functions registering(unregistering) clients, resive messages(including from stdin), send messages to all registered clients resive nick from client & register it
//ip scaner, avtomaticheskiy vibor regima raboti.

/*
                (begin)
                   |
                   |    
                  \|/   
        create threads   loop(256(ip 192.168.1.*))(check for connect)
                   |    (threads massive)
                   |
                  \|/
        wait threads ends
                   |
                   |
                  \|/   
        check for client(susess connection) loop  yes ----> end  (client)
                   |
                no |               
                  \|/
                server


*/
//import <iostream>
#include <fstream>
//std::ofstream out("/dev/stdout");
//std::ifstream in("/dev/stdin");
import peer;

enum choice {
    END, RUN
};
//void spawnThreads();
//void wait();
//void check();
using namespace std;
extern ofstream out;
extern ifstream in;

int main(){
choice ch;
st:;
//ofstream out("/dev/stdout");
//ifstream in("/dev/stdin");



out<<"0.end"<<endl;
out<<"1.run"<<endl;
int c;
in>>c;
ch=(int)c;
switch(ch){

	case END:
		return 0;
		break;

	case RUN:
		out<< "wait..."<<endl;
		//spawnThreads();
		//wait();
		//check();
	default:
		goto st;
}
}

