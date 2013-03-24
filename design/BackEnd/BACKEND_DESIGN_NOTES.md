BACK-END DESIGN NOTES
========================================

Overall Architecture
----------------------------------------

The overall architecture is very similar to the front-end EXCEPT instead of
processing valid text, etc.. the back-end is concerned with handling valid
states (ie. number of tickets available not less than 0) and then proceeding
to update the CUA and ATF.

The CUA and ATF are (READ/WRITE)

The DTF is READ-ONLY

The DTF is merged and then parsed and is composed of an array of transaction
objects, each transaction object is instantiated with references to the appropriate
ATF/CUA required to execute the transaction & change the state.

The Arraylist is then iterated over and each transaction which implements execute()
is executed. Any invalid states cause a failed constraint exception which is
logged.



Classes
----------------------------------------

The Back-end is very similar to the front-end in terms of design and has the
following classes

### Classes for handling file I/O

* CurrentUserAccounts
* AvailableTickets
* DailyTransactions


### Classes to facilitate program state 

* User
* Ticket


### Classes for handling transactions

* (Abstract class) Transaction (inherited by each of the following classes)
* Login
* Logout
* Create
* Delete
* Sell
* Buy
* Refund
* AddCredit


### Error/Exception handling classes

* FatalError
* FailedConstraint

### Helper Classes (Provide helper/common functionality)

* Validate
* Format? A possible helper class to format CUA/ATF files to write out
