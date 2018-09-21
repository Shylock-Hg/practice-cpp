#include <algorithm>
#include <cstring>

#include "Vector.h"

Vector::Vector(std::initializer_list<double> list) : 
	elem{new double[list.size()]}, c{static_cast<size_t>(list.size())}{
		std::copy(list.begin(), list.end(), elem);
	}
Vector::~Vector(){
	delete [] elem;
}

size_t Vector::count(){
	return c;
}
double* Vector::begin(){
	return (elem+0);
}
double* Vector::end(){
	return (elem+c);
}

double Vector::push_back(double it){
	double * newElem = new double[c+1];
	memcpy(newElem, elem, sizeof(double)*c);
	delete [] elem;
	elem = newElem;
	*(elem+c) = it;

	c++;
	return *(elem+c);
}

double& Vector::operator[](size_t i){
	return *(elem+i);
}

