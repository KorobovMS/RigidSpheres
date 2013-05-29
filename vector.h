#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>

class Vector
{
public:
	float i;
	float j;
	float k;

	Vector();
	Vector(float, float, float);
	Vector(const Vector&);

	~Vector() {}

	Vector operator+(const Vector&);
	Vector operator-(const Vector&);
	Vector operator*(float);
	float operator*(const Vector&);
	Vector operator/(float);
	const Vector& operator=(const Vector&);

	float length();
};

#endif // VECTOR_H
