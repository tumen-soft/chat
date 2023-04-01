all:
	g++ -c speech_impl.cpp -fmodules-ts -std=c++20
	g++ -c speech_impl1.cpp -fmodules-ts -std=c++20
	g++ -c speech.cpp -fmodules-ts -std=c++20
	g++ -c -fmodules-ts -std=c++20 -x c++-system-header iostream
	g++ main.cpp  *.o -fmodules-ts -std=c++20 -x c++-system-header iostream -x c++-system-header cstdlib
