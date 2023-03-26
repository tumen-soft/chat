#include <iostream>
int main() {
    //auto test = +[]{}; // Note the unary operator + before the lambda
    auto test = []{std::cout<<"test"<<std::endl;};
	test();
}

//https://www.google.ru/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwjz-Zjymvr9AhUY6CoKHb_zB-0QFnoECA0QAQ&url=https%3A%2F%2Fstackoverflow.com%2Fquestions%2F18889028%2Fa-positive-lambda-what-sorcery-is-this&usg=AOvVaw0OF1Pq2nDcH2nScFsDki8G
