#include "User.hpp"
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

private:
    void parse();
};
