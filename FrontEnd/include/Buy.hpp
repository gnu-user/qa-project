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
#ifndef BUY_HPP_
#define BUY_HPP_

#include "Transaction.hpp"
#include "User.hpp"
#include "Ticket.hpp"
#include "AvailableTickets.hpp"
#include "Exception.hpp"
#include <string>

using namespace std;

/**
 * Buy Class
 *
 * Used for the Buy transaction functions and attributes.
 */
class Buy : public Transaction
{
private:
	/**
	 * ticket Stores a pointer to the ticket being purchased.
	 * title Stores the title of the event for purchase.
	 * volume Stores the volume of tickets to purchase.
	 * seller Stores the name of the seller for the transaction.
	 */
    Ticket ticket;
    string title;
    int volume;
    string seller;

protected:
    virtual void save_transaction();

public:
    /**
     * Buy The constructor for the class, requires a reference to the
     * current user who is initiating the transaction.
     * @param current_user
     */
    Buy(User current_user);
   
    /**
     * process_title Validates and processes the transaction based on the
     * event title specified.
     * @param title The event title for the tickets being purchased.
     * @param available_tickets A handle to the available tickets.
     */
    void process_title(string title, AvailableTickets available_tickets);
   
    /**
     * process_volume Validates and processes the volume of tickets being
     * purchased.
     * @param volume The number of tickets being purchased.
     */
    void process_volume(string volume);
   
    /**
     * process_seller Validates and processes the specified seller for the
     * transaction.
     * @param username The seller's username.
     * @param available_tickets A handle to the available tickets.
     */
    void process_seller(string username, AvailableTickets available_tickets);
   
    /**
     * display_cost displays the cost per ticket and a total summary of the
     * cost of the tickets.
     */
    void display_cost();

    /**
     * process_confirmation Validates and processes the confirmation input
     * for whether the user accepts the transaction.
     * @param confirm The confirmation, either 'yes' or 'no'.
     */
    void process_confirmation(string confirm);
};
#endif /* BUY_HPP_ */
