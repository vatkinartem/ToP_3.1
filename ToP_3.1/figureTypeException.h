#pragma once
#include <stdexcept>
using namespace std;

class figureTypeException :
    public std::exception
{
public:
    figureTypeException(const char* msg);
    ~figureTypeException();
};

