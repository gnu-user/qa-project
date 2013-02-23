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

/* Enumeration of the available front end transactions codes */
enum transaction_codes {
			_undefined,
			_login,
			_logout,
			_create,
			_delete,
			_sell,
			_buy,
			_refund,
			_addcredit
};

/* Mapping of each transaction as a string to the transaction code */
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
