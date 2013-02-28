#ifndef LOGIN_HPP_
#define LOGIN_HPP_

#include "Transaction.hpp"
#include "User.hpp"
#include "CurrentUserAccounts.hpp"
#include "Exception.hpp"
#include <string>

using namespace std;

/**
 *  Login Class
 *
 *  Used for the login transaction functions and attributes.
 */
class Login : public Transaction
{
protected:
    /**
     * save_transaction Virtual function signature for
     * class abstraction in C++.
     */
    virtual void save_transaction();

public:
    /**
     * Login The constructor for the class, requires a handle to the
     * current user logged in (if applicable).
     * @param current_user The current user logged in.
     */
    Login(User current_user);
   
    /**
     * process_username Validates and processes the username specified
     * to log in with.
     * @param username The username for the account to log in.
     * @param user_accounts A handle to the current user accounts.
     * @return Returns a User object for the user which was logged in, or
     * null if an exception occurs.
     */
    User process_username(string username, CurrentUserAccounts user_accounts);
};
#endif /* LOGIN_HPP_ */
