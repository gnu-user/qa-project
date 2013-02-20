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

* (Interface) *Transaction* (implemented by each of the following classes)
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


Other
--------

Possible ENUM of the various error codes which can then be mapped to strings, although
this is not necessary.


File I/O Classes
------------------

### CurrentUserAccounts

This class verifies the current user accounts file exists, loads the contents into memory
and checks the current user accounts file for corrupted entries, if any error occurs
reading file an exception thrown.

#### private vector<User> users
* A vector which contains all of the users from the current user accounts file

#### CurrentUserAccount(String cua_file)
* Constructor which accepts the current user accounts file path
* throws an exception if file does not exist (DNE) or if corrupted
* Adds each of the users in the file to the users vector

#### bool has_user(String username)
* Returns true if if the user is found

#### User get_user(String username)
* Returns a User (Object) if the user is found in the current user account file, if user is not
  found returns NULL


### AvailableTickets

This class verifies the available tickets file exists, loads content into memory and checks the file,
if the file is corrupted or any error occurs reading the file an exception is thrown.

#### private vector<Tickets> tickets
* A vector which contains all of the tickets from the available tickets file (ATF)

#### AvailableTickets(String atf_file)
* Constructor which accepts the atf file path
* throws an exception if file does not exist (DNE) or if corrupted

#### bool has_event(String event)
* Returns true if the atf has the event listed

#### bool has_seller(String username)
* Returns true if the atf has the seller listed

#### Ticket get_ticket(String event, String username)
* Returns a Ticket (Object) if the ticket is found that matches the event and the username of
* the seller, NULL returned otherwise.


### DailyTransaction

Saves daily transaction events in memory and writes them to a file at the end of a session (when 
logging out).

#### private vector<Transaction> transactions
* A vector which contains all of the saved transactions in memory

#### void save(Transaction transaction)
* Saves a transaction in memory, all transactions must implement the Transaction interface

#### void write(String filename)
* Writes the daily transaction file to the file specified, throws an exception if an error occurs




Program State Classes
-----------------------

### User

Contains the information for a user, such as username, type, credit, and permissions.

#### private String username
* The user's name

#### private String type
* The user's type

#### private double credit
* The user's credit

#### private vector<String> permissions
* The user's permissions, transactions the user can use

#### User(String username, String type, double credit)
* Constructor for the user

#### String get_username()
* Returns the user's username

#### String get_type()
* Returns the user's type

#### double get_credit()
* Returns the user's credit

#### bool has_permission(String transaction)
* Returns true if the user has permissions for the transaction


### Ticket

Contains the ticket information, such as event name, seller's username, number of
tickets for sale, and price per ticket.

#### private String event
* The event name for the ticket

#### private String seller
* The username of the seller

#### private int volume
* The volume/number of tickets available for sale

#### private double price
* The price per ticket

#### String get_event()
* Returns the event title

#### String get_seller()
* Returns the seller's username

#### int get_volume()
* Returns the volume of tickets available for sale

#### double get_price()
* Returns the price per ticket