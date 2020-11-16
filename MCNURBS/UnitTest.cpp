#include "pch.h"
#include "CppUnitTest.h"

#include "HelloWorld.h"
#include "PowerBasisCurve.h"
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
			MCNURBS::Vector v (std::vector<double> (3));
			v[0] = -1.;
			v[1] = 3.;
			v[2] = 1.;
			MCNURBS::Vector w = MCNURBS::ZeroVector (4);


			Assert::IsTrue (u.GetSize () == 3);
			Assert::IsTrue (u == v);
			Assert::IsTrue (u.GetComponents () == std::vector<double> ({ -1., 3., 1. }));
			Assert::IsTrue (w == MCNURBS::Vector (std::vector<double>(4, 0.)));
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


TEST_CLASS (MCNURBS_PowerBasisCurve)
	{
	public:

		TEST_METHOD (ComputePointOnPowerBasisCurve0)
			{
			MCNURBS::Vector a0 ({ 1., 2. });
			MCNURBS::Vector a1 ({ -3., 1. });
			MCNURBS::PowerBasisCurve C ({ a0, a1 });
			Assert::IsTrue (C (0.) == a0);
			Assert::IsTrue (C (0.5) == MCNURBS::Vector ({ -0.5, 2.5 }));
			Assert::IsTrue (C (1.) == a0 + a1);
			}

		TEST_METHOD (ComputePointOnPowerBasisCurve1)
			{
			MCNURBS::Vector a0 ({ 4. });
			MCNURBS::Vector a1 ({ 3. });
			MCNURBS::Vector a2 ({ 2. });
			MCNURBS::PowerBasisCurve C ({ a0, a1, a2 });
			Assert::IsTrue (C (0.) == a0);
			Assert::IsTrue (C (0.25) == MCNURBS::Vector ({ 4.875 }));
			Assert::IsTrue (C (0.5) == MCNURBS::Vector ({ 6. }));
			Assert::IsTrue (C (1.) == a0 + a1 + a2);
			}
	};


}
