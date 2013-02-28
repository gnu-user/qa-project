#ifndef SELL_HPP_
#define SELL_HPP_

#include "Transaction.hpp"
#include "User.hpp"
#include "Ticket.hpp"
#include "Exception.hpp"
#include <string>

using namespace std;

class Sell : public Transaction
{

private:
    Ticket* ticket;
    string title;
    double price;
    int volume;

protected:
    virtual void save_transaction();

public:
    Sell(User current_user);
   
    void process_title(string title);
   
    void process_price(double price);
   
    void process_volume(int volume);
};
#endif /* SELL_HPP_ */
