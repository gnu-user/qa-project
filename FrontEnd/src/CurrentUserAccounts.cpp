#include "../include/CurrentUserAccounts.hpp"
#include "../include/Validate.hpp"
#include "Poco/File.h"
#include "Poco/Path.h"
#include "Poco/FileStream.h"
#include "Poco/RegularExpression.h"
#include "Poco/NumberParser.h"
#include <cassert>
#include <iostream>	// TODO remove

using namespace std;
using Poco::File;
using Poco::Path;
using Poco::FileInputStream;
using Poco::RegularExpression;
using Poco::NumberParser;

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
	for (vector<User>::iterator it = this->users.begin(); it != this->users.end(); ++it)
	{
		if (it->get_username().compare(username) == 0)
		{
			return true;
		}
	}

	return false;
}

User CurrentUserAccounts::get_user(string username)
{
    throw Exception(NOT_YET_IMPLEMENTED);
}

void CurrentUserAccounts::display_users()
{
	for (vector<User>::iterator it = this->users.begin(); it != this->users.end(); ++it)
	{
		cout << it->get_username() << " " << it->get_type() << " " << it->get_credit() << endl;
	}
}

void CurrentUserAccounts::parse()
{
	/* Read the contents of the current user accounts and store each user */
	FileInputStream fis(this->cua_file);

	if (fis.good())
	{
		string read;
		RegularExpression re("^([A-Za-z0-9_]{1,15}?)_+(AA|FS|BS|SS)_([0-9]{6}\\.[0-9]{2})$");
		RegularExpression re_end("END_{16}0{6}\\.0{2}");
		RegularExpression::MatchVec matches;

		while (getline(fis, read))
		{
			/* Stop if END of file reached */
			if (re_end.match(read))
			{
				return;
			}

			/* Add each user found to the list of users */
			if (Validate::cua_entry(read))
			{
				re.match(read, 0, matches);

				/* Get each match from the entry in the file */
				string username = read.substr(matches[1].offset, matches[1].length);
				string type = read.substr(matches[2].offset, matches[2].length);
				double credit = NumberParser::parseFloat(read.substr(matches[3].offset, matches[3].length));

				/* Add the user to the list of users */
				this->users.push_back(User(username,type, credit));
			}
			/* Corrupted entry in file */
			else
			{
				throw Exception(CORRUPT_CUA);
			}
		}
	}

	/* No END of file identifier found or file corrupted */
	throw Exception(CORRUPT_CUA);
}
