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


public class LogoutTest
{
    /* Objects used for executing the create test suite */
    private AvailableTickets availableTickets;
    private CurrentUserAccounts currentAccounts;
    private Logout logout;
    
    /* Parameters used for the test */
    private static final String username = "administrator";
    private static final String type = "AA";
    private static final Double credit = 0.0;
    private static final String transaction = "00_administrator___AA_000000.00";
    
    
    /**
     * @throws java.lang.Exception
     */
    @Before
    public void setUp() throws Exception
    {
        availableTickets = new AvailableTickets("files/LogoutTest.atf");
        currentAccounts = new CurrentUserAccounts("files/LogoutTest.cua");
    }

    /**
     * Test method for {@link Logout#execute(CurrentUserAccounts, AvailableTickets)}.
     * 
     * Tests the execute method for the Logout class by executing the method. 
     * Verify that all the creditadded attributes in the objects within the 
     * cua collection are set to zero.
     */
    @Test
    public void testExecute()
    {
        /* Set the credit added to the buyer account */
        currentAccounts.getUser("buyer").setCreditAdded(10.00);
        
        /* Verify the credit added was reset after logging out */
        logout = new Logout(username, type, credit, transaction);
        logout.execute(currentAccounts, availableTickets);
        assertEquals((Double) 0.00,  currentAccounts.getUser("buyer").getCreditAdded());
    }

    /**
     * Test method for {@link Logout#getTransaction()}.
     */
    @Test
    public void testGetTransaction()
    {
        /* Verify the correct transaction is returned */
        logout = new Logout(username, type, credit, transaction);
        assertEquals(transaction, logout.getTransaction());
    }

}
