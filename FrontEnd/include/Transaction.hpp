#ifndef TRANSACTION_HPP_
#define TRANSACTION_HPP_

#include "User.hpp"
#include "Exception.hpp"
#include <string>

using namespace std;

/**
 * Transaction Class
 *
 * Acts as a superclass for the other transaction classes.
 */
class Transaction
{

protected:
    /**
     * user Stores the user who performed the transaction.
     * code Stores the transaction code.
     * transaction Stores the formatted transaction string.
     */
    User user;
    string code;
    string transaction;
   
    /**
     * save_transaction Virtual function signature for
     * class abstraction in C++.
     */
    virtual void save_transaction();

    /* Transaction formatting helpers, overloads for each type of transaction format */
    // TODO fix this, have two overloads that are the same... not possible
    /**
     * format Formats transactions which require the usage of a user name, type,
     * and credit amount.
     * @param code The transaction code for the transaction.
     * @param username The username specified for the transaction.
     * @param type The type of user for the transaction.
     * @param credit The credit amount for the transaction.
     * @return Returns a formatted transaction string containing all arguments.
     */
    string format(string code, string username, string type, double credit);

    /**
     * format Formats transactions which require the usage of a user name, type,
     * seller, and credit amount.
     * @param code The transaction code for the transaction.
     * @param username The user name specified for the transaction.
     * @param type The type of user for the transaction.
     * @param seller The seller user name specified for the transaction.
     * @param refund The credit amount for the transaction.
     * @return Returns a formatted transaction string containing all arguments.
     */
    string format(string code, string username, string type, string seller, double refund);

    /**
     * format Formats transactions which require the usage of an event title,
     * seller user name, ticket volume, and price.
     * @param code The transaction code for the transaction.
     * @param event The event title specified for the transaction.
     * @param seller The seller user name specified for the transaction.
     * @param volume The number of tickets in the transaction.
     * @param price The price of the tickets in the transaction, in dollars.
     * @return Returns a formatted transaction string containing all arguments.
     */
    string format(string code, string event, string seller, int volume, double price);

public:
    /**
     * get_transaction Provides the stored formatted transaction string
     * for any transaction.
     * @return Returns the formatted transaction string.
     */
    string get_transaction();
};
#endif /* TRANSACTION_HPP_ */
