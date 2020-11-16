#pragma once


#include <vector>

#include "DefineMCNURBSDLL_API.h"


namespace MCNURBS {


class Vector
	{
	public:
		MCNURBSDLL_API explicit Vector (const std::initializer_list<double> &components);
		MCNURBSDLL_API explicit Vector (const std::vector<double> &components);

		MCNURBSDLL_API auto GetComponents () const->std::vector<double>;
		MCNURBSDLL_API auto GetSize () const->size_t;

		MCNURBSDLL_API auto operator[](size_t i) const->const double &;
		MCNURBSDLL_API auto operator[](size_t i)->double &;

	private:
		std::vector<double> components;
	};

MCNURBSDLL_API auto ZeroVector (size_t dimension)->Vector;

MCNURBSDLL_API auto operator==(const Vector &v0, const Vector &v1) -> bool;
MCNURBSDLL_API auto operator*(double c, const Vector &v)->Vector;
MCNURBSDLL_API auto operator*(const Vector &v, double c)->Vector;
MCNURBSDLL_API auto operator+(const Vector &v0, const Vector &v1)->Vector;
MCNURBSDLL_API auto operator-(const Vector &v0, const Vector &v1)->Vector;


}
