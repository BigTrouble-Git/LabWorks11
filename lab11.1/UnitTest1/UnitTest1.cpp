#include "pch.h"
#include "CppUnitTest.h"
#include "../Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char fname[100] = "124,124,124";
			char gname[100]; // ім'я другого файлу
			double s = ProcessBIN(fname, gname);

			Assert::AreEqual(s, 0.);

		}
	};
}
