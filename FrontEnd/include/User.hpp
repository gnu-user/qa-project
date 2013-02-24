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
    map<string, vector<string>> permissions {
        {"AA", {"login", "logout", "create", "delete", "sell", "buy", "refund", "addcredit"}},
        {"FS", {"login", "logout", "sell", "buy", "addcredit"}},
        {"BS", {"login", "logout", "buy", "addcredit"}},
        {"SS", {"login", "logout", "sell", "addcredit"}}
    };


public:
    User(string username, string type, double credit);
   
    string get_username();
   
    string get_type();
   
    double get_credit();
   
    bool has_permissions(string transaction);
};
#endif /* USER_HPP_ */
