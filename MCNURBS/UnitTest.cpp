#include "pch.h"
#include "CppUnitTest.h"

#include "HelloWorld.h"
#include "Vector.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTest {


TEST_CLASS (HelloWorld)
	{
	public:

		TEST_METHOD (TestHelloWorld)
			{
			Assert::IsTrue (MCNURBS::HelloWorld () == "Hello, world!");
			}

	};


TEST_CLASS (MCNURBS_Vector)
	{
	public:

		TEST_METHOD (VectorOperations)
			{
			MCNURBS::Vector u ({ -1., 3., 1. });
			Assert::IsTrue (u.GetComponents () == std::vector<double> ({ -1., 3., 1. }));
			}

		TEST_METHOD (ScalarTimesVector)
			{
			MCNURBS::Vector u ({ -1., 3., 1. });
			MCNURBS::Vector v ({ 4., 7., 0. });

			Assert::IsTrue (2. * u == MCNURBS::Vector ({ -2., 6., 2. }));
			Assert::IsTrue (3. * v == MCNURBS::Vector ({ 12., 21., 0. }));
			}

		TEST_METHOD (SumOfVectors)
			{
			MCNURBS::Vector u ({ -1., 3., 1. });
			MCNURBS::Vector v ({ 4., 7., 0. });

			Assert::IsTrue (2. * u + 3. * v == MCNURBS::Vector ({ 10., 27., 2. }));
			Assert::IsTrue (u - v == MCNURBS::Vector ({ -5., -4., 1. }));
			}

	};


}
