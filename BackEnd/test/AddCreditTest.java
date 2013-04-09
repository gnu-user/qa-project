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

import java.io.IOException;

import org.junit.Test;


public class AddCreditTest
{
    /* Objects used for executing the test suite */
    private AvailableTickets availableTickets;
    private CurrentUserAccounts currentAccounts;
    private AddCredit addCredit;
    
    /* Parameters used for the tests */
    private static final String username = "buyer";
    private static final String unknownUser = "nobuyer";
    private static final String type = "BS";
    private static final Double credit = 1000.00;
    private static final Double creditOverflow = 1000.02;
    private static final Double maxCredit = 1000.01;
    private static final String transaction = "06_buyer___________BS_000010.00";
    
    
    /**
     * Test method for {@link AddCredit#execute(CurrentUserAccounts, AvailableTickets)}.
     * 
     * Test the execute method in the Create class, by providing a valid username, 
     * resulting in the true execution branch (the method being executed to satisfy 
     * this branch is tested elsewhere). The user account specified by the username 
     * provided must have less than 999999.99 credit, but the amount added must increase 
     * the credit beyond that value. This must result in a Failed Constraint exception. 
     * This test covers the first of 4 possible execution paths.
     * @throws FatalError 
     * @throws IOException 
     * @throws NumberFormatException 
     */
    @Test
    public void testExecute1() throws FatalError, NumberFormatException, IOException
    {
        /* Create an instance of the ATF and CUA file for this test */
        availableTickets = new AvailableTickets("files/AddCreditTest.atf");
        currentAccounts = new CurrentUserAccounts("files/AddCreditTest.cua");
        
        /* Create the addcredit transaction with a credit overflow */
        addCredit = new AddCredit(username, type, creditOverflow, transaction);
        
        /* Verify that an ExceptionCodes.USER_CREDIT_OVERFLOW is thrown */
        try
        {
            addCredit.execute(currentAccounts, availableTickets);
        }
        catch (FailedConstraint e)
        {
            assertEquals(ExceptionCodes.USER_CREDIT_OVERFLOW.toString(), e.getMessage());
        }
    }

    /**
     * Test method for {@link AddCredit#execute(CurrentUserAccounts, AvailableTickets)}.
     * 
     * Test the execute method in the Create class, by providing a valid username, 
     * resulting in the true execution branch (the method being executed to satisfy 
     * this branch is tested elsewhere). The user account specified by the username 
     * provided must have less than 999999.99 credit, and the amount added must not 
     * increase the credit beyond that value. The amount of credit added must exceed 
     * 1000. This must result in a Failed Constraint exception. This test covers
     * the second of 4 possible execution paths.
     * @throws FatalError 
     * @throws IOException 
     * @throws NumberFormatException 
     */
    @Test
    public void testExecute2() throws FatalError, NumberFormatException, IOException
    {
        /* Create an instance of the ATF and CUA file for this test */
        availableTickets = new AvailableTickets("files/AddCreditTest.atf");
        currentAccounts = new CurrentUserAccounts("files/AddCreditTest.cua");
        
        /* Create the addcredit transaction with max credit for a session overflow */
        addCredit = new AddCredit(username, type, maxCredit, transaction);
        
        /* Verify that an ExceptionCodes.USER_CREDIT_SESSION_OVERFLOW is thrown */
        try
        {
            addCredit.execute(currentAccounts, availableTickets);
        }
        catch (FailedConstraint e)
        {
            assertEquals(ExceptionCodes.USER_CREDIT_SESSION_OVERFLOW.toString(), e.getMessage());
        }
    }

    /**
     * Test method for {@link AddCredit#execute(CurrentUserAccounts, AvailableTickets)}.
     * 
     * Test the execute method in the Create class, by providing a valid username, 
     * resulting in the true execution branch (the method being executed to satisfy
     * this branch is tested elsewhere). The user account specified by the username 
     * provided must have less than 999999.99 credit, and the amount added must not 
     * increase the credit beyond that value. The amount of credit added plus the 
     * amount of credit added per this session value must not exceed 1000. The 
     * credit must be added to the user’s account. This test covers the third of 
     * 4 possible execution paths.
     * @throws FailedConstraint 
     * @throws IOException 
     * @throws NumberFormatException 
     */
    @Test
    public void testExecute3() throws FatalError, FailedConstraint, NumberFormatException, IOException
    {
        /* Create an instance of the ATF and CUA file for this test */
        availableTickets = new AvailableTickets("files/AddCreditTest.atf");
        currentAccounts = new CurrentUserAccounts("files/AddCreditTest.cua");
        
        /* Get the user's initial credit before credit added */
        Double initCredit = currentAccounts.getUser(username).getCredit();
        
        /* Create a valid addcredit transaction add 1000 credit to the user account */
        addCredit = new AddCredit(username, type, credit, transaction);

        /* Verify the credit was added to the user's account */
        addCredit.execute(currentAccounts, availableTickets);
        assertEquals((Double) (initCredit + credit), currentAccounts.getUser(username).getCredit());
    }
    
    /**
     * Test method for {@link AddCredit#execute(CurrentUserAccounts, AvailableTickets)}.
     * 
     * Test the execute method in the Create class, by providing an invalid 
     * username, resulting in the false execution branch. This must result 
     * in a Failed Constraint exception.
     * @throws FatalError 
     * @throws IOException 
     * @throws NumberFormatException 
     */
    @Test
    public void testExecute4() throws FatalError, NumberFormatException, IOException
    {
        /* Create an instance of the ATF and CUA file for this test */
        availableTickets = new AvailableTickets("files/AddCreditTest.atf");
        currentAccounts = new CurrentUserAccounts("files/AddCreditTest.cua");
        
        /* Create the addcredit transaction with an unknow user */
        addCredit = new AddCredit(unknownUser, type, credit, transaction);
        
        /* Verify that an ExceptionCodes.UNKNOWN_USER is thrown */
        try
        {
            addCredit.execute(currentAccounts, availableTickets);
        }
        catch (FailedConstraint e)
        {
            assertEquals(ExceptionCodes.UNKNOWN_USER.toString(), e.getMessage());
        }           
    }
    
    /**
     * Test method for {@link AddCredit#getTransaction()}.
     */
    @Test
    public void testGetTransaction()
    {
        /* Verify the correct transaction returned */
        addCredit = new AddCredit(username, type, credit, transaction);
        assertEquals(transaction, addCredit.getTransaction());
    }
}
