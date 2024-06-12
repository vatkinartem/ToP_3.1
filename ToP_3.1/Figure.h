#pragma once
class Figure
{
private:
protected:
	double area;
public:
	Figure();
	virtual ~Figure() = 0;
	virtual double getArea() = 0;
};

