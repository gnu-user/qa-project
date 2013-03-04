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
#include "../include/Login.hpp"
#include "../include/Validate.hpp"

Login::Login(User current_user)
{
   if (current_user.get_status())
   {
       throw Exception(ALREADY_LOGIN);
   }
}

User Login::process_username(string username, CurrentUserAccounts user_accounts)
{
    try
    {
        /* Attempt to validate the username, throw exception if invalid */
        if (Validate::username(username))
        {
            /* If the username exists, set the user and save transaction */
            if (user_accounts.has_user(username))
            {
                this->user = user_accounts.get_user(username);
            }
            else
            {
                throw Exception(INVALID_USER);
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

    return user;
}

void Login::save_transaction()
{
    /* The login transaction is not recorded to the DTF, throw an exception */
    throw Exception(NOT_YET_IMPLEMENTED);
}
