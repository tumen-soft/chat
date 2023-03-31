chat: client.o server.o ipscan.o message.o 
	g++   client.o server.o ipscan.o message.o -o chat 
client.o: client.cpp
	g++ -c client.cpp -fmodules-ts -std=c++20 
server.o: server.cpp
	g++ -c server.cpp -fmodules-ts -std=c++20 
ipscan.o: ipscan.cpp	
	g++ -c ipscan.cpp -fpermissive -fmodules-ts -std=c++20 
message.o: message.cpp
	g++ -c -fmodules-ts -std=c++20 -x c++-system-header iostream
	g++ -c message.cpp -fpermissive -fmodules-ts -std=c++20 -x c++-system-header iostream


clean:
	rm *.o chat gcm.cache/ -r

#g++ -c -fpermissive -lpthread -std=c++20  -fmodules-ts server.cpp

#all:
#	g++ *.cpp -o game -std=c++17
