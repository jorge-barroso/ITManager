#pragma once
#include <stdexcept>
class DesWeakKeyException : public std::runtime_error
{
public:
	DesWeakKeyException(char const* message);
	~DesWeakKeyException();
	virtual char const* what() const throw();
};

