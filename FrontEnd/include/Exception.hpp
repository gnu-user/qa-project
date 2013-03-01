#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <string>
#include <map>

using namespace std;

/**
 * Exception codes used for various error messages throughout the program.
 */
enum exception_codes {
    ALREADY_LOGIN,         //!< ALREADY_LOGIN User is already logged in.
    DELETE_SELF,           //!< DELETE_SELF Cannot delete a user account that is logged in.
    INVALID_PRIV,          //!< INVALID_PRIV Insufficient privileges to execute transaction.
    MUST_LOGIN,            //!< MUST_LOGIN User must be logged in.
    ATF_NOT_FOUND,         //!< ATF_NOT_FOUND Available tickets file not found.
    CUA_NOT_FOUND,         //!< CUA_NOT_FOUND Current user accounts file not found.
    CORRUPT_ATF,           //!< CORRUPT_ATF Available tickets file corrupted.
    CORRUPT_CUA,           //!< CORRUPT_CUA Current user accounts file corrupted.
    DTF_WRITE_ERROR,       //!< DTF_WRITE_ERROR Error writing the daily transaction file.
    INVALID_USER,          //!< INVALID_USER Invalid user specified.
    UNKNOWN_USER,          //!< UNKNOWN_USER User specified is unknown.
    INVALID_USER_TYPE,     //!< INVALID_USER_TYPE Invalid user type.
    INVALID_USER_LENGTH,   //!< INVALID_USER_LENGTH Invalid user name specified, length is invalid.
    INVALID_USER_RESERVED, //!< INVALID_USER_RESERVED Invalid user name specified, contains reserved word.
    INVALID_USER_EXISTS,   //!< INVALID_USER_EXISTS Invalid user specified, user already exists.
    SELLER_IS_SELF,        //!< SELLER_IS_SELF Trying to purchase tickets from yourself.
    TITLE_NOT_FOUND,       //!< TITLE_NOT_FOUND Event title not found.
    SELLER_NOT_FOUND,      //!< SELLER_NOT_FOUND The seller was not found selling any tickets
    TICKET_NOT_FOUND,      //!< TICKET_NOT_FOUND Ticket not found for sale by seller specified.
    INVALID_TITLE,         //!< INVALID_TITLE Invalid title specified.
    INVALID_TITLE_LENGTH,  //!< INVALID_TITLE_LENGTH Invalid title specified, length is invalid.
    INVALID_TITLE_RESERVED,//!< INVALID_TITLE_RESERVED Invalid title specified, contains reserved word.
    INVALID_AMOUNT,        //!< INVALID_AMOUNT Invalid value specified, amount must be in dollars.
    NEGATIVE_AMOUNT,       //!< NEGATIVE_AMOUNT Invalid value specified, amount must be positive.
    CREDIT_AMOUNT_OVERFLOW,//!< CREDIT_AMOUNT_OVERFLOW Invalid credit amount specified, amount cannot exceed 1000.00.
    SALE_PRICE_OVERFLOW,   //!< SALE_PRICE_OVERFLOW Invalid sale price specified, amount cannot exceed 999.99.
    USER_CREDIT_OVERFLOW,  //!< USER_CREDIT_OVERFLOW User credit cannot exceed 999999.99.
    INVALID_TICKET_VOLUME, //!< INVALID_TICKET_VOLUME Invalid ticket volume specified, volume must be an integer value.
    TICKET_VOLUME_NEGATIVE,//!< TICKET_VOLUME_NEGATIVE Invalid ticket volume specified, volume must be a positive value.
    TICKET_VOLUME_OVERFLOW,//!< TICKET_VOLUME_OVERFLOW Ticket volume cannot exceed 100.
    TICKET_VOLUME_USER_MAX,//!< TICKET_VOLUME_USER_MAX Non-admin users cannot purchase more than 4 tickets per session.
    ONE_SELL_PER_SESSION,  //!< ONE_SELL_PER_SESSION Only one sell transaction may occur per session.
    PURCHASE_CANCELED,    //!< PURCHASE_CANCELLED User canceled the ticket purchase
    INVALID_CONFIRMATION,  //!< INVALID_CONFIRMATION Confirmation must be 'yes' or 'no'.
    NOT_YET_IMPLEMENTED    //!< NOT_YET_IMPLEMENTED Exception used for anything not implemented yet.
};

