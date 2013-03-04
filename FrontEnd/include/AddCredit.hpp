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
#ifndef ADDCREDIT_HPP_
#define ADDCREDIT_HPP_

#include "Transaction.hpp"
#include "CurrentUserAccounts.hpp"
#include "User.hpp"
#include "Exception.hpp"
#include <string>

using namespace std;

/**
 * AddCredit Class
 *
 * Used for the AddCredit transaction functions and attributes.
 */
class AddCredit : public Transaction
{
private:
	/**
	 * credit Stores the amount of credit to add.
	 */
    double credit;

protected:
    virtual void save_transaction();

public:
    /**
     * AddCredit The constructor for the class, requires a user specified to add the credit to.
     * @param current_user The user to add the credit specified to.
     */
    AddCredit(User current_user);

    /**
     * process_credit Performs the addition of the credit to the previously specified user account.
     * @param credit The actual amount of credit to add.
     */
     void process_credit(string credit);

   /**
    * process_username Determines the validity of the username specified, and processes that component of the transaction.
    * @param user_accounts Provides a handle to the current user accounts object.
    */
    void process_username(CurrentUserAccounts user_accounts);
};
#endif /* ADDCREDIT_HPP_ */
