TITLE
    Refund Transfer Credit Operation (Value Overflow)
DESCRIPTION
    Run the login transaction using an admin account. Initiate the refund 
    transaction. When prompted, enter a buyer which exists. When prompted, 
    enter a seller which exists. When prompted, enter a valid decimal value for 
    the refund amount (which is greater than the maximum credit value, of 
    999,999). Verify that the value is rejected, and an error occurs.
DEPENDENCIES
    refund_7
