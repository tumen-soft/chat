import <iostream>;
import <typeinfo>;
class A{};

int main(){

	A a;
	std::cout<<typeid(int).name()<<std::endl;
	return 0;


}


