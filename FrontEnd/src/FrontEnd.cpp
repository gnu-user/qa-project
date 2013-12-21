/**
 * Swift Ticket -- Front End Interface
 *
 * Copyright (C) 2013, Jonathan Gillett, Daniel Smullen, and Rayan Alfaheid
 * All rights reserved.
 *
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
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
#include "../include/Refund.hpp"
#include "../include/AddCredit.hpp"

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;


istream& get_input(istream& input_stream, string& target)
{
    string input;
    char ch;
    input_stream.get(ch);

    /* Throw EOF exception if EOF found */
    if (input_stream.eof())
    {
        throw Exception(EOF_INPUT);
    }

    while (ch!='\n' && !input_stream.eof()) //check for end of file
    {
        input += ch;
        input_stream.get(ch);
    }

    target = input;
    return input_stream;
}


int main(int argc, char** argv)
{
    string input;
    CurrentUserAccounts current_accounts;
    AvailableTickets available_tickets;
    DailyTransaction daily_transactions;
    User current_user;

    /* Verify the correct number of arguments provided */
    if (argc < 4)
    {
        cerr << "Usage:   ./FrontEnd [current user accounts file] [available tickets file] "
             << "[daily transaction file]" << endl
             << "Example: ./FrontEnd user_accounts avail_tickets daily_transaction" << endl;

        return EXIT_FAILURE;
    }

    /* Start the front end, read the input files and parse the contents */
    try
    {
        cout << "Welcome." << endl;

        /* Parse the current user accounts file */
        current_accounts = CurrentUserAccounts(argv[1]);
        cout << "Current user accounts file read successfully." << endl;

        /* Parse the available tickets file */
        available_tickets = AvailableTickets(argv[2]);
        cout << "Available tickets file read successfully." << endl;

        /* Set the filename for the daily transaction file */
        daily_transactions = DailyTransaction(argv[3]);
    }
    catch (Exception& e)
    {
        cerr << e.mesg() << endl;
        return EXIT_FAILURE;
    }


    cout << "> ";
    while(getline(cin, input))
    {
        cout << endl;

        try
        {
            switch(map_code[input])
            {
              case _login:
              {
                  Login login = Login(current_user);

                  cout << "Enter username: ";
                  get_input(cin, input), cout << endl;

                  /* Attempt to login with username provided */
                  current_user = login.process_username(input, current_accounts);
                  current_user.login();
                  cout << "Username accepted." << endl;
                  break;
              }
              case _logout:
              {
                  Logout logout = Logout(current_user);
                  current_user.logout();
                  current_user.reset_sell_status();

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
                  get_input(cin, input), cout << endl;
                  create.process_username(input, current_accounts);

                  /* Process the user type, save transaction if successful */
                  cout << "Enter the user type: ";
                  get_input(cin, input), cout << endl;
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
                  get_input(cin, input), cout << endl;
                  __delete.process_username(input, current_accounts);

                  daily_transactions.save((Transaction) __delete);
                  cout << "User deleted successfully." << endl;
                  break;
              }
              case _sell:
              {
                  Sell sell = Sell(current_user);

                  /* Process the event title */
                  cout << "Enter the event title: ";
                  get_input(cin, input), cout << endl;
                  sell.process_title(input);

                  /* Process sale price */
                  cout << "Enter the sale price in dollars: ";
                  get_input(cin, input), cout << endl;
                  sell.process_price(input);

                  /* Process the volume, save transaction if successful */
                  cout << "Enter the number of tickets for sale: ";
                  get_input(cin, input), cout << endl;
                  sell.process_volume(input);

                  /* Record that the user has sold tickets this session */
                  current_user.tickets_sold();

                  daily_transactions.save((Transaction) sell);
                  cout << "Tickets listed for sale successfully." << endl;
                  break;
              }
              case _buy:
              {
                  Buy buy = Buy(current_user);

                  /* Process the event title */
                  cout << "Enter the event title: ";
                  get_input(cin, input), cout << endl;
                  buy.process_title(input, available_tickets);

                  /* Process the volume */
                  cout << "Enter the number of tickets to purchase: ";
                  get_input(cin, input), cout << endl;
                  buy.process_volume(input);

                  /* Process the seller */
                  cout << "Enter the seller's username: ";
                  get_input(cin, input), cout << endl;
                  buy.process_seller(input, available_tickets);

                  /* Display the confirmation, save transaction if confirmed */
                  cout << "Purchase tickets? Please confirm (yes/no): ";
                  get_input(cin, input), cout << endl;
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
                  get_input(cin, input), cout << endl;
                  refund.process_buyer(input, current_accounts);

                  /* Process the seller's username */
                  cout << "Enter the seller's username: ";
                  get_input(cin, input), cout << endl;
                  refund.process_seller(input, current_accounts);

                  /* Refund the credit amount specified */
                  cout << "Enter the amount of credit to transfer: ";
                  get_input(cin, input), cout << endl;
                  refund.process_credit(input);

                  /* Add the transaction to the daily transaction file */
                  daily_transactions.save((Transaction) refund);
                  cout << "Buyer refunded successfully." << endl;
                  break;
              }
              case _addcredit:
              {
                  AddCredit addcredit = AddCredit(current_user);

                  /* Process amount of credit to add */
                  cout << "Enter the amount of credit to add: ";
                  get_input(cin, input), cout << endl;
                  addcredit.process_credit(input);

                  /* Process the username if applicable */
                  addcredit.process_username(current_accounts);

                  /* Add the transaction to the daily transaction file */
                  daily_transactions.save((Transaction) addcredit);
                  cout << "Credit added successfully." << endl;
                  break;
              }
              case _quit:
              {
                  /* If the user is not logged in terminate the program */
                  if (! current_user.get_status())
                  {
                      cout << "Goodbye." << endl;
                      return EXIT_SUCCESS;
                  }
                  else
                  {
                      throw Exception(INVALID_TRANSACTION);
                  }
              }
              default:
              {
                  throw Exception(INVALID_TRANSACTION);
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
        cout << "> ";
    }

    return EXIT_SUCCESS;
}
