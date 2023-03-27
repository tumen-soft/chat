#include <iostream>



int f(int(*fp)(int, int), int a){

return fp(a, 100);
}

int some_func(int i, int j){
return i+j;
}

int main(){

int (*fun_ptr)(int, int);

some_func(10,20);
fun_ptr = some_func;

std::cout<< fun_ptr(10,20)<<std::endl;
std::cout<< f(fun_ptr, 22)<<std::endl;

}
