#include "Transaction.hpp"
#include "CurrentUserAccounts.hpp"
#include "User.hpp"

#include <string>

using namespace std;

class AddCredit : Transaction
{
private:
    string username;
    double credit;

public:
    AddCredit(User current_user);
   
    void process_username(string input, CurrentUserAccounts user_accounts);
   
    void process_credit(string input);
};
