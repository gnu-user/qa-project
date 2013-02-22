#include "User.hpp"
#include "CurrentUserAccounts.hpp"
#include <string>

using namespace std;

class Delete
{


public:
    Delete(User current_user);
   
    void process_username(string input, CurrentUserAccounts user_accounts);
};
