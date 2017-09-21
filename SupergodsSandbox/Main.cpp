#include <iostream>
#include <SupergodCore.h>
#include "Math/Interfaces/ITransformer.h"
#include "Math/Interfaces/IRotator.h"

using namespace std;
using namespace SupergodCore;

struct Test : public Math::ITransformer<Test, Math::Vector3D>
{
	// Inherited via ITransformer
	virtual Math::Vector3D TransformVector(const Math::Vector3D & vector) const override
	{
		return Math::Vector3D();
	}
	virtual Test CombineTransformations(const Test & other) const override
	{
		return Test();
	}
	virtual Test DiscombineTransformations(const Test & other) const override
	{
		return Test();
	}
};

void main()
{
	Test a;
	Test b;
	Math::Transformer::CombineTransformations(a, b);
	cin.get();
}