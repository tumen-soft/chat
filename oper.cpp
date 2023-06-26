#include <iostream>
class client
    {public: int a;int b;
	client(int c):a(c){}
    };

class server: public client
{public:
	server(int n):client(n){}
};
class proxy {
	public:
    client *target;
    client *operator->() const
        { return target; }
};

class proxy2 {
	public:
    proxy *target;
    proxy &operator->() const
        { return * target; }
};

int main() {
    //client x; 
    //x = client{3,3};
    server* x;
    x = new server{4};
    //proxy y = { & x };
    //proxy2 z = { & y };

    std::cout << x->a; //<< y->a << z->a; // print "333"
}
