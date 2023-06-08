all:
	g++ -c -fmodules-ts -std=c++20 -x c++-system-header iostream
	g++ -c abspeer.cxx -fmodules-ts -std=c++20
	#g++ -c speech_impl.cpp -fmodules-ts -std=c++20
	#g++ -c speech_impl.cpp -fmodules-ts -std=c++20
	#g++ -c -fmodules-ts -std=c++20 -x c++-system-header iostream
	g++ main.cpp  *.o -fmodules-ts -std=c++20 -x c++-system-header iostream -x c++-system-header cstdlib


all1:

programm:stuff.cpm
	g++ -fmodules-ts -std=c++20 f-module-file=struff.cpm   stuff.cpm

stuff.cpm: client.cxx
	g++ abspeer.cxx -fmodules-ts -std=c++20 -o stuff.cpm

