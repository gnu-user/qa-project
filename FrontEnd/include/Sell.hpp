#ifndef SELL_HPP_
#define SELL_HPP_

#include "Transaction.hpp"
#include "User.hpp"
#include "Ticket.hpp"
#include "Exception.hpp"
#include <string>

using namespace std;

/**
 * Sell Class
 *
 * Used for the sell transaction functions and attributes.
 */
class Sell : public Transaction
{

private:
    /**
     * ticket Contains the ticket to be sold.
     * title Contains the title for the ticket sale.
     * price Contains the price for the ticket sales.
     * volume Contains the volume of tickets to sell.
     */
    Ticket ticket;
    string title;
    double price;
    int volume;

protected:
    /**
     * save_transaction Virtual function signature for
     * class abstraction in C++.
     */
    virtual void save_transaction();

public:
    /**
     * Sell The constructor of the function, requires a handle
     * to the current user logged in.
     * @param current_user A handle to the current user.
     */
    Sell(User current_user);
   
    /**
     * process_title Validates and processes the title for the
     * ticket sale.
     * @param title The title for the event tickets being sold.
     */
    void process_title(string title);
   
    /**
     * process_price Validates and processes the specified price
     * for the tickets.
     * @param price The price, in dollars, for the tickets being sold.
     */
    void process_price(string price);
   
    /**
     * process_volume Validates and processes the specified number
     * of tickets to be sold.
     * @param volume The number of tickets to be sold.
     */
    void process_volume(string volume);
};
#endif /* SELL_HPP_ */
