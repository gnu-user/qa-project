#ifndef DELETE_HPP_
#define DELETE_HPP_

#include "User.hpp"
#include "CurrentUserAccounts.hpp"
#include "Exception.hpp"
#include <string>

using namespace std;

class Delete : public Transaction
{

public:
    Delete(User current_user);
   
    void process_username(string input, CurrentUserAccounts user_accounts);
};
#endif /* DELETE_HPP_ */
