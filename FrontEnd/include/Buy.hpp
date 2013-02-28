#ifndef BUY_HPP_
#define BUY_HPP_

#include "Transaction.hpp"
#include "User.hpp"
#include "Ticket.hpp"
#include "AvailableTickets.hpp"
#include "Exception.hpp"
#include <string>

using namespace std;

class Buy : public Transaction
{
private:
    Ticket* ticket;
    string title;
    int volume;
    string seller;

protected:
    virtual void save_transaction();

public:
    Buy(User current_user);
   
    void process_title(string input, AvailableTickets available_tickets);
   
    void process_volume(string input);
   
    void process_seller(string input, AvailableTickets available_tickets);
   
    void process_confirmation(string input);
};
#endif /* BUY_HPP_ */
