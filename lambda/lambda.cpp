#include <iostream>
int f(int(*fp)(int, int),int a){
	return fp(a, 100);
}
int main(){
	auto sum = [](int i, int j){return i+j;};
	auto mul = [](int i, int j){return i*j;};
	std::cout << f(sum,22)<<std::endl;
	std::cout << f(mul,33)<<std::endl;
        std::cout << f([](int i, int j){return i*j;},44)<<std::endl;




}
