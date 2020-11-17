#pragma once

#include <initializer_list>

#include "Vector.h"

#include "DefineMCNURBSDLL_API.h"


namespace MCNURBS {


class BezierCurve
	{
	public:
		MCNURBSDLL_API explicit BezierCurve (const std::initializer_list<Vector> &controlPoints);

		MCNURBSDLL_API auto operator()(double t) const->Vector;

	private:
		std::vector<Vector> controlPoints;
	};


}
