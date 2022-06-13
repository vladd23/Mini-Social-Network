#include "ExceptionClass.h"
using namespace std;

ExceptionClass::ExceptionClass(const char* message): errorMessage(message), exception(message)
{
}

const char* ExceptionClass::what()
{
	return this->errorMessage;
}
