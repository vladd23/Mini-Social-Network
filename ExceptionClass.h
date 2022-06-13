#pragma once
#include <exception>
using namespace std;

class ExceptionClass : public exception
{
private:
	const char* errorMessage;
public:
	ExceptionClass(const char*);
	const char* what();
};

