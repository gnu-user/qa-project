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

import org.junit.Before;
import org.junit.Test;


public class RefundTest
{
    /* Objects used for executing the test suite */
    private AvailableTickets availableTickets;
    private CurrentUserAccounts currentAccounts;
    private Refund refund;
    
    /* Parameters used for the tests */
    private static final String knownBuyer = "buyer";
    private static final String unknownBuyer = "nobuyer";
    private static final String knownSeller = "seller";
    private static final String unknownSeller = "noseller";
    private static final Double credit = 10.0;
    private static final String transaction = "05_buyer___________seller__________000005.00";
    

    /**
     * Test method for {@link Refund#execute(CurrentUserAccounts, AvailableTickets)}.
     * 
     * Tests the execute method for the Refund class, by executing the method, 
     * providing an invalid username for both the buyer and seller. A Failed 
     * Constraint exception must be thrown.
     * @throws FatalError 
     */
    @Test
    public void testExecute1() throws FatalError
    {
        /* Create an instance of the ATF and CUA file for this test */
        availableTickets = new AvailableTickets("files/RefundTestExecute1.atf");
        currentAccounts = new CurrentUserAccounts("files/RefundTestExecute1.cua");
        
        /* Create the refund transaction with a buyer and seller that do not exist */
        refund = new Refund(unknownBuyer, unknownSeller, credit, transaction);
        
        /* Verify that an ExceptionCodes.UNKNOWN_USER is thrown */
        try
        {
            refund.execute(currentAccounts, availableTickets);
        }
        catch (FailedConstraint e)
        {
            assertEquals(ExceptionCodes.UNKNOWN_USER.toString(), e.getMessage());
        }
    }
    
    /**
     * Test method for {@link Refund#execute(CurrentUserAccounts, AvailableTickets)}.
     * 
     * Tests the execute method for the Refund class, by executing the method, 
     * providing a valid username for both the buyer and seller. The buyer’s 
     * credit must be 999,999.99. A Failed Constraint exception must be thrown.
     * @throws FatalError 
     */
    @Test
    public void testExecute2() throws FatalError
    {
        /* Create an instance of the ATF and CUA file for this test */
        availableTickets = new AvailableTickets("files/RefundTestExecute2.atf");
        currentAccounts = new CurrentUserAccounts("files/RefundTestExecute2.cua");
        
        /* Create a refund transaction with a buyer that has maximum credit of 999,999.99 */
        refund = new Refund(knownBuyer, knownSeller, credit, transaction);
        
        /* Verify that an ExceptionCodes.USER_CREDIT_OVERFLOW is thrown */
        try
        {
            refund.execute(currentAccounts, availableTickets);
        }
        catch (FailedConstraint e)
        {
            assertEquals(ExceptionCodes.USER_CREDIT_OVERFLOW.toString(), e.getMessage());
        }
    }
    
    /**
     * Test method for {@link Refund#execute(CurrentUserAccounts, AvailableTickets)}.
     * Tests the execute method for the Refund class, by executing the method, providing 
     * a valid username for both the buyer and seller. The seller’s credit must be zero. 
     * A Failed Constraint exception must be thrown.
     * @throws FatalError 
     */
    @Test
    public void testExecute3() throws FatalError
    {
        /* Create an instance of the ATF and CUA file for this test */
        availableTickets = new AvailableTickets("files/RefundTestExecute3.atf");
        currentAccounts = new CurrentUserAccounts("files/RefundTestExecute3.cua");
        
        /* Create a refund transaction with a seller that has 0 credit */
        refund = new Refund(knownBuyer, knownSeller, credit, transaction);
        
        /* Verify that an ExceptionCodes.USER_CREDIT_NEGATIVE is thrown */
        try
        {
            refund.execute(currentAccounts, availableTickets);
        }
        catch (FailedConstraint e)
        {
            assertEquals(ExceptionCodes.USER_CREDIT_NEGATIVE.toString(), e.getMessage());
        }
    }
    
    /**
     * Test method for {@link Refund#execute(CurrentUserAccounts, AvailableTickets)}.
     * 
     * Tests the execute method for the Refund class, by executing the method, 
     * providing a valid username for both the buyer and seller. The seller’s 
     * credit must be equal to the amount refunded. The buyer’s credit must be 
     * zero. Verify that the buyer’s credit is incremented, and the seller’s 
     * credit is decremented accordingly.
     * @throws FatalError 
     * @throws FailedConstraint 
     */
    @Test
    public void testExecute4() throws FatalError, FailedConstraint
    {
        /* Create an instance of the ATF and CUA file for this test */
        availableTickets = new AvailableTickets("files/RefundTestExecute4.atf");
        currentAccounts = new CurrentUserAccounts("files/RefundTestExecute4.cua");
        
        /* Execute refund transaction, everything is valid, buyer has 0 credit, seller has 10 */
        refund = new Refund(knownBuyer, knownSeller, credit, transaction);
        refund.execute(currentAccounts, availableTickets);
        
        /* Verify the transaction completed successfully the seller should have 0 credit, buyer 10 */
        assertEquals((Double) 0.00, currentAccounts.getUser(knownSeller).getCredit());
        assertEquals((Double) 10.00, currentAccounts.getUser(knownBuyer).getCredit());
    }

    /**
     * Test method for {@link Refund#getTransaction()}.
     * 
     * Tests the getTransaction method in the Refund class, by executing the method. 
     * This method is a simple accessor method with only one return call.
     */
    @Test
    public void testGetTransaction()
    {
        /* verify the correct transaction */
        refund = new Refund(knownBuyer, knownSeller, credit, transaction);
        assertEquals(transaction, refund.getTransaction());
    }
}
