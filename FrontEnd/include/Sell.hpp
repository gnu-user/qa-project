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
#ifndef SELL_HPP_
#define SELL_HPP_

#include "Transaction.hpp"
#include "User.hpp"
#include "Ticket.hpp"
#include "Exception.hpp"
#include <string>

using namespace std;

/**
 * Sell Class
 *
 * Used for the sell transaction functions and attributes.
 */
class Sell : public Transaction
{

private:
    /**
     * ticket Contains the ticket to be sold.
     * title Contains the title for the ticket sale.
     * price Contains the price for the ticket sales.
     * volume Contains the volume of tickets to sell.
     */
    Ticket ticket;
    string title;
    double price;
    int volume;

protected:
    /**
     * save_transaction Virtual function signature for
     * class abstraction in C++.
     */
    virtual void save_transaction();

public:
    /**
     * Sell The constructor of the function, requires a handle
     * to the current user logged in.
     * @param current_user A handle to the current user.
     */
    Sell(User current_user);
   
    /**
     * process_title Validates and processes the title for the
     * ticket sale.
     * @param title The title for the event tickets being sold.
     */
    void process_title(string title);
   
    /**
     * process_price Validates and processes the specified price
     * for the tickets.
     * @param price The price, in dollars, for the tickets being sold.
     */
    void process_price(string price);
   
    /**
     * process_volume Validates and processes the specified number
     * of tickets to be sold.
     * @param volume The number of tickets to be sold.
     */
    void process_volume(string volume);
};
#endif /* SELL_HPP_ */
