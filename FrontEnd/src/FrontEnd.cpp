#include "../include/CurrentUserAccounts.hpp"
#include "../include/AvailableTickets.hpp"
#include "../include/DailyTransaction.hpp"
#include "../include/Exception.hpp"
#include "../include/TransactionCodes.hpp"
#include "../include/Transaction.hpp"
#include "../include/Login.hpp"
#include "../include/Logout.hpp"
#include "../include/Refund.hpp"
#include "../include/Create.hpp"
#include "../include/Delete.hpp"
#include "../include/Sell.hpp"
#include "../include/Buy.hpp"

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv)
{
    string input;
    CurrentUserAccounts current_accounts;
    AvailableTickets available_tickets;
    DailyTransaction daily_transactions;
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

        current_accounts = CurrentUserAccounts(argv[1]);
        cout << "Current user accounts file read successfully." << endl;

        /* Display each user */
        current_accounts.display_users();

        /* Check if user exists */
        if (current_accounts.has_user("buyer"))
        {
            cout << "HAS buyer" << endl;
        }
        if (current_accounts.has_user("administrator"))
        {
            cout << "HAS administrator" << endl;
        }
        if (!current_accounts.has_user("admin"))
        {
            cout << "DOES NOT HAVE admin" << endl;
        }

        User new_user = current_accounts.get_user("administrator");
        cout << new_user.get_username() << endl;


        /* Available tickets file tests */
        available_tickets = AvailableTickets(argv[2]);
        cout << "Available tickets file read successfully." << endl;

        available_tickets.display_tickets();

        /* Check that a ticket exists */
        Ticket ticket = available_tickets.get_ticket("The Godfather III", "seller");

        cout << ticket.get_event() << " " << ticket.get_seller() << endl;


        // Make a new user
        User derp = User("derp", "BS", 0.0);
        cout << derp.get_username() << " " << derp.get_type() << " " << derp.get_credit() << endl;

        if (derp.has_permissions("buy"))
        {
            cout << "HAS PERM" << endl;
        }

        ticket = Ticket("Test", "tester", 10, 5.00);

        /* Set the filename for the daily transaction file */
        daily_transactions = DailyTransaction(argv[3]);
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
                  current_user = login.process_username(input, current_accounts);
                  current_user.login();
                  break;
              }
              case _logout:
              {
                  Logout logout = Logout(current_user);
                  current_user.logout();
                  cout << "Logout complete." << endl;

                  /* Write all session transactions to daily transaction file */
                  daily_transactions.save((Transaction) logout);
                  daily_transactions.write();
                  break;
              }
              case _create:
              {
                  Create create = Create(current_user);

                  /* Process the username */
                  cout << "Enter the username to create: ";
                  getline(cin, input);
                  create.process_username(input, current_accounts);

                  /* Process the user type, save transaction if successful */
                  cout << "Enter the user type: ";
                  getline(cin, input);
                  create.process_type(input);

                  daily_transactions.save((Transaction) create);
                  cout << "User created successfully." << endl;
                  break;
              }
              case _delete:
              {
                  Delete __delete = Delete(current_user);

                  /* Process the username, save transaction if successful */
                  cout << "Enter the username to delete: ";
                  getline(cin, input);
                  __delete.process_username(input, current_accounts);

                  daily_transactions.save((Transaction) __delete);
                  cout << "User deleted successfully as well as any outstanding tickets." << endl;
                  break;
              }
              case _sell:
              {
                  Sell sell = Sell(current_user);

                  /* Process the event title */
                  cout << "Enter the event title: ";
                  getline(cin, input);
                  sell.process_title(input);

                  /* Process sale price */
                  cout << "Enter the sale price in dollars: ";
                  getline(cin, input);
                  sell.process_price(input);

                  /* Process the volume, save transaction if successful */
                  cout << "Enter the number of tickets for sale: ";
                  getline(cin, input);
                  sell.process_volume(input);

                  daily_transactions.save((Transaction) sell);
                  cout << "Tickets listed for sale successfully." << endl;
                  break;
              }
              case _buy:
              {
                  Buy buy = Buy(current_user);

                  /* Process the event title */
                  cout << "Enter the event title: ";
                  getline(cin, input);
                  buy.process_title(input, available_tickets);

                  /* Process the volume */
                  cout << "Enter the number of tickets to purchase: ";
                  getline(cin, input);
                  buy.process_volume(input);

                  /* Process the seller */
                  cout << "Enter the seller's username: ";
                  getline(cin, input);
                  buy.process_seller(input, available_tickets);

                  /* Display the confirmation, save transaction if confirmed */
                  cout << "Purchase tickets? Please confirm (yes/no): ";
                  getline(cin, input);
                  buy.process_confirmation(input);

                  daily_transactions.save((Transaction) buy);
                  cout << "Tickets purchased successfully." << endl;
                  break;
              }
              case _refund:
              {
                  Refund refund = Refund(current_user);

                  /* Process buyer's username */
                  cout << "Enter the buyer's username: ";
                  getline(cin, input);
                  refund.process_buyer(input);

                  /* Process the seller's username */
                  cout << "Enter the seller's username: ";
                  getline(cin, input);
                  refund.process_seller(input);

                  /* Refund the credit amount specified */
                  cout << "Enter the amount of credit to transfer: ";
                  getline(cin, input);
                  refund.process_credit(input);

                  /* Add the transaction to the daily transaction file */
                  daily_transactions.save((Transaction) refund);
                  cout << "Buyer refunded successfully." << endl;
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
