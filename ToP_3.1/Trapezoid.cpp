#include "Trapezoid.h"

Trapezoid::Trapezoid():a(0), c(0), height(0)
{
	this->area = 0;
}

Trapezoid::Trapezoid(double _a, double _c, double _height) :a(_a), c(_c), height(_height)
{
	this->area = 0;
}

Trapezoid::Trapezoid(const Trapezoid& source) :a(source.a), c(source.c), height(source.height)
{
	this->area = 0;
}

Trapezoid::~Trapezoid()
{
}

double Trapezoid::getArea()
{
	this->area = (a + c) * height / 2;

	return this->area;
}
