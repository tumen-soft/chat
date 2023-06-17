CC=gcc
CXX=g++
CFLAGS= -fmodules-ts -std=c++20 -fpermissive 
LDFLAGS= 
OBJECTS= abspeer.o ipscan.o client.o server.o message.o chat.o
MODULES= $(CFLAGS) -x c++-system-header iostream 

default:chat
	#g++ -c -fmodules-ts -std=c++20 -x c++-system-header iostream
	#g++ -c abspeer.cxx -fmodules-ts -std=c++20
	#g++ -c ipscan.cxx -fmodules-ts -std=c++20 -fpermissive
	#g++ -c client.cxx -fmodules-ts -std=c++20 -fpermissive
	#g++ -c server.cxx -fmodules-ts -std=c++20 -fpermissive
	#g++ -c message.cxx -fmodules-ts -std=c++20 -fpermissive
	#g++ main.cpp  *.o -o chat -fmodules-ts -std=c++20 -x c++-system-header iostream -x c++-system-header cstdlib

chat:$(OBJECTS)

ch:
	$(CXX) $(MODULES)

chat.o: chat.cpp

abspeer.o: abspeer.cxx
	$(CXX) $(CFLAGS) abspeer.cxx  

ipscan.o: ipscan.cxx
	$(CXX) $(CFLAGS) ipscan.cxx  

client.o: client.cxx
	$(CXX) $(CFLAGS) client.cxx  

server.o: server.cxx
	$(CXX) $(CFLAGS) server.cxx  

message.o: message.cxx
	$(CXX) $(CFLAGS) message.cxx  

clean:
	rm *.o chat
