#include "vector.h"

Vector::Vector()
{
	i=j=k=0.;
}

Vector::Vector(const Vector &copy)
{
	i=copy.i;
	j=copy.j;
	k=copy.k;
}

Vector::Vector(float _i, float _j, float _k)
{
	i=_i;
	j=_j;
	k=_k;
}

const Vector& Vector::operator =(const Vector &copy)
{
	i=copy.i;
	j=copy.j;
	k=copy.k;
	return *this;
}

Vector Vector::operator +(const Vector &v)
{
	return Vector(i+v.i ,j+v.j, k+v.k);
}

Vector Vector::operator -(const Vector &v)
{
	return Vector(i-v.i, j-v.j, k-v.k);
}

Vector Vector::operator *(float a)
{
	return Vector(i*a, j*a, k*a);
}

Vector Vector::operator /(float a)
{
	return Vector(i/a, j/a, k/a);
}

float Vector::operator *(const Vector &v)
{
	return (i*v.i + j*v.j + k*v.k);
}

float Vector::length()
{
	return sqrt(i*i + j*j + k*k);
}