/**
 *  Exception Class
 *
 *  Used for all exceptions within every transaction, and provides
 *  functions for providing diagnostic output.
 */
class Exception
{
private:
	/**
	 * code_msg Maps the transaction error codes to error messages.
	 */
    map<exception_codes, string> code_msg = {
        {ALREADY_LOGIN, "Invalid transaction, you are already logged in."},
        {DELETE_SELF, "Invalid transaction, you cannot delete yourself."},
        {INVALID_PRIV, "Invalid transaction, you do not have the necessary privileges."},
        {MUST_LOGIN, "Invalid transaction, only login accepted."},
        {ATF_NOT_FOUND, "Available tickets file not found, check arguments provided."},
        {CUA_NOT_FOUND, "Current user accounts file not found, check arguments provided."},
        {CORRUPT_ATF, "An error occurred reading the available tickets file, data corrupted."},
        {CORRUPT_CUA, "An error occurred reading the current user account file, data corrupted."},
        {DTF_WRITE_ERROR, "An error occurred writing the daily transaction file."},
        {INVALID_USER, "Invalid username."},
        {UNKNOWN_USER, "Invalid username, username does not exist."},
        {INVALID_USER_TYPE, "Invalid user type, type specified does not exist."},
        {INVALID_USER_LENGTH, "Invalid username, username cannot exceed 15 characters."},
        {INVALID_USER_RESERVED, "Invalid username, username cannot be \"END\"."},
        {INVALID_USER_EXISTS, "Invalid username, user already exists."},
        {SELLER_IS_SELF, "Invalid username, you cannot purchase tickets from yourself."},
        {TITLE_NOT_FOUND, "Invalid event title, event title does not exist."},
        {SELLER_NOT_FOUND, "Invalid seller username, seller is not selling any tickets."},
        {TICKET_NOT_FOUND, "Tickets not found, specified seller is not selling tickets to that event."},
        {INVALID_TITLE, "Invalid event title."},
        {INVALID_TITLE_LENGTH, "Invalid event title, event title cannot exceed 19 characters."},
        {INVALID_TITLE_RESERVED, "Invalid event title, event title cannot contain the word \"END\"."},
        {INVALID_AMOUNT, "Invalid value, amount must be in dollars (e.g. 10.00)."},
        {NEGATIVE_AMOUNT, "Invalid value, amount cannot be less than 0.00."},
        {CREDIT_AMOUNT_OVERFLOW, "Invalid credit value, amount cannot exceed 1000.00."},
        {SALE_PRICE_OVERFLOW, "Invalid sale price, amount cannot exceed 999.99." },
        {USER_CREDIT_OVERFLOW, "Invalid credit amount, user credit cannot exceed 999999.99."},
        {INVALID_TICKET_VOLUME, "Invalid number of tickets, volume must be an integer value (e.g. 25)."},
        {TICKET_VOLUME_NEGATIVE, "Invalid number of tickets, volume cannot be less than 0."},
        {TICKET_VOLUME_OVERFLOW, "Invalid number of tickets, volume cannot exceed 100."},
        {TICKET_VOLUME_USER_MAX, "Invalid number of tickets, cannot purchase more than 4 tickets."},
        {ONE_SELL_PER_SESSION, "Invalid transaction, only one sell transaction per session accepted."},
        {PURCHASE_CANCELED, "Ticket purchase transaction canceled."},
        {INVALID_CONFIRMATION, "Invalid confirmation, please enter \"yes\" or \"no\"."},
        {NOT_YET_IMPLEMENTED, "Not yet implemented"}
    };
    exception_codes code;

public:
    /**
     * Exception The constructor for the class, requires an exception code.
     * @param code The exception code to use.
     */
    Exception(exception_codes code);

    /**
     * mesg Outputs an exception message to the console.
     * @return Returns an exception string.
     */
    string mesg();
};

#endif /* EXCEPTION_HPP_ */
