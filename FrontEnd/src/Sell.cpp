#include "../include/Sell.hpp"
#include "../include/Validate.hpp"

Sell::Sell(User current_user)
{
    /* If the user has not logged in throw exception */
    if (! current_user.get_status())
    {
        throw Exception(MUST_LOGIN);
    }

    /* Verify the user has the necessary privileges */
    if (! current_user.has_permissions("sell"))
    {
        throw Exception(INVALID_PRIV);
    }

    this->code = "03";
    this->user = current_user;
}

void Sell::process_title(string title)
{
    try
    {
        /* Attempt to validate the event title, throw exception if invalid */
        if (Validate::title(title))
        {
            this->title = title;
        }
        else
        {
            throw Exception(INVALID_TITLE);
        }
    }
    /* Catch any exceptions and throw them to the calling function */
    catch (Exception& e)
    {
        throw e;
    }
}

void Sell::process_price(string price)
{
    double tmp_price = 0.0;

    try
    {
        /* Validate the price is in dollars amount */
        if (Validate::dollars(price, tmp_price))
        {
            /* Verify ticket price is less than maximum, 999.99 */
            if (tmp_price <= 999.99)
            {
                this->price = tmp_price;
            }
            else
            {
                throw Exception(SALE_PRICE_OVERFLOW);
            }
        }
    }
    /* Catch any exceptions and throw them to the calling function */
    catch (Exception& e)
    {
        throw e;
    }
}

void Sell::process_volume(int volume)
{
    throw Exception(NOT_YET_IMPLEMENTED);
}

void Sell::save_transaction()
{
    throw Exception(NOT_YET_IMPLEMENTED);
}
