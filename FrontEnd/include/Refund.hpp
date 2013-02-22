#include "Transaction.hpp"
#include "User.hpp"
#include "CurrentUserAccounts.hpp"
#include "AvailableTickets.hpp"
#include <string>

using namespace std;

class Refund : Transaction
{

private:
    string buyer;
    string seller;
    double credit;

public:
    Refund(User current_user);
   
    void process_buyer(string input, CurrentUserAccounts user_accounts);
   
    void process_seller(string input, AvailableTickets available_tickets);
   
    void process_credit(string input);
};
