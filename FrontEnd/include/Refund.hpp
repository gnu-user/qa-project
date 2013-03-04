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
#ifndef REFUND_HPP_
#define REFUND_HPP_

#include "Transaction.hpp"
#include "User.hpp"
#include "CurrentUserAccounts.hpp"
#include "AvailableTickets.hpp"
#include "Exception.hpp"
#include <string>

using namespace std;

/**
 * Refund Class
 *
 * Used for the refund transaction functions and attributes.
 */
class Refund : public Transaction
{

private:
    /**
     * buyer Contains the buyer for the original sale to be refunded.
     * seller Contains the seller for the refund.
     * credit Contains the amount of credit to refund to the buyer,
     * in dollars.
     */
    string buyer;
    string seller;
    double credit;

protected:
    /**
     * save_transaction Virtual function signature for class
     * abstraction in C++.
     */
    virtual void save_transaction();

public:
    /**
     * Refund The constructor for the class, requires a handle to
     * the current user logged in.
     * @param current_user A handle to the current user logged in.
     */
    Refund(User current_user);
   
    /**
     * process_buyer Validates and processes the specified buyer for
     * the refund.
     * @param buyer The buyer for the sale to be refunded.
     * @param user_accounts A handle to the current user accounts.
     */
    void process_buyer(string buyer, CurrentUserAccounts user_accounts);
   
    /**
     * process_seller Validates and processes the specified seller for
     * the refund.
     * @param seller The seller for the sale to be refunded.
     * @param user_accounts A handle to the current user accounts.
     */
    void process_seller(string seller, CurrentUserAccounts user_accounts);
   
    /**
     * process_credit Validates and processes the specified amount
     * for the refund.
     * @param credit The specified refund amount, in dollars.
     */
    void process_credit(string credit);
};
#endif /* REFUND_HPP_ */
