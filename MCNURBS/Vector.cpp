#include "pch.h"

#include "Vector.h"


namespace MCNURBS {


Vector::Vector (const std::initializer_list<double> &components)
	: components (components)
	{
	}


Vector::Vector (const std::vector<double> &components)
	: components (components)
	{
	}


auto Vector::GetComponents () const -> std::vector<double>
	{
	return this->components;
	}


size_t Vector::GetSize () const
	{
	return this->components.size ();
	}


auto Vector::operator[](size_t i) const->const double &
	{
	return this->components[i];
	}


auto Vector::operator[](size_t i)->double &
	{
	return this->components[i];
	}


auto ZeroVector (size_t dimension) -> Vector
	{
	return Vector (std::vector<double> (dimension, 0.));
	}


auto operator==(const Vector &v0, const Vector &v1) -> bool
	{
	return v0.GetComponents () == v1.GetComponents ();
	}


auto operator*(double c, const Vector &v) -> Vector
	{
	Vector cv = v;
	for (size_t i = 0; i < cv.GetSize (); ++i)
		{
		cv[i] = c * v[i];
		}

	return cv;
	}


auto operator*(const Vector &v, double c) -> Vector
	{
	return c * v;
	}


auto operator+(const Vector &v0, const Vector &v1)->Vector
	{
	Vector v = v0;
	for (size_t i = 0; i < v.GetSize (); ++i)
		{
		v[i] += v1[i];
		}

	return v;
	}


auto operator-(const Vector &v0, const Vector &v1)->Vector
	{
	return v0 + -1. * v1;
	}


}
