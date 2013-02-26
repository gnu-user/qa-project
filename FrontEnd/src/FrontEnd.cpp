#include "../include/CurrentUserAccounts.hpp"
#include "../include/AvailableTickets.hpp"
#include "../include/Exception.hpp"
#include "../include/TransactionCodes.hpp"
#include "../include/Login.hpp"
#include "../include/Logout.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <memory>

using namespace std;

int main(int argc, char** argv)
{
    string input;
    auto_ptr<CurrentUserAccounts> ptr_cua;
    auto_ptr<AvailableTickets> ptr_atf;
    User current_user = User();    // Empty User rather than smart pointers

    /* Verify the correct number of arguments provided */
    if (argc < 4)
    {
        cerr << "Usage:   ./FrontEnd [current user accounts file] [available tickets file] "
             << "[daily transaction file]" << endl
             << "Example: ./FrontEnd user_accounts avail_tickets daily_transaction" << endl;

        //return EXIT_FAILURE;
    }

    /* Start the front end, read the input files and parse the contents */
    try
    {
        cout << "Welcome." << endl;

        ptr_cua.reset(new CurrentUserAccounts(argv[1]));
        cout << "Current user accounts file read successfully." << endl;

        /* Display each user */
        ptr_cua->display_users();

        /* Check if user exists */
        if (ptr_cua->has_user("buyer"))
        {
            cout << "HAS buyer" << endl;
        }
        if (ptr_cua->has_user("administrator"))
        {
            cout << "HAS administrator" << endl;
        }
        if (!ptr_cua->has_user("admin"))
        {
            cout << "DOES NOT HAVE admin" << endl;
        }

        User new_user = ptr_cua->get_user("administrator");
        cout << new_user.get_username() << endl;


        /* Available tickets file tests */
        ptr_atf.reset(new AvailableTickets(argv[2]));
        cout << "Available tickets file read successfully." << endl;

        ptr_atf->display_tickets();

        /* Check that a ticket exists */
        Ticket ticket = ptr_atf->get_ticket("The Godfather III", "seller");

        cout << ticket.get_event() << " " << ticket.get_seller() << endl;


        // Make a new user
        User derp = User("derp", "BS", 0.0);
        cout << derp.get_username() << " " << derp.get_type() << " " << derp.get_credit() << endl;

        if (derp.has_permissions("buy"))
        {
            cout << "HAS PERM" << endl;
        }

        ticket = Ticket("Test", "tester", 10, 5.00);
    }
    catch (Exception& e)
    {
        cerr << e.mesg() << endl;
        //return EXIT_FAILURE;
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
                  Login login = Login(current_user);

                  cout << "Enter username: ";
                  getline(cin, input);

                  /* Attempt to login with username provided */
                  current_user = login.process_username(input, *ptr_cua);
                  current_user.login();
                  break;
              }
              case _logout:
              {
                  Logout logout = Logout(current_user);
                  current_user.logout();
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
