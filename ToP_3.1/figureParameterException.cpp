#include "figureParameterException.h"

figureParameterException::figureParameterException(const char* msg) : std::exception(msg)
{
}

figureParameterException::~figureParameterException()
{
}