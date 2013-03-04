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
#ifndef TRANSACTION_HPP_
#define TRANSACTION_HPP_

#include "User.hpp"
#include "Exception.hpp"
#include <string>

using namespace std;

/**
 * Transaction Class
 *
 * Acts as a superclass for the other transaction classes.
 */
class Transaction
{

protected:
    /**
     * user Stores the user who performed the transaction.
     * code Stores the transaction code.
     * transaction Stores the formatted transaction string.
     */
    User user;
    string code;
    string transaction;
   
    /**
     * save_transaction Virtual function signature for
     * class abstraction in C++.
     */
    virtual void save_transaction();

    /**
     * format Formats transactions which require the usage of a user name, type,
     * and credit amount.
     * @param code The transaction code for the transaction.
     * @param username The username specified for the transaction.
     * @param type The type of user for the transaction.
     * @param credit The credit amount for the transaction.
     * @return Returns a formatted transaction string containing all arguments.
     */
    string format(string code, string username, string type, double credit);

    /**
     * format Formats transactions which require the usage of a user name, type,
     * seller, and credit amount.
     * @param code The transaction code for the transaction.
     * @param username The user name specified for the transaction.
     * @param type The type of user for the transaction.
     * @param seller The seller user name specified for the transaction.
     * @param refund The credit amount for the transaction.
     * @return Returns a formatted transaction string containing all arguments.
     */
    string format(string code, string username, string type, string seller, double refund);

    /**
     * format Formats transactions which require the usage of an event title,
     * seller user name, ticket volume, and price.
     * @param code The transaction code for the transaction.
     * @param event The event title specified for the transaction.
     * @param seller The seller user name specified for the transaction.
     * @param volume The number of tickets in the transaction.
     * @param price The price of the tickets in the transaction, in dollars.
     * @return Returns a formatted transaction string containing all arguments.
     */
    string format(string code, string event, string seller, int volume, double price);

public:
    /**
     * get_transaction Provides the stored formatted transaction string
     * for any transaction.
     * @return Returns the formatted transaction string.
     */
    string get_transaction();
};
#endif /* TRANSACTION_HPP_ */
