#include "../include/Validate.hpp"
#include "Poco/RegularExpression.h"

using Poco::RegularExpression;

bool Validate::username(string username)
{
    throw Exception(NOT_YET_IMPLEMENTED);
}

bool Validate::event(string event)
{
    throw Exception(NOT_YET_IMPLEMENTED);
}

bool Validate::cua_entry(string entry)
{
    /* Verify that the current user accounts entry matches format */
	RegularExpression re("^[A-Za-z0-9_]{15}_(AA|FS|BS|SS)_[0-9]{6}\\.[0-9]{2}$");

	return re.match(entry);
}

bool Validate::atf_entry(string entry)
{
    throw Exception(NOT_YET_IMPLEMENTED);
}

bool Validate::dollars(string amount, double& converted)
{
    throw Exception(NOT_YET_IMPLEMENTED);
}

bool Validate::volume(string amount, int& converted)
{
    throw Exception(NOT_YET_IMPLEMENTED);
}
