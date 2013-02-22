#include "../include/CurrentUserAccounts.hpp"
#include "Poco/File.h"
#include "Poco/Path.h"

using Poco::File;
using Poco::Path;

CurrentUserAccounts::CurrentUserAccounts(string cua_file)
{
	File file = File(cua_file);

	if (file.exists())
	{
		this->cua_file = cua_file;
	}
	else
	{
		throw Exception(CUA_NOT_FOUND);
	}
}

bool CurrentUserAccounts::has_user(string username)
{
    throw "Not yet implemented";
}

User CurrentUserAccounts::get_user(string username)
{
    throw "Not yet implemented";
}

void CurrentUserAccounts::parse()
{
    throw "Not yet implemented";
}
