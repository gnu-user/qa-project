#ifndef ADDCREDIT_HPP_
#define ADDCREDIT_HPP_

#include "Transaction.hpp"
#include "CurrentUserAccounts.hpp"
#include "User.hpp"
#include "Exception.hpp"
#include <string>

using namespace std;

/**
 * AddCredit Class
 *
 * Used for the AddCredit transaction functions and attributes.
 */
class AddCredit : public Transaction
{
private:
	/**
	 * credit Stores the amount of credit to add.
	 */
    double credit;

protected:
    virtual void save_transaction();

public:
    /**
     * AddCredit The constructor for the class, requires a user specified to add the credit to.
     * @param current_user The user to add the credit specified to.
     */
    AddCredit(User current_user);

    /**
     * process_credit Performs the addition of the credit to the previously specified user account.
     * @param credit The actual amount of credit to add.
     */
     void process_credit(string credit);

   /**
    * process_username Determines the validity of the username specified, and processes that component of the transaction.
    * @param user_accounts Provides a handle to the current user accounts object.
    */
    void process_username(CurrentUserAccounts user_accounts);
};
#endif /* ADDCREDIT_HPP_ */
