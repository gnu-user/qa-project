/**
 * Swift Ticket -- Front End Interface
 *
 * Copyright (C) 2013, Jonathan Gillett, Daniel Smullen, and Rayan Alfaheid
 * All rights reserved.
 *
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "../include/CurrentUserAccounts.hpp"
#include "../include/Validate.hpp"
#include "Poco/File.h"
#include "Poco/Path.h"
#include "Poco/FileStream.h"
#include "Poco/RegularExpression.h"
#include "Poco/NumberParser.h"
#include <cassert>
#include <iostream>

using namespace std;
using Poco::File;
using Poco::Path;
using Poco::FileInputStream;
using Poco::RegularExpression;
using Poco::NumberParser;

CurrentUserAccounts::CurrentUserAccounts()
{

}

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
    for (vector<User>::iterator it = users.begin(); it != users.end(); ++it)
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
    for (vector<User>::iterator it = users.begin(); it != users.end(); ++it)
    {
        if (it->get_username().compare(username) == 0)
        {
            return *it;
        }
    }

    throw Exception(UNKNOWN_USER);
}

void CurrentUserAccounts::display_users()
{
    for (vector<User>::iterator it = users.begin(); it != users.end(); ++it)
    {
        cout << it->get_username() << " " << it->get_type() << " "
             << it->get_credit() << endl;
    }
}

void CurrentUserAccounts::parse()
{
    /* Read the contents of the current user accounts and store each user */
    FileInputStream fis(cua_file);

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
