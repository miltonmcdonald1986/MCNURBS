#pragma once


#include <vector>

#include "DefineMCNURBSDLL_API.h"


namespace MCNURBS {


class Vector
	{
	public:
		explicit Vector(const std::vector<double> &components)
			: components(components)
			{
			}

	private:
		std::vector<double> components;

		friend bool operator==(const Vector &v0, const Vector &v1);
		friend Vector operator*(double c, const Vector &v);
	};



bool operator==(const Vector &v0, const Vector &v1)
	{
	return v0.components == v1.components;
	}


Vector operator*(double c, const Vector &v)
	{
	Vector cv = v;
	for (size_t i = 0; i < cv.components.size(); ++i)
		{
		cv.components[i] = c * v.components[i];
		}

	return cv;
	}


}
