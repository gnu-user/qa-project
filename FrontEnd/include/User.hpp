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
#ifndef USER_HPP_
#define USER_HPP_

#include "Exception.hpp"
#include <string>
#include <vector>
#include <map>

using namespace std;

/**
 * User Class
 *
 * Used for storing user data, and provides functions for interacting with them.
 */
class User
{

private:
    /**
     * username Stores the user name string.
     * type Stores the user type.
     * credit Stores the user's credit amount.
     * login_status Stores whether the user is logged in. True if logged in false, if not.
     */
    string username;
    string type;
    double credit;
    bool login_status;

    /**
     * permissions Maps the user types to allowed transaction permissions.
     */
    map<string, vector<string>> permissions = {
        {"AA", {"login", "logout", "create", "delete", "sell", "buy", "refund", "addcredit"}},
        {"FS", {"login", "logout", "sell", "buy", "addcredit"}},
        {"BS", {"login", "logout", "buy", "addcredit"}},
        {"SS", {"login", "logout", "sell", "addcredit"}}
    };


public:
    /* Default nullary constructor */
    User();

    /**
     * User The constructor for the class, requires all class attributes to be defined.
     * @param username The specified user name.
     * @param type The user type for the account.
     * @param credit The amount of credit for the user.
     */
    User(string username, string type, double credit);
   
    /**
     * get_username Access method for the user's name attribute.
     * @return Returns the user's name as a string.
     */
    string get_username();
   
    /**
     * get_type Access method for the user's type.
     * @return Returns the user's type, as a string.
     */
    string get_type();
   
    /**
     * get_credit Access method for the user's credit amount.
     * @return Returns the user's credit amount, in dollars.
     */
    double get_credit();

    /**
     * get_status Returns the login status of the user.
     * @return Returns true if the user is logged in. False if not.
     */
    bool get_status();
   
    /**
     * login Changes the user's login_status attribute to true. The user
     * is now logged in.
     */
    void login();

    /**
     * logout Changes the user's login_status attribute to false. The user
     * is now logged out.
     */
    void logout();

    /**
     * has_permissions Determines whether a user has permissions to execute
     * a specified transaction.
     * @param transaction The specified transaction to determine permissions.
     * @return Returns true if the user has the appropriate permissions
     * to execute the transaction, false if not.
     */
    bool has_permissions(string transaction);
};
#endif /* USER_HPP_ */
