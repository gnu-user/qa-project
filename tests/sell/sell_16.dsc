TITLE
    Ticket Volume Input (Edge Case, non integer input, garbage)
DESCRIPTION
    Run the login transaction using an admin account. Initiate the sell 
    transaction. Enter a valid title, and enter valid numerical input (a double 
    with two decimal places between 0.00 and 999.99 inclusive) when prompted to 
    enter a ticket price. Enter a non-numerical value when prompted to enter a 
    ticket volume. Verify that the value is not accepted, and an error occurs.
DEPENDENCIES
    sell_15
