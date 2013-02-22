/*
 * Exception.hpp
 *
 *  Created on: Feb 22, 2013
 *      Author: jon
 */

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <string>
#include <map>

using namespace std;

enum exception_codes {
	ALREADY_LOGIN,
	DELETE_SELF,
	INVALID_PRIV,
	MUST_LOGIN,
	ATF_NOT_FOUND,			// Available tickets file not found
	CUA_NOT_FOUND,			// Current user accounts file not found
	CORRUPT_ATF,			// Available tickets file corrupted
	CORRUPT_CUA,			// Current user accounts file corrupted
	INVALID_USER,
	UNKNOWN_USER,
	INVALID_USER_LENGTH,
	INVALID_USER_RESERVED,	// Exception for a user with reserved word, like "END"
	INVALID_USER_EXISTS,
	SELLER_IS_SELF,			// Trying to purchase tickets from yourself
	TITLE_NOT_FOUND,		// Event title not found
	INVALID_TITLE_LENGTH,
	INVALID_TITLE_RESERVED,
	INVALID_SALE_PRICE,		// Ticket sale price, must be dollars
	INVALID_CREDIT_AMOUNT,	// Credit amount must be in dollars
	SALE_PRICE_NEGATIVE,	// Ticket sale price, must be positive
	CREDIT_AMOUNT_NEGATIVE,	// Credit amount, must be positive
	CREDIT_AMOUNT_OVERFLOW, // Credit amount, cannot exceed 1000.00
	SALE_PRICE_OVERFLOW,	// Sale price, cannot exceed 999.99
	USER_CREDIT_OVERFLOW,	// User credit cannot exceed 999999.99.
	INVALID_TICKET_VOLUME,  // Volume must be an integer value
	TICKET_VOLUME_NEGATIVE, // Volume cannot be less than 0
	TICKET_VOLUME_OVERFLOW, // Volume cannot exceed 100.
	TICKET_VOLUME_USER_MAX, // Non-admin users cannot purchase more than 4 tickets
	ONE_SELL_PER_SESSION,	// Only one sell transaction per session
	INVALID_CONFIRMATION	// Confirmation must be yes/no
};

class Exception
{
private:
	map<exception_codes, string> code_msg_map {
		{ALREADY_LOGIN, "Invalid transaction, you are already logged in."},
		{DELETE_SELF, "Invalid transaction, you can not delete yourself."},
		{INVALID_PRIV, "Invalid transaction, you do not have the necessary privileges."},
		{MUST_LOGIN, "Invalid transaction, only login accepted."},
		{ATF_NOT_FOUND, "Available tickets file not found, check arguments provided."},
		{CUA_NOT_FOUND, "Current user accounts file not found, check arguments provided."},
		{CORRUPT_ATF, "An error occurred reading the available tickets file, data corrupted."},
		{CORRUPT_CUA, "An error occurred reading the current user account file, data corrupted."},
		{INVALID_USER, "Invalid username."},
		{UNKNOWN_USER, "Invalid username, username does not exist."},
		{INVALID_USER_LENGTH, " Invalid username, username cannot exceed 15 characters."},
		{INVALID_USER_RESERVED, "Invalid username, username cannot be \"END\"."},
		{INVALID_USER_EXISTS, "Invalid username, user already exists."},
		{SELLER_IS_SELF, "Invalid username, you cannot purchase tickets from yourself."},
		{TITLE_NOT_FOUND, "Invalid event title, event title does not exist."},
		{INVALID_TITLE_LENGTH, "Invalid event title, event title cannot exceed 19 characters."},
		{INVALID_TITLE_RESERVED, "Invalid event title, event title cannot contain the word \"END\"."},
		{INVALID_SALE_PRICE, "Invalid sale price, amount must be in dollars (e.g. 10.00)."},
		{INVALID_CREDIT_AMOUNT, "Invalid credit value, amount must be in dollars (e.g. 10.00)."},
		{SALE_PRICE_NEGATIVE, "Invalid sale price, amount cannot be less than 0.00."},
		{CREDIT_AMOUNT_NEGATIVE, "Invalid credit value, amount cannot be less than 0.00."},
		{CREDIT_AMOUNT_OVERFLOW, " Invalid credit value, amount cannot exceed 1000.00."},
		{SALE_PRICE_OVERFLOW, "Invalid sale price, amount cannot exceed 999.99." },
		{USER_CREDIT_OVERFLOW, "Invalid credit amount, user credit cannot exceed 999999.99."},
		{INVALID_TICKET_VOLUME, "Invalid number of tickets, volume must be an integer value (e.g. 25)."},
		{TICKET_VOLUME_NEGATIVE, "Invalid number of tickets, volume cannot be less than 0."},
		{TICKET_VOLUME_OVERFLOW, "Invalid number of tickets, volume cannot exceed 100."},
		{TICKET_VOLUME_USER_MAX, "Invalid number of tickets, cannot purchase more than 4 tickets."},
		{ONE_SELL_PER_SESSION, "Invalid transaction, only one sell transaction per session accepted."},
		{INVALID_CONFIRMATION, "Invalid confirmation, please enter \"yes\" or \"no\"."}
	};
	exception_codes code;

public:
	Exception(exception_codes code);
	string mesg();
	virtual ~Exception();
};

#endif /* EXCEPTION_HPP_ */
