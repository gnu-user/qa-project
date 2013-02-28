#ifndef CREATE_HPP_
#define CREATE_HPP_

#include "Transaction.hpp"
#include "User.hpp"
#include "CurrentUserAccounts.hpp"
#include "Exception.hpp"
#include <string>
#include <vector>

using namespace std;

class Create : public Transaction
{

private:
    map<string, string> account_types = {
            {"admin", "AA"},
            {"full-standard", "FS"},
            {"buy-standard", "BS"},
            {"sell-standard", "SS"}
    };
    string new_username;

protected:
    virtual void save_transaction();

public:
    Create(User current_user);
   
    void process_username(string input, CurrentUserAccounts user_account);
   
    void process_type(string input);
};
#endif /* CREATE_HPP_ */
