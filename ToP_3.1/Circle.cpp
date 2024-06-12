#include "Circle.h"

Circle::Circle(): r(0)
{
	this->area = 0;
}

Circle::Circle(const double radius = 0) : r(radius)
{
	this->area = 0;
}

Circle::Circle(const Circle& source) : r(source.r)
{
	this->area = source.area;
}

Circle::~Circle()
{
}

double Circle::getArea()
{
	this->area = (M_PI * this->r * this->r);
	return this->area;
}
