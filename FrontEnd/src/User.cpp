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
#include "../include/User.hpp"
#include <algorithm>

User::User()
{
    this->login_status = false;
}

User::User(string username, string type, double credit)
{
    /* Throws an error if invalid user type specified */
    if (this->permissions.find(type) != this->permissions.end())
    {
        this->username = username;
        this->type = type;
        this->credit = credit;
        this->login_status = false;
    }
    else
    {
        throw Exception(INVALID_USER_TYPE);
    }
}

string User::get_username()
{
    return username;
}

string User::get_type()
{
    return type;
}

double User::get_credit()
{
    return credit;
}

bool User::get_status()
{
    return login_status;
}

void User::login()
{
    this->login_status = true;
}

void User::logout()
{
    this->login_status = false;
}


bool User::has_permissions(string transaction)
{
    vector<string> user_perms = permissions[type];

    if(find(user_perms.begin(), user_perms.end(), transaction) != user_perms.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}
