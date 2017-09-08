#include <iostream>
#include <SupergodEngine.h>

using namespace std;
using namespace SupergodEngine;

void main()
{
	Math::Vector2D vec(1, 2);
	vec += Math::Vector2D(2, 1);

	vec -= Math::Vector2D(3, 4);
	cin.get();
}