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


public class DeleteTest
{

    /* Objects used for executing the test suite */
    private AvailableTickets availableTickets;
    private CurrentUserAccounts currentAccounts;
 
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
        availableTickets = new AvailableTickets("files/DeleteTest.atf");
        currentAccounts = new CurrentUserAccounts("files/DeleteTest.cua");
    }

    /**
     * Test method for {@link Delete#execute(CurrentUserAccounts, AvailableTickets)}.
     * 
     * Test the execute method in the Delete class, by providing a valid username, 
     * resulting in the true execution branch (the method being executed to satisfy 
     * this branch is tested elsewhere).
     * @throws FailedConstraint 
     */
    @Test
    public void testExecute1() throws FailedConstraint
    {
        /* Create an instance of a delete transaction */
        Delete delete = new Delete(existingUsername, type, credit, transaction);
        delete.execute(currentAccounts, availableTickets);
       
        /* Verify the delete statement was executed */
        assertFalse(currentAccounts.hasUser(existingUsername));
    }
    
    /**
     * Test method for {@link Delete#execute(CurrentUserAccounts, AvailableTickets)}.
     * 
     * Test the execute method in the Create class, by providing an invalid username, 
     * resulting in the false execution branch (the method being executed to satisfy 
     * this branch is tested elsewhere). Verify that an exception is thrown for 
     * a Failed Constraint.
     * @throws FailedConstraint 
     */
    @Test(expected=FailedConstraint.class)
    public void testExecute2() throws FailedConstraint
    {
        /* Attempt to delete a non-existing user, exception must be thrown */
        Delete delete = new Delete(unknownUsername, type, credit, transaction);
        delete.execute(currentAccounts, availableTickets);
    }

    /**
     * Test method for {@link Delete#getTransaction()}.
     */
    @Test
    public void testGetTransaction()
    {
        /* Verify the transaction returned is correct */
        Delete delete = new Delete(existingUsername, type, credit, transaction);
        assertEquals(delete.getTransaction(), transaction);
    }
}
