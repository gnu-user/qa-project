#ifndef LOGOUT_HPP_
#define LOGOUT_HPP_

#include "Transaction.hpp"
#include "Exception.hpp"
#include "User.hpp"

class Logout : Transaction
{
protected:
    virtual void save_transaction();

public:
    Logout(User current_user);
};
#endif /* LOGOUT_HPP_ */
