CC=gcc
CXX=g++
CFLAGS= -fpermissive 
LDFLAGS= 
OBJECTS= chat.o
MODULES= $(CFLAGS) 

default:chat docs

chat:$(OBJECTS)
	$(CXX) $(OBJECTS) $(MODULES) -o chat

%.o:%.cpp
	$(CXX) $(CFLAGS) $< -c -o $@
clean:
	rm *.o chat

docs:
	doxygen
