#ifndef TRANSACTION_HPP_
#define TRANSACTION_HPP_

#include "User.hpp"
#include <string>

using namespace std;

class Transaction
{

protected:
    User* user;
    string code;
    string transaction;
   
    virtual void save_transaction() = 0;

public:
    string get_transaction();
};
#endif /* TRANSACTION_HPP_ */