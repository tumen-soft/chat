all:
	g++ -c -fmodules-ts -std=c++20 -x c++-system-header iostream
	g++ -c abspeer.cxx -fmodules-ts -std=c++20
	g++ -c ipscan.cxx -fmodules-ts -std=c++20 -fpermissive
	g++ -c client.cxx -fmodules-ts -std=c++20 -fpermissive
	g++ -c server.cxx -fmodules-ts -std=c++20 -fpermissive
	g++ -c message.cxx -fmodules-ts -std=c++20 -fpermissive
	g++ main.cpp  *.o -o chat -fmodules-ts -std=c++20 -x c++-system-header iostream -x c++-system-header cstdlib


all1:

programm:stuff.cpm
	g++ -fmodules-ts -std=c++20 f-module-file=struff.cpm   stuff.cpm

stuff.cpm: client.cxx
	g++ abspeer.cxx -fmodules-ts -std=c++20 -o stuff.cpm

