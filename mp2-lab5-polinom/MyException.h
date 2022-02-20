#pragma once
#include <exception>

class MyException : public std::exception
{
public:
	MyException(const char* msg) : std::exception(msg) {}
};
