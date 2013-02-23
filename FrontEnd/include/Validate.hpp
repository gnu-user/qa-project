#ifndef VALIDATE_HPP_
#define VALIDATE_HPP_

#include "Exception.hpp"
#include <string>

using namespace std;

class Validate
{

public:
    static bool username(string username);
   
    static bool event(string event);
   
    static bool cua_entry(string entry);
   
    static bool atf_entry(string entry);
   
    static bool dollars(string amount, double& converted);
   
    static bool volume(string amount, int& converted);
};
#endif /* VALIDATE_HPP_ */
