#include <iostream>
#include <csignal>
class foo{
public:
int g(int a, int b){
return a+b;

}


};
void signa(int k){

}
typedef int (foo::*memb)(int, int);
int main(){
foo f;
memb mp = &foo::g;
std::cout<<(f.*mp)(5,7)<<std::endl;
std::signal(SIGFPE, signa);
//std::signal(int sig, int (*func)(int,int));
return 0;
}
