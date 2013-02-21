FRONT-END DESIGN NOTES
==========================

Classes
----------

The front end has the following classes, these provide all of the functionality as well
as error/exception handling.


### Classes for handling file I/O

* CurrentUserAccounts
* AvailableTickets
* DailyTransaction


### Classes to facilitate program state 

* User
* Ticket


### Classes for handling transactions

* (Abstract class) *TransactionInterface* (inherited by each of the following classes)
* Login
* Logout
* Create
* Delete
* Sell
* Buy
* Refund
* AddCredit


### Classes to facilitate input validation (instead of duplicated code)

* Validate
* FormatTransaction? A possible helper class to format transaction data


### Other

Possible ENUM of the various error codes which can then be mapped to strings, although
this is not necessary.


File I/O Classes
=================

CurrentUserAccounts
----------------------

This class verifies the current user accounts file exists, loads the contents into memory
and checks the current user accounts file for corrupted entries, if any error occurs
reading file an exception thrown.

### private vector<User> users
* A vector which contains all of the users from the current user accounts file

### CurrentUserAccount(String cua_file)
* Constructor which accepts the current user accounts file path
* throws an exception if file does not exist (DNE) or if corrupted
* Adds each of the users in the file to the users vector

### bool has_user(String username)
* Returns true if if the user is found

### User get_user(String username)
* Returns a User (Object) if the user is found in the current user account file, if user is not
  found returns NULL


AvailableTickets
-----------------

This class verifies the available tickets file exists, loads content into memory and checks the file,
if the file is corrupted or any error occurs reading the file an exception is thrown.

### private vector<Tickets> tickets
* A vector which contains all of the tickets from the available tickets file (ATF)

### AvailableTickets(String atf_file)
* Constructor which accepts the atf file path
* throws an exception if file does not exist (DNE) or if corrupted

### bool has_event(String event)
* Returns true if the atf has the event listed

### bool has_seller(String username)
* Returns true if the atf has the seller listed

### Ticket get_ticket(String event, String username)
* Returns a Ticket (Object) if the ticket is found that matches the event and the username of
* the seller, NULL returned otherwise.


DailyTransaction
-------------------

Saves daily transaction events in memory and writes them to a file at the end of a session (when 
logging out).

### private vector<Transaction> transactions
* A vector which contains all of the saved transactions in memory

### void save(Transaction transaction)
* Saves a transaction in memory, all transactions must implement the Transaction interface

### void write(String filename)
* Writes the daily transaction file to the file specified, throws an exception if an error occurs




Program State Classes
========================

User
------

Contains the information for a user, such as username, type, credit, and permissions.


### private String username
* The user's name

### private String type
* The user's type

### private double credit
* The user's credit

### private vector<String> permissions
* The user's permissions, transactions the user can use

### User(String username, String type, double credit)
* Constructor for the user

### String get_username()
* Returns the user's username

### String get_type()
* Returns the user's type

### double get_credit()
* Returns the user's credit

### bool has_permission(String transaction)
* Returns true if the user has permissions for the transaction


Ticket
----------

Contains the ticket information, such as event name, seller's username, number of
tickets for sale, and price per ticket.

### private String event
* The event name for the ticket

### private String seller
* The username of the seller

### private int volume
* The volume/number of tickets available for sale

### private double price
* The price per ticket

### String get_event()
* Returns the event title

### String get_seller()
* Returns the seller's username

### int get_volume()
* Returns the volume of tickets available for sale

### double get_price()
* Returns the price per ticket




Transaction Classes
====================

These classes all inherit the transaction class and provide the logic for processing
each of the transactions.

Transaction (Abstract)
-------------------------

The Transaction class is an abstract class that provides the basic functionality every
subclass must have.

### private User* user
* Reference to a user

### private String code
* The transaction code

### private String transaction
* The transaction in the daily transaction file format

### private virtual void save_transaction()
* Saves the information for the transaction into the daily transaction format
* Sets the private transaction member

### String get_transaction() = ();
* This returns the transaction as a String that can be written to the daily transaction file


Login inherits Transaction
----------------------------

The Login transaction inherits transaction, contains the login transaction details,
if the login is successful the login returns a reference to the current user that is now logged in.

### Login(User current_user)
* If the user object is null the login transaction succeeds (not currently logged in), otherwise an
exception is thrown, the user is already logged in if user is not null.

### User* process_username(String input)
* Processes the username for the login transaction to the username specified, if the username does not exist,
or some other error occurs an exception is thrown.
* If no errors occur returns a pointer to the current_user and executes save_transaction()


Logout inherits Transaction
----------------------------

The logout transaction inherits transaction, contains the logout transaction details

