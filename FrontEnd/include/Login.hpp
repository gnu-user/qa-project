#ifndef LOGIN_HPP_
#define LOGIN_HPP_

#include "Transaction.hpp"
#include "User.hpp"
#include "CurrentUserAccounts.hpp"
#include "Exception.hpp"
#include <string>

using namespace std;

class Login : public Transaction
{
protected:
    virtual void save_transaction();

public:
    Login(User current_user);
   
    User process_username(string username, CurrentUserAccounts user_accounts);
};
#endif /* LOGIN_HPP_ */
