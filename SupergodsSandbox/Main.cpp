#include <iostream>
#include <SupergodCore.h>

#define PRINT(thing) cout << thing << endl

using namespace std;
using namespace SupergodCore;

#define Vector3D_UnitX SupergodCore::Math::Vector3D(1, 0, 0)

void main()
{
	Math::Vector3D test = Math::Vector3D::UnitX();
	cin.get();
}