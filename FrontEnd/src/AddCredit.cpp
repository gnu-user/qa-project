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
#include "../include/AddCredit.hpp"
#include "../include/Validate.hpp"
#include <iostream>

using namespace std;

AddCredit::AddCredit(User current_user)
{
    /* If the user has not logged in throw exception */
    if (! current_user.get_status())
    {
        throw Exception(MUST_LOGIN);
    }

    /* Verify the user has the necessary privileges */
    if (! current_user.has_permissions("addcredit"))
    {
        throw Exception(INVALID_PRIV);
    }

    this->code = "06";
    this->user = current_user;
}

void AddCredit::process_credit(string credit)
{
    double tmp_credit = 0.0;

    try
    {
        /* Validate the credit is in dollars amount */
        if (Validate::dollars(credit, tmp_credit))
        {
            /* Verify credit amount added does not exceed maximum, 1000.00 */
            if (tmp_credit <= 1000.00)
            {
                this->credit = tmp_credit;
            }
            else
            {
                throw Exception(CREDIT_AMOUNT_OVERFLOW);
            }
        }
    }
    /* Catch any exceptions and throw them to the calling function */
    catch (Exception& e)
    {
        throw e;
    }
}

void AddCredit::process_username(CurrentUserAccounts user_accounts)
{
    string input;

    /* If the user is an admin, as for the username */
    if (user.get_type().compare("AA") == 0)
    {
        cout << "Enter the username to which credit is being added: ";
        getline(cin, input);
    }
    else
    {
        save_transaction();
        return;
    }

    try
    {
        /* Attempt to validate the username, throw exception if invalid */
        if (Validate::username(input))
        {
            /* Check that the username exists */
            if (user_accounts.has_user(input))
            {
                    this->user = user_accounts.get_user(input);
                    save_transaction();
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


void AddCredit::save_transaction()
{
    this->transaction = format(
                            code,
                            user.get_username(),
                            user.get_type(),
                            credit
                        );
}
