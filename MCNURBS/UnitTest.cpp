#include "pch.h"
#include "CppUnitTest.h"

#include "HelloWorld.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTest1
{


	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestHelloWorld)
			{
			Assert::IsTrue (MCNURBS::HelloWorld () == "Hello, world!");
			}

	};


}
