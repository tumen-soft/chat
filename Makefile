chat: client.o server.o ipscan.o message.o 
	g++   client.o server.o ipscan.o message.o -o chat -fno-rtti 
client.o: client.cxx
	g++ -c -fmodules-ts -std=c++20 -x c++-system-header iostream typeinfo
	g++ -c client.cxx -fmodules-ts -std=c++20 -x c++-system-header iostream typeinfo
server.o: server.cxx
	g++ -c server.cxx -fmodules-ts -std=c++20 
ipscan.o: ipscan.cxx	
	g++ -c ipscan.cxx -fpermissive -fmodules-ts -std=c++20 
message.o: message.cxx
	g++ -c -fmodules-ts -std=c++20 -x c++-system-header iostream
	g++ -c message.cxx -fpermissive -fmodules-ts -std=c++20 -x c++-system-header iostream


clean:
	rm *.o chat gcm.cache/ -r

#g++ -c -fpermissive -lpthread -std=c++20  -fmodules-ts server.cpp

#all:
#	g++ *.cpp -o game -std=c++17
