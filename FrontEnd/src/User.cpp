#include "../include/User.hpp"
#include <algorithm>

User::User()
{
    this->login_status = false;
}

User::User(string username, string type, double credit)
{
    /* Throws an error if invalid user type specified */
    if (this->permissions.find(type) != this->permissions.end())
    {
        this->username = username;
        this->type = type;
        this->credit = credit;
        this->login_status = false;
    }
    else
    {
        throw Exception(INVALID_USER_TYPE);
    }
}

string User::get_username()
{
    return this->username;
}

string User::get_type()
{
    return this->type;
}

double User::get_credit()
{
    return this->credit;
}

bool User::get_status()
{
    return this->login_status;
}

void User::login()
{
    this->login_status = true;
}

bool User::has_permissions(string transaction)
{
    vector<string> user_perms = this->permissions[this->type];

    if(find(user_perms.begin(), user_perms.end(), transaction) != user_perms.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}
