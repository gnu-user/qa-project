#include "../include/Refund.hpp"
#include "../include/Validate.hpp"

Refund::Refund(User current_user)
{
    /* If the user has not logged in throw exception */
    if (!current_user.get_status())
    {
        throw Exception(MUST_LOGIN);
    }

    /* Verify the user has the necessary privileges */
    if (!current_user.has_permissions("refund"))
    {
        throw Exception(INVALID_PRIV);
    }

    this->code = "05";
    this->user = current_user;
}

void Refund::process_buyer(string buyer, CurrentUserAccounts user_accounts)
{
    try
    {
        /* Attempt to validate the username, throw exception if invalid */
        if (Validate::username(buyer))
        {
            /* Check that the buyer exists */
            if (user_accounts.has_user(buyer))
            {
                /* Get the buyer for the refund */
                this->buyer = buyer;
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

void Refund::process_seller(string seller, CurrentUserAccounts user_accounts)
{
    try
    {
        /* Attempt to validate the username, throw exception if invalid */
        if (Validate::username(seller))
        {
            /* Check that the seller exists */
            if (user_accounts.has_user(seller))
            {
                /* Get the seller for the refund */
                this->seller = seller;
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

void Refund::process_credit(string credit)
{
    double tmp_credit = 0.0;

        try
        {
            /* Validate the credit is in dollars amount */
            if (Validate::dollars(credit, tmp_credit))
            {
                /* Verify credit is less than overflow, 999999.99 */
                if (tmp_credit <= 999999.99)
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

void Refund::save_transaction()
{
    this->transaction = format(
                            code,
                            buyer,
                            user.get_type(),
                            seller,
                            credit
                        );
}
