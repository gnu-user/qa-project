#include "../include/CurrentUserAccounts.hpp"
#include "../include/AvailableTickets.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv)
{
	/* Verify the correct number of arguments provided */
	if (argc < 4)
	{
		cerr << "Usage:   ./FrontEnd [current user accounts file] [available tickets file] "
			 << "[daily transaction file]" << endl
			 << "Example: ./FrontEnd user_accounts avail_tickets daily_transaction" << endl;

		return EXIT_FAILURE;
	}

	/* Read the input files and parse the contents */
	try
	{
		CurrentUserAccounts cua = CurrentUserAccounts(argv[1]);
		AvailableTickets atf = AvailableTickets(argv[2]);
	}
	catch (Exception& e)
	{
		cerr << e.mesg() << endl;
	}

	return 0;
}
