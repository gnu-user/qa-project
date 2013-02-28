#ifndef CREATE_HPP_
#define CREATE_HPP_

#include "Transaction.hpp"
#include "User.hpp"
#include "CurrentUserAccounts.hpp"
#include "Exception.hpp"
#include <string>

using namespace std;

/**
 * Create Class
 *
 * Used for the create transaction functions and attributes.
 */
class Create : public Transaction
{

private:
	/**
	 * types Stores the types of usernames that can be used.
	 * new_username Stores the new username to create.
	 */
    string types[];
    string new_username;

public:
    /**
     * Create The constructor for the class, requires a reference to the
     * current user initiating the transaction.
     * @param current_user
     */
    Create(User current_user);
   
    /**
     * process_username Validates and processes the username entered for
     * creation.
     * @param input The username to create.
     * @param user_account A handle to the current user accounts.
     */
    void process_username(string input, CurrentUserAccounts user_account);
   
    /**
     * process_type Validates and processes the type of user account
     * specified for creation.
     * @param input The type of user account to create.
     */
    void process_type(string input);
};
#endif /* CREATE_HPP_ */
