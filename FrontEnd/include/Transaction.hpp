#ifndef TRANSACTION_HPP_
#define TRANSACTION_HPP_

#include "User.hpp"
#include "Exception.hpp"
#include <string>

using namespace std;

class Transaction
{

protected:
    User user;
    string code;
    string transaction;
   
    virtual void save_transaction() = 0;

    /* Transaction formatting helpers, overloads for each type of transaction format */
    // TODO fix this, have two overloads that are the same... not possible
    string format(string code, string username, string type, double credit);
    string format(string code, string username, string type, string seller, double refund);
    string format(string code, string event, string seller, int volume, double price);

public:
    string get_transaction();
};
#endif /* TRANSACTION_HPP_ */
