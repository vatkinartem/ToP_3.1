#include "RectTriangle.h"

RectTriangle::RectTriangle() : a(0), b(0)
{
	this->area = 0;
}

RectTriangle::RectTriangle(double _a = 0, double _b = 0) : a(_a), b(_b)
{
	this->area = 0;
}

RectTriangle::RectTriangle(const RectTriangle& source) : a(source.a), b(source.b)
{
	this->area = 0;
}

RectTriangle::~RectTriangle()
{
}

double RectTriangle::getArea()
{
	this->area = (this->a * this->b)/2;
	return this->area;
}
