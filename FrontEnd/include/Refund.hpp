#ifndef REFUND_HPP_
#define REFUND_HPP_

#include "Transaction.hpp"
#include "User.hpp"
#include "CurrentUserAccounts.hpp"
#include "AvailableTickets.hpp"
#include "Exception.hpp"
#include <string>

using namespace std;

/**
 * Refund Class
 *
 * Used for the refund transaction functions and attributes.
 */
class Refund : public Transaction
{

private:
    /**
     * buyer Contains the buyer for the original sale to be refunded.
     * seller Contains the seller for the refund.
     * credit Contains the amount of credit to refund to the buyer,
     * in dollars.
     */
    string buyer;
    string seller;
    double credit;

protected:
    /**
     * save_transaction Virtual function signature for class
     * abstraction in C++.
     */
    virtual void save_transaction();

public:
    /**
     * Refund The constructor for the class, requires a handle to
     * the current user logged in.
     * @param current_user A handle to the current user logged in.
     */
    Refund(User current_user);
   
    /**
     * process_buyer Validates and processes the specified buyer for
     * the refund.
     * @param buyer The buyer for the sale to be refunded.
     * @param user_accounts A handle to the current user accounts.
     */
    void process_buyer(string buyer, CurrentUserAccounts user_accounts);
   
    /**
     * process_seller Validates and processes the specified seller for
     * the refund.
     * @param seller The seller for the sale to be refunded.
     * @param available_tickets A handle to the available tickets file.
     */
    void process_seller(string seller, AvailableTickets available_tickets);
   
    /**
     * process_credit Validates and processes the specified amount
     * for the refund.
     * @param credit The specified refund amount, in dollars.
     */
    void process_credit(double credit);
};
#endif /* REFUND_HPP_ */
