#include "pch.h"
#include "CppUnitTest.h"
#include "../lab4.3/Array.h" 
#include "../lab4.3/Array.cpp" 
#include "../lab4.3/Hex.h" 
#include "../lab4.3/Hex.cpp" 
#include "../lab4.3/Fraction.h" 
#include "../lab4.3/Fraction.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest43
{
	TEST_CLASS(UnitTest43)
	{
	public:

		TEST_METHOD(TestEqualityOperator)
		{
			// Arrange
			Array arr1(3, 5);
			Array arr2(3, 5);
			Array arr3(3, 6);

			// Act & Assert
			Assert::IsTrue(arr1 == arr2, L"arr1 should be equal to arr2");
			Assert::IsFalse(arr1 == arr3, L"arr1 should not be equal to arr3");
		}
	};
}
