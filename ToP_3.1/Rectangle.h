#pragma once
#include "Figure.h"
class Rectangle :
    public Figure
{
private:
    double ab;
    double bc;
    double cd;
    double da;
public:
    Rectangle();
    Rectangle(const double _ab, const  double _bc);
    Rectangle(const Rectangle &source);
    ~Rectangle() override;
    double getArea() override;
};

