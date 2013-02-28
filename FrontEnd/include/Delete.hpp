#ifndef DELETE_HPP_
#define DELETE_HPP_

#include "Transaction.hpp"
#include "User.hpp"
#include "CurrentUserAccounts.hpp"
#include "Exception.hpp"
#include <string>

using namespace std;

/**
 * Delete Class
 *
 * Used for the delete transaction functions and attributes.
 */
class Delete : public Transaction
{
protected:
	/**
	 * save_transaction Virtual function signature used for
	 * interface creation in C++.
	 */
    virtual void save_transaction();

public:
	/**
	 * Delete The constructor for the class,
	 * requires a reference to the current user session.
	 * @param current_user
	 */
    Delete(User current_user);
   
    /**
     * process_username Validates and processes a username for
     * deletion.
     * @param username The username to delete.
     * @param user_accounts A handle to the current user accounts.
     */
    void process_username(string username, CurrentUserAccounts user_accounts);
};
#endif /* DELETE_HPP_ */
