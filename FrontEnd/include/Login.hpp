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
#ifndef LOGIN_HPP_
#define LOGIN_HPP_

#include "Transaction.hpp"
#include "User.hpp"
#include "CurrentUserAccounts.hpp"
#include "Exception.hpp"
#include <string>

using namespace std;

/**
 *  Login Class
 *
 *  Used for the login transaction functions and attributes.
 */
class Login : public Transaction
{
protected:
    /**
     * save_transaction Virtual function signature for
     * class abstraction in C++.
     */
    virtual void save_transaction();

public:
    /**
     * Login The constructor for the class, requires a handle to the
     * current user logged in (if applicable).
     * @param current_user The current user logged in.
     */
    Login(User current_user);
   
    /**
     * process_username Validates and processes the username specified
     * to log in with.
     * @param username The username for the account to log in.
     * @param user_accounts A handle to the current user accounts.
     * @return Returns a User object for the user which was logged in, or
     * null if an exception occurs.
     */
    User process_username(string username, CurrentUserAccounts user_accounts);
};
#endif /* LOGIN_HPP_ */
