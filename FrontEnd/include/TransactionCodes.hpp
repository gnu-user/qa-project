/*
 * TransactionCodes.hpp
 *
 *  Created on: Feb 23, 2013
 *      Author: jon
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
