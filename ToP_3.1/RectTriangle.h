#pragma once
#include "Figure.h"
#include <math.h>

class RectTriangle :
    public Figure
{
private:
    double a;
    double b;
public:
    RectTriangle();
    RectTriangle(double _a, double _b);
    RectTriangle(const RectTriangle& source);
    ~RectTriangle() override;
    double getArea() override;
};

