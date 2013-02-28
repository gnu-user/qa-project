#ifndef LOGOUT_HPP_
#define LOGOUT_HPP_

#include "Transaction.hpp"
#include "Exception.hpp"
#include "User.hpp"

/**
 * Logout Class
 *
 * Used for the logout transaction functions and attributes.
 */
class Logout : public Transaction
{
protected:
    /**
     * save_transaction Virtual function signature for
     * class abstraction in C++.
     */
    virtual void save_transaction();

public:
    /**
     * Logout The constructor for the class, requires a handle
     * to the current user logged in.
     * @param current_user The current user logged in, to be
     * logged out.
     */
    Logout(User current_user);
};
#endif /* LOGOUT_HPP_ */
