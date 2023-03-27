#include <iostream>
template <class FUN>
int f(FUN fp, int a)
{
	return fp(a);
}


int main(){
	//цешка панель  управления
        std::cout << f([](int i, int j){return i*j;},44)<<std::endl;

}
