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
#ifndef TICKET_HPP_
#define TICKET_HPP_

#include "Exception.hpp"
#include <string>

using namespace std;

/**
 * Ticket Class
 *
 * Used for storing ticket data, and provides functions for interacting with them.
 */
class Ticket
{

private:
    /**
     * event The event title for the tickets.
     * seller The seller of the tickets.
     * volume The amount of tickets available.
     * price The cost of the tickets in dollars.
     */
    string event;
    string seller;
    int volume;
    double price;

public:
    /* Default nullary constructor */
    Ticket();

    /**
     * Ticket The constructor for the class, requires all class attributes
     * to be defined.
     * @param event The event title for the tickets.
     * @param seller The seller of the tickets.
     * @param volume The amount of tickets available.
     * @param price The cost of the tickets in dollars.
     */
    Ticket(string event, string seller, int volume, double price);

    /**
     * get_event Access function for the event title.
     * @return Returns the event title as a string.
     */
    string get_event();
   
    /**
     * get_seller Access function for the seller.
     * @return Returns the seller as a string.
     */
    string get_seller();
   
    /**
     * get_volume Access function for the ticket volume.
     * @return Returns the amount of tickets available as an integer.
     */
    int get_volume();
   
    /**
     * get_price Access function for the ticket price.
     * @return Returns the cost of the tickets, in dollars.
     */
    double get_price();
};
#endif /* TICKET_HPP_ */
