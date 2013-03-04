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
#include "../include/Buy.hpp"
#include "../include/Validate.hpp"
#include <iostream>
#include <iomanip>

using namespace std;
using std::showpoint;

Buy::Buy(User current_user)
{
    /* If the user has not logged in throw exception */
    if (! current_user.get_status())
    {
        throw Exception(MUST_LOGIN);
    }

    /* Verify the user has the necessary privileges */
    if (! current_user.has_permissions("buy"))
    {
        throw Exception(INVALID_PRIV);
    }

    this->code = "04";
    this->user = current_user;
}

void Buy::process_title(string title, AvailableTickets available_tickets)
{
    try
    {
        /* Attempt to validate the event title, throw exception if invalid */
        if (Validate::title(title))
        {
            /* If the event title exists, set the title */
            if (available_tickets.has_event(title))
            {
                this->title = title;
            }
            else
            {
                throw Exception(TITLE_NOT_FOUND);
            }
        }
        else
        {
            throw Exception(INVALID_TITLE);
        }
    }
    /* Catch any exceptions and throw them to the calling function */
    catch (Exception& e)
    {
        throw e;
    }
}

void Buy::process_volume(string volume)
{
    int tmp_volume = 0;

    try
    {
        /* Validate the volume is a valid integer */
        if (Validate::volume(volume, tmp_volume))
        {
            /* Verify the number of tickets puchased by buy/full-standard is within the limits */
            if ( (user.get_type().compare("BS") == 0 || user.get_type().compare("FS") == 0)
                 && tmp_volume <= 4 )
            {
                this->volume = tmp_volume;
            }
            /* There are no limits on the number of tickets an admin can purchase */
            else if (user.get_type().compare("AA") == 0)
            {
                this->volume = tmp_volume;
            }
            else
            {
                throw Exception(TICKET_VOLUME_USER_MAX);
            }
        }
    }
    /* Catch any exceptions and throw them to the calling function */
    catch (Exception& e)
    {
        throw e;
    }
}

void Buy::process_seller(string username, AvailableTickets available_tickets)
{
    try
    {
        /* Attempt to validate the username, throw exception if invalid */
        if (Validate::username(username))
        {
            /* Verify not purchasing tickets from self */
            if (user.get_username().compare(username) == 0)
            {
                throw Exception(SELLER_IS_SELF);
            }

            /* Check that the seller has tickets listed */
            if (available_tickets.has_seller(username))
            {
                /* Attempt to get a ticket with title provided being sold by seller */
                this->ticket = available_tickets.get_ticket(title, username);
                this->seller = username;
                display_cost();
            }
            else
            {
                throw Exception(SELLER_NOT_FOUND);
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

void Buy::display_cost()
{
    cout << fixed << showpoint << setprecision(2)
         << "Cost per ticket: $" << ticket.get_price() << endl
         << "Total cost of tickets: $" << volume * ticket.get_price() << endl;
}

void Buy::process_confirmation(string confirm)
{
    if (confirm.compare("yes") == 0)
    {
        save_transaction();
    }
    else if (confirm.compare("no") == 0)
    {
        throw Exception(PURCHASE_CANCELED);
    }
    else
    {
        throw Exception(INVALID_CONFIRMATION);
    }
}

void Buy::save_transaction()
{
    this->transaction = format(
                            code,
                            ticket.get_event(),
                            seller,
                            volume,
                            ticket.get_price()
                        );
}
