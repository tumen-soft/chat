#include <iostream>
#if 0
int f(int(*fp)(int, int),int a){
	return fp(a, 100);
}
#endif
template <class FUN>
int f(FUN fp, int a)
{
	return fp(a);
}


int main(){
	auto sum = [](int i, int j){return i+j;};
	auto mul = [](int i, int j){return i*j;};
#if 0
	std::cout << f(sum,22)<<std::endl;
	std::cout << f(mul,33)<<std::endl;
        std::cout << f([](int i, int j){return i*j;},44)<<std::endl;
#endif
	int i=1;
	auto sum1 = [i](int j){return i+j;};
	std::cout << f(sum1,22)<<std::endl;
	//if     x.y.x      x.y.y    true false
	auto sum2 = [i](int j){return i;};
	auto sum3= [i](int j){return j;};
        std::cout << f(sum2,22)<<std::endl;
        std::cout << f(sum3,22)<<std::endl;



}
