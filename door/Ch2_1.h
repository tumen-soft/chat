#ifndef CH_2_1_H
#define CH_2_1_H


/*

2.1. Compile-Time Assertions

//TODO Clean this up
	Check at runtime if an expression is valid.
	The use case for this, as presented by the book, is for copying from one pointer to another.
	It replaces a runtime assert with a compile-time assert, meaning rarely executed branches that may not appear to cause problems can we checked.

	Note: In C++11 you can use static_assert, but while I'm following the book, I'm going to pretend its 2001.
*/
#include <iostream>
using namespace std;
namespace Chapter2
{
	namespace Ch2_1
	{
		#define STATIC_CHECK(expr, msg) \
		{\
			class ERROR_##msg {} ;\
			(void) Chapter2::Ch2_1::CompileTimeChecker<(expr) != 0> (ERROR_##msg());\
		}
		template <bool> class CompileTimeChecker
		{
			CompileTimeChecker(...){cout<<"top";};
		};
		template<> class CompileTimeChecker<false> {   
		public:
                       CompileTimeChecker(...){std::cout << "false"<< std::endl;};
 };


            template<> class CompileTimeChecker<true> {   
		public:
	                       CompileTimeChecker(...){std::cout<<"true"<<std::endl;};
 };


		void Run();
	}
}


#endif
