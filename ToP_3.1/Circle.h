#pragma once
#include "Figure.h"
#define _USE_MATH_DEFINES
#include <math.h>

class Circle :
    public Figure
{
private:
    double r;
public:
    Circle();
    Circle(const double radius);
    Circle(const Circle& source);
    ~Circle() override;
    double getArea() override;
};

