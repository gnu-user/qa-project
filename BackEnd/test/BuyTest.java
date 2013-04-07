/**
 * Swift Ticket -- Back End
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
import static org.junit.Assert.*;
import org.junit.Test;


public class BuyTest
{
    /* Objects used for executing the test suite */
    private AvailableTickets availableTickets;
    private CurrentUserAccounts currentAccounts;
    private Buy buy;
    
    /* Parameters used for the tests */
    private static final String event = "The Godfather";
    private static final String knownBuyer = "buyer";
    private static final String unknownBuyer = "nobuyer";
    private static final String knownSeller = "seller";
    private static final String unknownSeller = "noseller";
    private static final Double price = 10.0;
    private static final String transaction = "04_The_Godfather_______seller__________004_010.00";
    

    /**
     * Test method for {@link Buy#execute(CurrentUserAccounts, AvailableTickets)}.
     * 
     * Test the execute method for the Buy class, by providing a buyer or seller 
     * that does not exist. A Failed Constraint exception must result. This is 
     * the first of 5 execution paths.
     * @throws FatalError 
     */
    @Test
    public void testExecute1() throws FatalError
    {
        /* Create an instance of the ATF and CUA file for this test */
        availableTickets = new AvailableTickets("files/BuyTestExecute1.atf");
        currentAccounts = new CurrentUserAccounts("files/BuyTestExecute1.cua");
        
        /* Create the buy transaction with a buyer and seller that do not exist */
        buy = new Buy(event, unknownBuyer, unknownSeller, 1, price, transaction);
        
        /* Verify that an ExceptionCodes.UNKNOWN_USER is thrown */
        try
        {
            buy.execute(currentAccounts, availableTickets);
        }
        catch (FailedConstraint e)
        {
            assertEquals(ExceptionCodes.UNKNOWN_USER.toString(), e.getMessage());
        }
    }
    
    /**
     * Test method for {@link Buy#execute(CurrentUserAccounts, AvailableTickets)}.
     * 
     * Test the execute method for the Buy class, by providing a buyer and seller 
     * that exists. The buyer provided must not have enough credit to complete the 
     * transaction. A Failed Constraint exception must result. This is the second 
     * of 5 execution paths.
     * @throws FatalError 
     */
    @Test
    public void testExecute2() throws FatalError
    {
        /* Create an instance of the ATF and CUA file for this test */
        availableTickets = new AvailableTickets("files/BuyTestExecute2.atf");
        currentAccounts = new CurrentUserAccounts("files/BuyTestExecute2.cua");
        
        /* Create the buy transaction with a buyer that does not have enough credit */
        buy = new Buy(event, knownBuyer, knownSeller, 1, price, transaction);
        
        /* Verify that an ExceptionCodes.USER_CREDIT_NEGATIVE is thrown */
        try
        {
            buy.execute(currentAccounts, availableTickets);
        }
        catch (FailedConstraint e)
        {
            assertEquals(ExceptionCodes.USER_CREDIT_NEGATIVE.toString(), e.getMessage());
        }
    }
    
    /**
     * Test method for {@link Buy#execute(CurrentUserAccounts, AvailableTickets)}.
     * 
     * Test the execute method for the Buy class, by providing a buyer and seller 
     * that exists. The buyer provided must have enough credit to complete the 
     * transaction. The seller must have 999,999.99 credit, with the sale 
     * resulting in an overflow. A Failed Constraint exception must result. 
     * This is the third of 5 execution paths.
     * @throws FatalError 
     */
    @Test
    public void testExecute3() throws FatalError
    {
        /* Create an instance of the ATF and CUA file for this test */
        availableTickets = new AvailableTickets("files/BuyTestExecute3.atf");
        currentAccounts = new CurrentUserAccounts("files/BuyTestExecute3.cua");
        
        /* Create the buy transaction with a seller that has maximum credit of 999,999.99 */
        buy = new Buy(event, knownBuyer, knownSeller, 1, price, transaction);
        
        /* Verify that an ExceptionCodes.USER_CREDIT_OVERFLOW is thrown */
        try
        {
            buy.execute(currentAccounts, availableTickets);
        }
        catch (FailedConstraint e)
        {
            assertEquals(ExceptionCodes.USER_CREDIT_OVERFLOW.toString(), e.getMessage());
        }
    }
    
    /**
     * Test method for {@link Buy#execute(CurrentUserAccounts, AvailableTickets)}.
     * 
     * Test the execute method for the Buy class, by providing a buyer and seller 
     * that exists. The buyer provided must have enough credit to complete the 
     * transaction. The seller must have zero credit. The transaction must specify 
     * that 2 tickets are purchased. The seller must only have 1 ticket available. 
     * A Failed Constraint exception must result. This is the fourth of 5 
     * execution paths.
     * @throws FatalError 
     */
    @Test
    public void testExecute4() throws FatalError
    {
        /* Create an instance of the ATF and CUA file for this test */
        availableTickets = new AvailableTickets("files/BuyTestExecute4.atf");
        currentAccounts = new CurrentUserAccounts("files/BuyTestExecute4.cua");
        
        /* Create buy transaction for 2 tickets, seller only has 1 ticket for sale */
        buy = new Buy(event, knownBuyer, knownSeller, 2, price, transaction);
        
        /* Verify that an ExceptionCodes.TICKET_VOLUME_NEGATIVE is thrown */
        try
        {
            buy.execute(currentAccounts, availableTickets);
        }
        catch (FailedConstraint e)
        {
            assertEquals(ExceptionCodes.TICKET_VOLUME_NEGATIVE.toString(), e.getMessage());
        }
    }
    
    /**
     * Test method for {@link Buy#execute(CurrentUserAccounts, AvailableTickets)}.
     * 
     * Test the execute method for the Buy class, by providing a buyer and seller 
     * that exists. The buyer provided must have enough credit to complete the 
     * transaction. The seller must have zero credit. The transaction must specify
     * that 2 tickets are purchased. The seller must only have 2 tickets available,
     * and the transaction must complete successfully. This is the fifth of 5 
     * execution paths.
     * @throws FatalError 
     * @throws FailedConstraint 
     */
    @Test
    public void testExecute5() throws FatalError, FailedConstraint
    {
        /* Create an instance of the ATF and CUA file for this test */
        availableTickets = new AvailableTickets("files/BuyTestExecute5.atf");
        currentAccounts = new CurrentUserAccounts("files/BuyTestExecute5.cua");
        
        /* Create the buy transaction where everything is valid, seller has 2 tickets */
        buy = new Buy(event, knownBuyer, knownSeller, 2, price, transaction);
        buy.execute(currentAccounts, availableTickets);
        
        /* Verify the transaction completed successfully seller has no remaining tickets */
        assertEquals((Integer) 0, availableTickets.getTicket(event, knownSeller).getVolume());
    }
    
    /**
     * Test method for {@link Buy#getTransaction()}.
     */
    @Test
    public void testGetTransaction()
    {
        /* Create an instance of the buy transaction */
        buy = new Buy(event, knownBuyer, knownSeller, 1, price, transaction);
        
        /* Verify the correct transaction code returned */
        assertEquals(transaction, buy.getTransaction());
    }

}
