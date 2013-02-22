#ifndef LOGOUT_HPP_
#define LOGOUT_HPP_

#include "Transaction.hpp"
#include "User.hpp"

class Logout : Transaction
{

public:
    Logout(User current_user);
};
#endif /* LOGOUT_HPP_ */