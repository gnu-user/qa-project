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


public class DecisionCoverageTest
{
    /* Objects used for executing the test suite */
    private AvailableTickets availableTickets;
    private CurrentUserAccounts currentAccounts;
    private Delete delete;
 
    /* Parameters used for the tests */
    private static final String existingUsername = "buyer";
    private static final String unknownUsername = "newuser";
    private static final String type = "BS";
    private static final Double credit = 0.0;
    private static final String transaction = "01_newuser_________BS_000000.00";
    
    /**
     * Test setup, create the objects needed to execute the tests
     * 
     * @throws Exception
     */
    @Before
    public void setUp() throws Exception
    {
        availableTickets = new AvailableTickets("files/DecisionCoverageTest.atf");
        currentAccounts = new CurrentUserAccounts("files/DecisionCoverageTest.cua");
    }


    /**
     * Test method for {@link Delete#execute(CurrentUserAccounts, AvailableTickets)}.
     * 
     * A test that provides decision coverage for the execute() method of the 
     * Delete class. Provides decision coverage for the execute method in the 
     * Delete class, by providing a valid username, resulting in the if 
     * statement being evaluated as true.
     * @throws FailedConstraint 
     */
    @Test
    public void testDecision1() throws FailedConstraint
    {
        /* Create an instance of a delete transaction */
        delete = new Delete(existingUsername, type, credit, transaction);
        delete.execute(currentAccounts, availableTickets);
       
        /* Verify the if statement was evaluated as true for the decision coverage */
        assertFalse(currentAccounts.hasUser(existingUsername));
    }
    
    /**
     * Test method for {@link Delete#execute(CurrentUserAccounts, AvailableTickets)}.
     * 
     * A test that provides decision coverage for the execute() method of the 
     * Delete class. Provides decision coverage for the execute method in the 
     * Delete class,  by providing an invalid username, resulting in the if 
     * statement being evaluated false and the else branch being executed.
     * @throws FailedConstraint 
     */
    @Test
    public void testDecision2()
    {
        /* Attempt to delete a non-existing user, verify the if statement was 
         * evaluated as false because an UNKNOWN_USER exception will be thrown */
        try
        {
            delete = new Delete(unknownUsername, type, credit, transaction);
            delete.execute(currentAccounts, availableTickets);
        }
        catch (FailedConstraint e)
        {
            assertEquals(ExceptionCodes.UNKNOWN_USER.toString(), e.getMessage());
        }   
    }
}
