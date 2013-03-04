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
#ifndef LOGOUT_HPP_
#define LOGOUT_HPP_

#include "Transaction.hpp"
#include "Exception.hpp"
#include "User.hpp"

/**
 * Logout Class
 *
 * Used for the logout transaction functions and attributes.
 */
class Logout : public Transaction
{
protected:
    /**
     * save_transaction Virtual function signature for
     * class abstraction in C++.
     */
    virtual void save_transaction();

public:
    /**
     * Logout The constructor for the class, requires a handle
     * to the current user logged in.
     * @param current_user The current user logged in, to be
     * logged out.
     */
    Logout(User current_user);
};
#endif /* LOGOUT_HPP_ */
