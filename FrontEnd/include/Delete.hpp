#ifndef DELETE_HPP_
#define DELETE_HPP_

#include "Transaction.hpp"
#include "User.hpp"
#include "CurrentUserAccounts.hpp"
#include "Exception.hpp"
#include <string>

using namespace std;

class Delete : public Transaction
{
protected:
    virtual void save_transaction();

public:
    Delete(User current_user);
   
    void process_username(string input, CurrentUserAccounts user_accounts);
};
#endif /* DELETE_HPP_ */
