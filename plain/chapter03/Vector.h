#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>

#include <initializer_list>

class Vector{
private:
	double * elem;
	size_t c;
public:
	Vector(std::initializer_list<double> list);
	~Vector();

	size_t count();
	double* begin();
	double* end();

	double push_back(double it);

	double& operator[](size_t i);
};

#endif

