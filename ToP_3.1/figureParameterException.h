#pragma once
#include <stdexcept>
using namespace std;

class figureParameterException :
    public std::exception
{
public:
    figureParameterException(const char* msg);
    ~figureParameterException();
};

