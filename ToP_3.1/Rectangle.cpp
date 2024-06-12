#include "Rectangle.h"

Rectangle::Rectangle():ab(0), bc(0), cd(0), da(0)
{
	this->area = 0;
}

Rectangle::Rectangle(double _ab = 0, double _bc = 0) : ab(_ab), bc(_bc), cd(_ab), da(_bc)
{
	this->area = 0;
}

Rectangle::Rectangle(const Rectangle& source) : ab(source.ab), bc(source.bc), cd(source.cd), da(source.da)
{
	this->area = 0;
}

Rectangle::~Rectangle()
{
}

double Rectangle::getArea()
{
	this->area = this->ab * this->bc;

	return this->area;
}

