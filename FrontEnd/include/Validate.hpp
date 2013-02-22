#ifndef VALIDATE_HPP_
#define VALIDATE_HPP_

#include <string>

using namespace std;

class Validate
{

public:
    bool username(string username);
   
    bool event(string event);
   
    bool cua_entry(string entry);
   
    bool atf_entry(string entry);
   
    bool dollars(string amount, double& converted);
   
    bool volume(string amount, int& converted);
};
#endif /* VALIDATE_HPP_ */