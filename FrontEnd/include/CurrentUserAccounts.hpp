#ifndef CURRENTUSERACCOUNTS_HPP_
#define CURRENTUSERACCOUNTS_HPP_

#include "User.hpp"
#include "Exception.hpp"
#include <string>
#include <vector>

using namespace std;

class CurrentUserAccounts
{

private:
    vector<User> users;
    string cua_file;

public:
    CurrentUserAccounts(string cua_file);
   
    bool has_user(string username);
   
    User get_user(string username);

    void display_users();

private:
    void parse();
};
#endif /* CURRENTUSERACCOUNTS_HPP_ */
