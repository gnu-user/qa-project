#include "../include/Logout.hpp"

Logout::Logout(User current_user)
{
    /* If the user has not logged in throw exception */
    if (! current_user.get_status())
    {
        throw Exception(MUST_LOGIN);
    }

    this->code = "00";
    this->user = current_user;
    save_transaction();
}

void Logout::save_transaction()
{
    this->transaction = format(
                            code,
                            user.get_username(),
                            user.get_type(),
                            user.get_credit()
                        );
}
