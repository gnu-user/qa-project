#include <iostream>
#include <string>
#include <stdio.h>
#include <Poco/String.h>

using Poco::trim;
using Poco::trimLeftInPlace;
using Poco::trimRight;
using Poco::trimRightInPlace;

using namespace std;

int main()
{
	string hello("  Hello, world!  ");
	string s1(trimLeftInPlace(hello)); // "Hello, world!  "
	trimRightInPlace(s1);            // "Hello, world!"
	string s2(trim(hello));     // "Hello, world!"

	cout << s1 << endl << s2 << endl;

	return 0;
}
