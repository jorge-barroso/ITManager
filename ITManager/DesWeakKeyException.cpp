#include "stdafx.h"
#include "DesWeakKeyException.h"


DesWeakKeyException::DesWeakKeyException(char const* message) : std::runtime_error(message)
{}

DesWeakKeyException::~DesWeakKeyException()
{
}

char const * DesWeakKeyException::what() const throw()
{
	return std::exception::what();
}
