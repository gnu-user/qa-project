/*
 * Exception.hpp
 *
 *  Created on: Feb 22, 2013
 *      Author: jon
 */

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <string>
#include <map>

using namespace std;

enum exception_codes { FAIL };

class Exception
{
private:
	map<exception_codes, string> code_msg_map {
		{FAIL, "DERP"}
	};
	exception_codes code;

public:
	Exception(exception_codes code);
	string mesg();
	virtual ~Exception();
};

#endif /* EXCEPTION_HPP_ */
