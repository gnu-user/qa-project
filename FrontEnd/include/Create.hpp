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
#ifndef CREATE_HPP_
#define CREATE_HPP_

#include "Transaction.hpp"
#include "User.hpp"
#include "CurrentUserAccounts.hpp"
#include "Exception.hpp"
#include <string>
#include <map>

using namespace std;

/**
 * Create Class
 *
 * Used for the create transaction functions and attributes.
 */
class Create : public Transaction
{

private:
	/**
	 * types Stores the types of usernames that can be used.
	 * new_username Stores the new username to create.
	 */
    map<string, string> account_types = {
            {"admin", "AA"},
            {"full-standard", "FS"},
            {"buy-standard", "BS"},
            {"sell-standard", "SS"}
    };
    string new_username;

protected:
    virtual void save_transaction();

public:
    /**
     * Create The constructor for the class, requires a reference to the
     * current user initiating the transaction.
     * @param current_user
     */
    Create(User current_user);
   
    /**
     * process_username Validates and processes the username entered for
     * creation.
     * @param username The username to create.
     * @param user_accounts A handle to the current user accounts.
     */
    void process_username(string username, CurrentUserAccounts user_accounts);
   
    /**
     * process_type Validates and processes the type of user account
     * specified for creation.
     * @param type The type of user account to create.
     */
    void process_type(string type);
};
#endif /* CREATE_HPP_ */
