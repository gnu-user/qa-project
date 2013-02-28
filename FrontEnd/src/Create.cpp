#include "../include/Create.hpp"
#include "../include/User.hpp"
#include "../include/Validate.hpp"

Create::Create(User current_user)
{
    /* If the user has not logged in throw exception */
    if (! current_user.get_status())
    {
        throw Exception(MUST_LOGIN);
    }

    /* Verify the user has the necessary privileges */
    if (! current_user.has_permissions("create"))
    {
        throw Exception(INVALID_PRIV);
    }

    this->code = "01";
}

void Create::process_username(string input, CurrentUserAccounts user_account)
{
    try
    {
        /* Attempt to validate the username, throw exception if invalid */
        if (Validate::username(input))
        {
            /* Accept the new username if it is unique */
            if (! user_account.has_user(input))
            {
                this->new_username = input;
            }
            else
            {
                throw Exception(INVALID_USER_EXISTS);
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

void Create::process_type(string input)
{
    /* If the user type matches one of the types supported, create user */
    if (account_types.find(input) != account_types.end())
    {
        this->user = User(new_username, account_types[input], 0.0);
        save_transaction();
    }
    else
    {
        throw Exception(INVALID_USER_TYPE);
    }
}

void Create::save_transaction()
{
    this->transaction = format(
                            code,
                            user.get_username(),
                            user.get_type(),
                            user.get_credit()
                        );
}
