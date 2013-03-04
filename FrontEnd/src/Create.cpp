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
#include "../include/Create.hpp"
#include "../include/User.hpp"
#include "../include/Validate.hpp"

Create::Create(User current_user)
{
    /* If the user has not logged in throw exception */
    if (! current_user.get_status())
    {
        throw Exception(MUST_LOGIN);
    }

    /* Verify the user has the necessary privileges */
    if (! current_user.has_permissions("create"))
    {
        throw Exception(INVALID_PRIV);
    }

    this->code = "01";
}

void Create::process_username(string username, CurrentUserAccounts user_accounts)
{
    try
    {
        /* Attempt to validate the username, throw exception if invalid */
        if (Validate::username(username))
        {
            /* Accept the new username if it is unique */
            if (! user_accounts.has_user(username))
            {
                this->new_username = username;
            }
            else
            {
                throw Exception(INVALID_USER_EXISTS);
            }
        }
        else
        {
            throw Exception(INVALID_USER);
        }
    }
    /* Catch any exceptions and throw them to the calling function */
    catch (Exception& e)
    {
        throw e;
    }
}

void Create::process_type(string type)
{
    /* If the user type matches one of the types supported, create user */
    if (account_types.find(type) != account_types.end())
    {
        this->user = User(new_username, account_types[type], 0.0);
        save_transaction();
    }
    else
    {
        throw Exception(INVALID_USER_TYPE);
    }
}

void Create::save_transaction()
{
    this->transaction = format(
                            code,
                            user.get_username(),
                            user.get_type(),
                            user.get_credit()
                        );
}
