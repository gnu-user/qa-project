/*
 * Exception.cpp
 *
 *  Created on: Feb 22, 2013
 *      Author: jon
 */

#include "../include/Exception.hpp"

Exception::Exception(exception_codes code)
{
    this->code = code;
}

string Exception::mesg()
{
    return code_msg[code];
}
