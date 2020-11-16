#include "pch.h"

#include "PowerBasisCurve.h"


void Horner1 (const std::vector<MCNURBS::Vector> &a, size_t n, double u0, MCNURBS::Vector &C)
	{
	C = a[n];
	for (int i = static_cast<int>(n) - 1; i >= 0; --i)
		{
		C = C * u0 + a[i];
		}
	}


namespace MCNURBS {


PowerBasisCurve::PowerBasisCurve (const std::initializer_list<Vector> &coefficients)
	: coefficients(coefficients)
	{
	}


auto PowerBasisCurve::operator()(double t) const->Vector
	{
	Vector C = ZeroVector(this->coefficients[0].GetSize());
	Horner1 (this->coefficients, this->coefficients.size () - 1, t, C);
	return C;
	}

}
