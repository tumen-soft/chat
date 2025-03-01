//#define DEBUG
#include "ipscan.h"
#include <memory>
//#include "policy.h"
#include "client.h"
#include "server.h"
#include "chat.h"
#include <iostream>
//#define DEBUG
#define MAXLINE 1024
#define PORT 8080

/** 0.8
chat ‐ a sample messanger
This line is now the first of the description section.
Note that function parameters parm1 and parm2 are highlighted
in the generated man page.
*/


#include <string_view>
#include <source_location>

void check(bool condition, std::string_view additional_message, std::source_location sl =
std::source_location::current()){
  if(not(condition)){
    std::cerr << "condition failed " << additional_message << " " << sl.file_name() << ":" << sl.line() << std::endl;
  }
}


//void test(){
//  check(true!=true, "true!=true==false");
//}

//using А = абстракция::А;

















void spawnThreads();
void check();
int check1();
//typedef std::map<int,char*> nmap;
//enum PeerType{
//        _Server,
//        _Client
//};
//extern int main_(void);
//#define DEBUG_BUILD 1

class Switch {
public:
    А *getPolicy(С *s) {

        return new С(new TCPE());

    }



    А *getPolicy(В *c) {

        return (new В(new TCPD()));

    }

    void run() {
        chat->создатьСокет();
        chat->connectInit();
        for(;;)
        {
            chat->selinit();

            chat->sel();

            ///select(300, &singleton->read_fd, NULL, NULL, NULL);

            ///if(FD_ISSET(singleton->sock, &singleton->read_fd))singleton->conn();

            chat->sendmes();

//for(;;)
        }
    }


    А *chat;
};



enum choice {
    END, RUN
};
//std::ostream& os = std::cout;

А *getPolicy() {

    return new С(new TCPE());

}



А *getPolicy1() {

//return new Client(new TCPD());

}

int main_() {
    choice ch;
st:
    ;
    test();
    std::cout<<"0.end"<<std::endl;
    std::cout<<"1.run"<<std::endl;
    int c,p;
//peer = new Server;
    std::cin>>c;
//c=1;
    ch=(choice)c;
    //А *chat;
    Switch *sw= new Switch();
    switch(ch) {

    case END:
        return 0;
        break;

    case RUN:
        spawnThreads();
        check();
        //--------------
        if(check1()<1)А *chat=sw->getPolicy(new С);
        else А *chat=sw->getPolicy(new В);
        sw->chat=chat;
	sw->run();

        //default:
        //       goto st;
        //	break;
    }

//run(peer);
//std::cout<<f;
}

