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
#ifndef DELETE_HPP_
#define DELETE_HPP_

#include "Transaction.hpp"
#include "User.hpp"
#include "CurrentUserAccounts.hpp"
#include "Exception.hpp"
#include <string>

using namespace std;

/**
 * Delete Class
 *
 * Used for the delete transaction functions and attributes.
 */
class Delete : public Transaction
{
protected:
	/**
	 * save_transaction Virtual function signature used for
	 * interface creation in C++.
	 */
    virtual void save_transaction();

public:
	/**
	 * Delete The constructor for the class,
	 * requires a reference to the current user session.
	 * @param current_user
	 */
    Delete(User current_user);
   
    /**
     * process_username Validates and processes a username for
     * deletion.
     * @param username The username to delete.
     * @param user_accounts A handle to the current user accounts.
     */
    void process_username(string username, CurrentUserAccounts user_accounts);
};
#endif /* DELETE_HPP_ */
