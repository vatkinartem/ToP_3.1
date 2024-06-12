#pragma once
#include "Figure.h"
#include <math.h>

class Trapezoid :
    public Figure
{
private:
    double a;
    double c;
    double height;
public:
    Trapezoid();
    Trapezoid(double _a, double _c, double _height);
    Trapezoid(const Trapezoid& source);
    ~Trapezoid() override;
    double getArea() override;
};  

