#include "../include/Delete.hpp"
#include "../include/Validate.hpp"

Delete::Delete(User current_user)
{
    /* If the user has not logged in throw exception */
    if (! current_user.get_status())
    {
        throw Exception(MUST_LOGIN);
    }

    /* Verify the user has the necessary privileges */
    if (! current_user.has_permissions("delete"))
    {
        throw Exception(INVALID_PRIV);
    }

    this->code = "02";
    this->user = current_user;
}

// TODO Possibly add support for deleting any outstanding tickets after a
// user has been deleted. I think this REALLY is the backend's responsibility...
void Delete::process_username(string username, CurrentUserAccounts user_accounts)
{
    try
    {
        /* Attempt to validate the username, throw exception if invalid */
        if (Validate::username(username))
        {
            /* Check that the username exists */
            if (user_accounts.has_user(username))
            {
                /* Verify not deleting self, set user to delete as user specified */
                if (user.get_username().compare(username) != 0)
                {
                    this->user = user_accounts.get_user(username);
                    save_transaction();
                }
                else
                {
                    throw Exception(DELETE_SELF);
                }
            }
            else
            {
                throw Exception(INVALID_USER);
            }
        }
        else
        {
            throw Exception(INVALID_USER);
        }
    }
    /* Catch any exceptions and throw them to the calling function */
    catch (Exception& e)
    {
        throw e;
    }
}

void Delete::save_transaction()
{
    this->transaction = format(
                            code,
                            user.get_username(),
                            user.get_type(),
                            user.get_credit()
                        );
}
