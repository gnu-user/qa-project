#ifndef SELL_HPP_
#define SELL_HPP_

#include "Transaction.hpp"
#include "User.hpp"
#include "Ticket.hpp"
#include <string>

using namespace std;

class Sell : Transaction
{

private:
    Ticket* ticket;
    string title;
    double price;
    int volume;

public:
    Sell(User current_user);
   
    void process_title(string input);
   
    void process_price(string input);
   
    void process_volume(string input);
};
#endif /* SELL_HPP_ */