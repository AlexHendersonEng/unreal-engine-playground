#include "MyStaticLibrary.h"
#include "MySharedLibrary.h"
#include <iostream>

int main()
{
	std::cout << MyStaticLibrary() << std::endl;
	std::cout << MySharedLibrary() << std::endl;
	return 0;
}
