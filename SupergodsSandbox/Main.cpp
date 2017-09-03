#include <iostream>
#include "../SupergodEngine/Math/SMath.h"

void main()
{
	byte b = -3;
	std::cout << SupergodEngine::Math::SMath::CloseEnough(1, 2, 1) << std::endl;
	std::cout << SupergodEngine::Math::SMath::CloseEnough(1, 2, 0.999f) << std::endl;
	std::cin.get();
}