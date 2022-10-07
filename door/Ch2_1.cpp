#include "Ch2_1.h"

#include <iostream>

struct A
{
	int a;
};
struct AB
{
	int a, b;
};
enum T{
	s,
	c
};

using namespace Chapter2::Ch2_1;
int main()
{
	std::cout << std::endl;
	std::cout << "***** 2.1 *****" << std::endl;
	STATIC_CHECK(1, Destination_Too_Narrow);
}
