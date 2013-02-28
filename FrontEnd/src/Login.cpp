#include "../include/Login.hpp"
#include "../include/Validate.hpp"

Login::Login(User current_user)
{
   if (current_user.get_status())
   {
       throw Exception(ALREADY_LOGIN);
   }
}

User Login::process_username(string username, CurrentUserAccounts user_account)
{
    try
    {
        /* Attempt to validate the username, throw exception if invalid */
        if (Validate::username(username))
        {
            /* If the username exists, set the user and save transaction */
            if (user_account.has_user(username))
            {
                this->user = user_account.get_user(username);
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

    return user;
}

void Login::save_transaction()
{
    // TODO The login transaction is not recorded to the DTF, add an exception for this
    throw Exception(NOT_YET_IMPLEMENTED);
}
