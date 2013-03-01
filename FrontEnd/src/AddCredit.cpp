#include "../include/AddCredit.hpp"
#include "../include/Validate.hpp"
#include <iostream>

using namespace std;

AddCredit::AddCredit(User current_user)
{
    /* If the user has not logged in throw exception */
    if (! current_user.get_status())
    {
        throw Exception(MUST_LOGIN);
    }

    /* Verify the user has the necessary privileges */
    if (! current_user.has_permissions("addcredit"))
    {
        throw Exception(INVALID_PRIV);
    }

    this->code = "06";
    this->user = current_user;
}

void AddCredit::process_credit(string credit)
{
    double tmp_credit = 0.0;

    try
    {
        /* Validate the credit is in dollars amount */
        if (Validate::dollars(credit, tmp_credit))
        {
            /* Verify credit amount added does not exceed maximum, 1000.00 */
            if (tmp_credit <= 1000.00)
            {
                this->credit = tmp_credit;
            }
            else
            {
                throw Exception(CREDIT_AMOUNT_OVERFLOW);
            }
        }
    }
    /* Catch any exceptions and throw them to the calling function */
    catch (Exception& e)
    {
        throw e;
    }
}

void AddCredit::process_username(CurrentUserAccounts user_accounts)
{
    string input;

    /* If the user is an admin, as for the username */
    if (user.get_type().compare("AA") == 0)
    {
        cout << "Enter the username to which credit is being added: ";
        getline(cin, input);
    }
    else
    {
        save_transaction();
        return;
    }

    try
    {
        /* Attempt to validate the username, throw exception if invalid */
        if (Validate::username(input))
        {
            /* Check that the username exists */
            if (user_accounts.has_user(input))
            {
                    this->user = user_accounts.get_user(input);
                    save_transaction();
            }
            else
            {
                throw Exception(UNKNOWN_USER);
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


void AddCredit::save_transaction()
{
    this->transaction = format(
                            code,
                            user.get_username(),
                            user.get_type(),
                            credit
                        );
}
