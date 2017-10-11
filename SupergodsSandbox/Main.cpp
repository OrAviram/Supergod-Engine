#include <iostream>
#include <SupergodCore.h>
#include "Math/Interfaces/ITransformer.h"
#include "Math/Interfaces/IRotator.h"

#define PRINT(thing) cout << thing << endl

using namespace std;
using namespace SupergodCore;

void main()
{
	PRINT(sizeof(Math::Angle));
	PRINT(sizeof(float));
	cin.get();
}