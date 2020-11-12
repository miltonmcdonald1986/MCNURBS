#include "pch.h"
#include "CppUnitTest.h"

#include "HelloWorld.h"
#include "Vector.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTest
{


	TEST_CLASS(HelloWorld)
		{
		public:
		
			TEST_METHOD(TestHelloWorld)
				{
				Assert::IsTrue (MCNURBS::HelloWorld () == "Hello, world!");
				}

	};


	TEST_CLASS (MCNURBS_Vector)
		{
		public:

			TEST_METHOD (ScalarTimesVector)
				{
				MCNURBS::Vector u ({ -1., 3., 1. });
				MCNURBS::Vector v ({ -2., 6., 2. });
				
				Assert::IsTrue (2.*u == v);
				}

		};


}
