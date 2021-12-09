#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab8.1 rec/Lab8.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81rec
{
	TEST_CLASS(UnitTest81rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			using namespace std;
			char lit_r[4] = "aa";
			bool l = false;
			l = Find_r(lit_r, 0);
			Assert::AreEqual(l, true);
		}
	};
}
