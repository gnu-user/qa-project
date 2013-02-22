#include "Transaction.hpp"
#include "User.hpp"

class Logout : Transaction
{

public:
    Logout(User current_user);
};
