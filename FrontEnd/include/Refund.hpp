#ifndef REFUND_HPP_
#define REFUND_HPP_

#include "Transaction.hpp"
#include "User.hpp"
#include "CurrentUserAccounts.hpp"
#include "AvailableTickets.hpp"
#include "Exception.hpp"
#include <string>

using namespace std;

class Refund : public Transaction
{

private:
    string buyer;
    string seller;
    double credit;

protected:
    virtual void save_transaction();

public:
    Refund(User current_user);
   
    void process_buyer(string buyer, CurrentUserAccounts user_accounts);
   
    void process_seller(string seller, AvailableTickets available_tickets);
   
    void process_credit(double credit);
};
#endif /* REFUND_HPP_ */
