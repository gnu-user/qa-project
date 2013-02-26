#ifndef USER_HPP_
#define USER_HPP_

#include "Exception.hpp"
#include <string>
#include <vector>
#include <map>

using namespace std;

class User
{

private:
    string username;
    string type;
    double credit;
    bool login_status;  // Login status, true if user logged in, default is false
    map<string, vector<string>> permissions {
        {"AA", {"login", "logout", "create", "delete", "sell", "buy", "refund", "addcredit"}},
        {"FS", {"login", "logout", "sell", "buy", "addcredit"}},
        {"BS", {"login", "logout", "buy", "addcredit"}},
        {"SS", {"login", "logout", "sell", "addcredit"}}
    };


public:
    /* Default empty constructor, used only to simplify declaration of User variable */
    User();

    User(string username, string type, double credit);
   
    string get_username();
   
    string get_type();
   
    double get_credit();

    bool get_status();
   
    void login();

    bool has_permissions(string transaction);
};
#endif /* USER_HPP_ */