### Logout(User current_user)
* If the user object is null the transaction fails and throws an exception (user is not logged in),
* If no error occurs executes save_transaction()


Create inherits Transaction
-----------------------------

The create transaction inherits transaction, contains user creation details

### private String[] types
* Array of the valid account types the create statement can make

### private String new_username
* The name of the new user to create

### Create(User current_user)
* If the user object is null the transaction fails and throws an exception (user is not logged in)
* If the current_user does not have privileges exception is thrown

### void process_username(String input, CurrentUserAccounts user_accounts)
* Processes the username, if the username is valid and exists saves the new username, , otherwise
an exception is thrown

### void process_type(String input)
* Process the type provided, if the type is valid creates the new user account (in memory), otherwise
an exception is thrown
* If no error occurs executes save_transaction()


Delete inherits Transaction
----------------------------

The delete transaction inherits transaction, contains user deletion details

### Delete(User current_user)
* If the user object is null the transaction fails and throws an exception (user is not logged in)
* If the current_user does not have privileges exception is thrown

### void process_username(String input, CurrentUserAccounts user_accounts)
* Processes the username, if the username is valid, exists, and is not the current user saves the
user details (in memory), otherwise an exception is thrown
* If no error occurs executes save_transaction()


Sell inherits Transaction
--------------------------

The sell transaction inherits transaction, contains user sale details

### private Ticket* ticket
* Reference to a ticket

### private String title
* The title of the event

### private double price
* The price of the ticket

### private int volume
* The volume of tickets for sale

### Sell(User current_user)
* If the user object is null the transaction fails and throws an exception (user is not logged in)
* If the current_user does not have privileges exception is thrown

### void process_title(String input)
* Processes the event title, if the title is valid, saves the title, otherwise an exception is thrown

### void process_price(String input)
* Process the sale price, if the price is valid (dollars amount) saves price, otherwise an exception
is thrown

### void process_volume(String input)
* Process the ticket volume, if the amount is valid, creates a new ticket object, otherwise an exception
is thrown
* If no error occurs executes save_transaction()


Buy inherits Transaction
--------------------------

The sell transaction inherits transaction, contains user purchase details

### private Ticket* ticket
* Reference to a ticket

### private String title
* The title of the event

### private int volume
* The volume of tickets for sale

### private String seller
* The name of the seller

### Buy(User current_user)
* If the user object is null the transaction fails and throws an exception (user is not logged in)
* If the current_user does not have privileges exception is thrown

### void process_title(String input, AvailableTickets available_tickets)
* Processes the event title, if the title is valid and exists saves the title, otherwise an exception is thrown

### void process_volume(String input)
* Process the ticket volume, if the amount is valid, saves the volume, otherwise an exception
is thrown

### void process_seller(String input, , AvailableTickets available_tickets)
* Process the seller's username, if the seller exists and the event title specified is sold by the seller
the Ticket object is saved. Otherwise, an exception is thrown if seller does not exist, or seller can not
be found that is selling tickets for event.

### void process_confirmation(String input)
* If the user confirms the transaction as "yes" the transaction is saved, save_transaction() executed, otherwise
an exception is thrown and the transaction is discarded.
* If no error occurs executes save_transaction()



Refund inherits Transaction
-----------------------------

The refund transaction inherits transaction, contains user refund details

### private String buyer
* The name of the buyer

### private String seller
* The name of the seller

### private double credit

### Refund(User current_user)
* If the user object is null the transaction fails and throws an exception (user is not logged in)
* If the current_user does not have privileges exception is thrown

### void process_buyer(String input, CurrentUserAccounts user_accounts)
* Processes the buyer username, if the username is valid and exists saves the username, otherwise
an exception is thrown

### void process_seller(String input, AvailableTickets available_tickets)
* Process the seller's username, if the seller exists, save the seller's username. Otherwise, an exception
is thrown.

### void process_credit(String input)
* Process the credit amount, if the amount is valid save the credit value, otherwise an exception is thrown.
* If no error occurs executes save_transaction()



AddCredit inherits Transaction
-----------------------------

The addcredit transaction inherits transaction, contains user credit details

### private String username
* The name of the user to add credit to if executed in admin mode

### private double credit

### AddCredit(User current_user)
* If the user object is null the transaction fails and throws an exception (user is not logged in)
* If the current_user does not have privileges exception is thrown

### void process_username(String input, CurrentUserAccounts user_accounts)
* Processes the username, if the username is valid and exists saves the username, otherwise
an exception is thrown

### void process_credit(String input)
* Process the credit amount, if the amount is valid save the credit value, otherwise an exception is thrown.
* If no error occurs executes save_transaction()