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
#include "../include/Sell.hpp"
#include "../include/Validate.hpp"

Sell::Sell(User current_user)
{
    /* If the user has not logged in throw exception */
    if (! current_user.get_status())
    {
        throw Exception(MUST_LOGIN);
    }

    /* If the user has already sold tickets this session throw exception */
    if (current_user.get_sell_status())
    {
        throw Exception(ONE_SELL_PER_SESSION);
    }

    /* Verify the user has the necessary privileges */
    if (! current_user.has_permissions("sell"))
    {
        throw Exception(INVALID_PRIV);
    }

    this->code = "03";
    this->user = current_user;
}

void Sell::process_title(string title)
{
    try
    {
        /* Attempt to validate the event title, throw exception if invalid */
        if (Validate::title(title))
        {
            this->title = title;
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

void Sell::process_price(string price)
{
    double tmp_price = 0.0;

    try
    {
        /* Validate the price is in dollars amount */
        if (Validate::dollars(price, tmp_price))
        {
            /* Verify ticket price is less than maximum, 999.99 */
            if (tmp_price <= 999.99)
            {
                this->price = tmp_price;
            }
            else
            {
                throw Exception(SALE_PRICE_OVERFLOW);
            }
        }
    }
    /* Catch any exceptions and throw them to the calling function */
    catch (Exception& e)
    {
        throw e;
    }
}

void Sell::process_volume(string volume)
{
    int tmp_volume = 0;

    try
    {
        /* Validate the volume is a valid integer */
        if (Validate::volume(volume, tmp_volume))
        {
            /* Verify the volume of tickets is less than maximum, 100 */
            if (tmp_volume <= 100)
            {
                this->volume = tmp_volume;
                save_transaction();
            }
            else
            {
                throw Exception(TICKET_VOLUME_OVERFLOW);
            }
        }
    }
    /* Catch any exceptions and throw them to the calling function */
    catch (Exception& e)
    {
        throw e;
    }
}

void Sell::save_transaction()
{
    this->transaction = format(
                            code,
                            title,
                            user.get_username(),
                            volume,
                            price
                        );
}
