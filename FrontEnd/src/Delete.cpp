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
#include "../include/Delete.hpp"
#include "../include/Validate.hpp"

Delete::Delete(User current_user)
{
    /* If the user has not logged in throw exception */
    if (! current_user.get_status())
    {
        throw Exception(MUST_LOGIN);
    }

    /* Verify the user has the necessary privileges */
    if (! current_user.has_permissions("delete"))
    {
        throw Exception(INVALID_PRIV);
    }

    this->code = "02";
    this->user = current_user;
}

// TODO Possibly add support for deleting any outstanding tickets after a
// user has been deleted. I think this REALLY is the backend's responsibility...
void Delete::process_username(string username, CurrentUserAccounts user_accounts)
{
    try
    {
        /* Attempt to validate the username, throw exception if invalid */
        if (Validate::username(username))
        {
            /* Check that the username exists */
            if (user_accounts.has_user(username))
            {
                /* Verify not deleting self, set user to delete as user specified */
                if (user.get_username().compare(username) != 0)
                {
                    this->user = user_accounts.get_user(username);
                    save_transaction();
                }
                else
                {
                    throw Exception(DELETE_SELF);
                }
            }
            else
            {
                throw Exception(UNKNOWN_USER);
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

void Delete::save_transaction()
{
    this->transaction = format(
                            code,
                            user.get_username(),
                            user.get_type(),
                            user.get_credit()
                        );
}
