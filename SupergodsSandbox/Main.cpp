#include <iostream>
#include <SupergodEngine.h>

using namespace SupergodEngine;

void main()
{
	byte b = -3;
	std::cout << Math::SMath::CloseEnough(1, 2, 1) << std::endl;
	std::cout << Math::SMath::CloseEnough(1, 2, 0.999f) << std::endl;
	std::cin.get();
}