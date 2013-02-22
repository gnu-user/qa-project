#ifndef USER_HPP_
#define USER_HPP_

#include <string>
#include <vector>

using namespace std;

class User
{

private:
    string username;
    string type;
    double credit;
    vector<string> permissions;

public:
    User(string username, string type, double credit);
   
    string get_username();
   
    string get_type();
   
    double get_credit();
   
    bool has_permissions(string transaction);
};
#endif /* USER_HPP_ */