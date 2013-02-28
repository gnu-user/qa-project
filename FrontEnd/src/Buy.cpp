#include "../include/Buy.hpp"

Buy::Buy(User current_user)
{
    /* If the user has not logged in throw exception */
    if (! current_user.get_status())
    {
        throw Exception(MUST_LOGIN);
    }

    /* Verify the user has the necessary privileges */
    if (! current_user.has_permissions("buy"))
    {
        throw Exception(INVALID_PRIV);
    }

    this->code = "04";
    this->user = current_user;
}

void Buy::process_title(string title, AvailableTickets available_tickets)
{
    throw Exception(NOT_YET_IMPLEMENTED);
}

void Buy::process_volume(string volume)
{
    throw Exception(NOT_YET_IMPLEMENTED);
}

void Buy::process_seller(string username, AvailableTickets available_tickets)
{
    throw Exception(NOT_YET_IMPLEMENTED);
}

void Buy::process_confirmation(string confirm)
{
    throw Exception(NOT_YET_IMPLEMENTED);
}

void Buy::save_transaction()
{
    throw Exception(NOT_YET_IMPLEMENTED);
}
