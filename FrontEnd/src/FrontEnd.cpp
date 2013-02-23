#include "../include/CurrentUserAccounts.hpp"
#include "../include/AvailableTickets.hpp"
#include "../include/Exception.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

// Value-Defintions of the different String values
enum transaction_code {
			_undefined,
			_login,
			_logout,
			_create,
			_delete,
			_sell,
			_buy,
			_refund,
			_addcredit
};

static map<string, transaction_code> map_code = {
			{"login", _login},
			{"logout", _logout},
			{"create", _create},
			{"delete", _delete},
			{"sell", _sell },
			{"buy", _buy},
			{"refund", _refund},
			{"addcredit", _addcredit}
};


int main(int argc, char** argv)
{
	string input;

	/* Verify the correct number of arguments provided */
	if (argc < 4)
	{
		cerr << "Usage:   ./FrontEnd [current user accounts file] [available tickets file] "
			 << "[daily transaction file]" << endl
			 << "Example: ./FrontEnd user_accounts avail_tickets daily_transaction" << endl;

		//return EXIT_FAILURE;
	}

	/* Read the input files and parse the contents */
	try
	{
		cout << "Welcome." << endl;
		//CurrentUserAccounts cua = CurrentUserAccounts(argv[1]);
		//AvailableTickets atf = AvailableTickets(argv[2]);
	}
	catch (Exception& e)
	{
		cerr << e.mesg() << endl;
	}

	while(true)
	{
		cout << "> ";
		getline(cin, input);

		try
		{
			switch(map_code[input])
			{
			  case _login:
			  {
				  throw Exception(ALREADY_LOGIN);
				  cout << "Enter username: ";
				  getline(cin, input);
				  break;
			  }
			  case _logout:
			  {
				  cout << "Logout complete." << endl;
				  break;
			  }
			  case _create:
			  {
				  cout << "Enter the username to create: ";
				  getline(cin, input);
				  break;
			  }
			  case _delete:
			  {
				  cout << "Enter the username to delete: ";
				  getline(cin, input);
				  break;
			  }
			  case _sell:
			  {
				  cout << "Enter the event title: ";
				  getline(cin, input);
				  break;
			  }
			  case _buy:
			  {
				  cout << "Enter the event title: ";
				  getline(cin, input);
				  break;
			  }
			  case _refund:
			  {
				  cout << "Enter the buyer's username: ";
				  getline(cin, input);
				  break;
			  }
			  case _addcredit:
			  {
				  cout << "Enter the amount of credit to add: ";
				  getline(cin, input);
				  break;
			  }
			  default:
			  {
				  break;
			  }
			}
		}
		catch (Exception& e)
		{
			cerr << e.mesg() << endl;
		}

		// Flush the stream
		cout.flush();
	}

	return 0;
}
