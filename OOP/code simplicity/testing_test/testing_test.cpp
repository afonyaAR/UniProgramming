#include "pch.h"
#include "CppUnitTest.h"
#include <cassert>
#include "../testing/testing.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testingtest
{
	TEST_CLASS(testingtest)
	{
	public:

		TEST_METHOD(AddWithInc_2Plus3Inc1_Returned6)
		{
			double arg1 = 2;
			double arg2 = 3;

			double expected = 6;

			double result = AddWithInc(arg1, arg2);

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Div_4Div2_Returned2)
		{
			double arg1 = 4;
			double arg2 = 2;

			double expected = 2;

			double result = Div(arg1, arg2);

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Div_4Div0_Returned_Division_by_zero)
		{
			double arg1 = 4;
			double arg2 = 0;

			double result = Div(arg1, arg2);
		}
	};
}
