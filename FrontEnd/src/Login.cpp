#include "../include/Login.hpp"
#include "../include/Validate.hpp"

Login::Login(User current_user)
{
   if (current_user.get_status())
   {
       throw Exception(ALREADY_LOGIN);
   }
}

User Login::process_username(string input, CurrentUserAccounts user_account)
{
    try
    {
        /* Attempt to validate the username, throw exception if invalid */
        if (Validate::username(input))
        {
            /* If the username is valid, set the user and save transaction */
            if (user_account.has_user(input))
            {
                this->user = user_account.get_user(input);
                //save_transaction();
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

    return this->user;
}

void Login::save_transaction()
{
    throw Exception(NOT_YET_IMPLEMENTED);
}
