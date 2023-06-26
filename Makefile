CC=gcc
CXX=g++
CFLAGS= -fmodules-ts -std=c++20 -fpermissive 
LDFLAGS= 
OBJECTS=abspeer.o ipscan.o client.o server.o message.o chat.o
MODULES= $(CFLAGS) -x c++-system-header iostream 

default:chat

chat:$(OBJECTS)
	$(CXX) $(OBJECTS) $(MODULES) -o chat

%.o:%.cxx
	$(CXX) $(CFLAGS) $< -c -o $@
clean:
	rm *.o chat
