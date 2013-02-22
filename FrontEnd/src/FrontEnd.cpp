#include "../include/CurrentUserAccounts.hpp"
#include "Poco/File.h"
#include "Poco/Path.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using Poco::File;
using Poco::Path;
using namespace std;

int main(int argc, char** argv)
{
	/* Verify the correct number of arguments provided */
	if (argc < 3)
	{
		cerr << "Usage:   ./FrontEnd [current user accounts file] [available tickets file] "
			 << "[daily transaction file]" << endl
			 << "Example: ./FrontEnd user_accounts avail_tickets daily_transaction" << endl;

		//return EXIT_FAILURE;
	}

	/* Read the input files and parse the contents */
	try
	{
		CurrentUserAccounts cua = CurrentUserAccounts("test");
	}
	catch (Exception& e)
	{
		cerr << e.mesg() << endl;
	}

	cout << argv[0] << endl;

	File temp = File("derp");

	if (temp.exists())
	{
		cout << "FILE EXISTS" << endl;
	}
	else
	{
		cout << "FILE DOES NOT EXIST!" << endl;
	}


	return 0;
}
