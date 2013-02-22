#include "Transaction.hpp"
#include "User.hpp"
#include "CurrentUserAccounts.hpp"
#include <string>

using namespace std;

class Login : Transaction
{


public:
    Login(User current_user);
   
    User* process_username(string input, CurrentUserAccounts user_account);
};
