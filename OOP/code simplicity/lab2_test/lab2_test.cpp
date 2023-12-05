#include "pch.h"
#include "CppUnitTest.h"
#include "../lab2/lab2.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab2test
{
	TEST_CLASS(lab2test)
	{
	public:
		TEST_METHOD(NumOfTargetedStrokes_Test)
		{
			int m = 5;
			int n = 3;
			int target = 0;
			int** matrix = RandomMatrix(m, n, numbers);
			Assert::
		}
	};
}
