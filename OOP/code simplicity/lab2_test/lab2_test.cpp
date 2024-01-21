#include "pch.h"
#include "CppUnitTest.h"
#include "../lab2/lab2.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab2test
{
	TEST_CLASS(lab2test)
	{
	public:
		TEST_METHOD(NumOfTargetedStrokes_Test1)
		{
			const int n = 2;
			const int m = 3;
			int target = 0;
			int** matrix = new int* [n];
			matrix[0] = new int[m] { 0, 1, 2 };
			matrix[1] = new int[m] { 0, 1, 1 };
			Assert::AreEqual(0, NumOfTargetedStrokes(matrix, n, m, target));
		}

		TEST_METHOD(NumOfTargetedStrokes_Test2)
		{
			const int n = 1;
			const int m = 1;
			int target = 0;
			int** matrix = new int* [n];
			matrix[0] = new int[m] { 0 };
			Assert::AreEqual(0, NumOfTargetedStrokes(matrix, n, m, target));
		}

		TEST_METHOD(NumOfTargetedStrokes_Test3)
		{
			const int n = 0;
			const int m = 0;
			int target = 0;
			int** matrix = new int* [n];
			Assert::AreEqual(0, NumOfTargetedStrokes(matrix, n, m, target));
		}
	};
}
