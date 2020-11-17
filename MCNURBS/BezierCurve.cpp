#include "pch.h"

#include "BezierCurve.h"


void deCasteljau1 (const MCNURBS::Vector *P, size_t n, double u, MCNURBS::Vector &C)
	{
	std::vector<MCNURBS::Vector> Q (n + 1, MCNURBS::ZeroVector(P[0].GetSize()));
	for (size_t i = 0; i <= n; ++i)
		Q[i] = P[i];
		
	for (int k = 1; k <= static_cast<int>(n); k++)
		{
		for (int i = 0; i <= static_cast<int>(n) - k; ++i)
			{
			Q[i] = (1. - u) * Q[i] + u * Q[static_cast<size_t>(i) + 1];
			}
		}
	
	C = Q[0];
	}


namespace MCNURBS {


BezierCurve::BezierCurve (const std::initializer_list<Vector> &controlPoints)
	: controlPoints (controlPoints)
	{
	}


auto BezierCurve::operator()(double t) const->Vector
	{
	Vector C = ZeroVector (this->controlPoints[0].GetSize ());
	deCasteljau1 (this->controlPoints.data (), this->controlPoints.size () - 1, t, C);
	return C;
	}

}
