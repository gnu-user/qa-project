#include "../include/Logout.hpp"

Logout::Logout(User current_user)
{
    /* If the user has not logged in throw exception */
    if (! current_user.get_status())
    {
        throw Exception(MUST_LOGIN);
    }

    this->user = current_user;
}

void Logout::save_transaction()
{
    throw Exception(NOT_YET_IMPLEMENTED);
}
