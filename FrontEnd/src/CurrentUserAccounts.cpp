#include "../include/CurrentUserAccounts.hpp"
#include "Poco/File.h"
#include "Poco/Path.h"
#include "Poco/FileStream.h"
#include <cassert>
#include <iostream>	// TODO remove

using namespace std;
using Poco::File;
using Poco::Path;
using Poco::FileInputStream;

CurrentUserAccounts::CurrentUserAccounts(string cua_file)
{
	File file = File(cua_file);

	if (file.exists())
	{
		this->cua_file = cua_file;

		/* Parse the current user accounts file */
		this->parse();
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
	/* Read the contents of the current user accounts and store each user */
	FileInputStream fis(this->cua_file);

	assert(fis.good());
	if (fis.good())
	{
		string read;

		while (getline(fis, read))
		{
			cout << read << endl;
		}
	}
	else
	{
		throw Exception(CORRUPT_CUA);
	}
}
