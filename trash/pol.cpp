#include <iostream>

class Base{
public:
virtual  Base * clone() {
    std::cout << "Base::clone()\n" ;
    Base * bp = new Base ;
    return bp ;
}
  std::string ID() {return "Base class";}
};

class Derived: public Base {
public:
  //Derived* and Base* are same data type (acceptable):
  Derived * clone() {
    std::cout << "Derived::clone()\n" ;
    Derived * dp = new Derived ;
    return dp ;
}
  std::string ID() {return "Derived class";}
};


int main() {

  Base * bp = new Derived;

  std::cout << bp->clone()->ID() <<"\n";

  std::cout << dynamic_cast <Derived*>(bp->clone())->ID() <<"\n";
  /*
  next code give error: cannot convert Base* to Derived*: 

  Derived * dp2 = bp->clone();
  std::cout << dp2->ID() << "\n";
  */
}
