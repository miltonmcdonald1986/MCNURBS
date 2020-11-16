#pragma once

#include <initializer_list>

#include "Vector.h"

#include "DefineMCNURBSDLL_API.h"


namespace MCNURBS {


class PowerBasisCurve
	{
	public:
		MCNURBSDLL_API explicit PowerBasisCurve (
			const std::initializer_list<Vector> &coefficients
			);

		MCNURBSDLL_API auto operator()(double t) const -> Vector;

	private:
		std::vector<Vector> coefficients;
	};


}
