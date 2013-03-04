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
#ifndef TRANSACTIONCODES_HPP_
#define TRANSACTIONCODES_HPP_

#include <map>

using namespace std;

/**
 * Transaction codes used for the transactions supported.
 */
enum transaction_codes {
            _undefined,//!< _undefined Used for undefined transactions.
            _login,    //!< _login Used for the login transaction.
            _logout,   //!< _logout Used for the logout transaction.
            _create,   //!< _create Used for the create transaction.
            _delete,   //!< _delete Used for the delete transaction.
            _sell,     //!< _sell Used for the sell transaction.
            _buy,      //!< _buy Used for the buy transaction.
            _refund,   //!< _refund Used for the refund transaction.
            _addcredit //!< _addcredit used for the add credit transaction.
};

/**
 * map_code Maps each transaction code to a transaction string.
 */
static map<string, transaction_codes> map_code = {
            {"login", _login},
            {"logout", _logout},
            {"create", _create},
            {"delete", _delete},
            {"sell", _sell },
            {"buy", _buy},
            {"refund", _refund},
            {"addcredit", _addcredit}
};


#endif /* TRANSACTIONCODES_HPP_ */
