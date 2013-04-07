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


public class SellTest
{
    /* Objects used for executing the test suite */
    private AvailableTickets availableTickets;
    private CurrentUserAccounts currentAccounts;
    private Sell sell;
    
    /* Parameters used for the tests */
    private static final String newEvent = "Goodfellas";
    private static final String currentEvent = "The Godfather";
    private static final String seller = "seller";
    private static final Integer volume = 10;
    private static final Integer overflowVolume = 200;
    private static final Double price = 10.00;
    private static final Double newPrice = 15.00;
    private static final String transaction = "04_The_Godfather_______seller__________010_010.00";
    
    
    /**
     * Setup the objects used for executing each test
     * 
     * @throws java.lang.Exception
     */
    @Before
    public void setUp() throws Exception
    {
        availableTickets = new AvailableTickets("files/SellTest.atf");
        currentAccounts = new CurrentUserAccounts("files/SellTest.cua");
    }

    /**
     * Test method for {@link Sell#execute(CurrentUserAccounts, AvailableTickets)}.
     * 
     * Tests the execute method for the Sell class by executing the method, 
     * providing a new and currently unsold ticket object. Verify that the 
     * new ticket is added to the available tickets collection.
     * @throws FailedConstraint 
     */
    @Test
    public void testExecute1() throws FailedConstraint
    {
        /* Create the sell transaction */
        sell = new Sell(newEvent, seller, volume, price, transaction);
        sell.execute(currentAccounts, availableTickets);
        
        /* Verify that new ticket is added to the available tickets collection */
        assertTrue(availableTickets.hasTicket(newEvent,seller));
    }

    /**
     * Test method for {@link Sell#execute(CurrentUserAccounts, AvailableTickets)}.
     * 
     * Tests the execute method for the Sell class by executing the method, 
     * providing an existing ticket, and providing a volume of 200. 
     * A Failed Constraint exception must be thrown.
     * @throws FailedConstraint 
     */
    @Test(expected=FailedConstraint.class)
    public void testExecute2() throws FailedConstraint
    {
        /* Create the sell transaction */
        sell = new Sell(currentEvent, seller, overflowVolume, price, transaction);
        
        /* Execute the transaction with an overflow volume of tickets */
        sell.execute(currentAccounts, availableTickets);
    }
    
    /**
     * Test method for {@link Sell#execute(CurrentUserAccounts, AvailableTickets)}.
     * 
     * Tests the execute method for the Sell class by executing the method, providing
     * an existing ticket, and providing a volume of 10, while the existing volume 
     * of tickets for the specified event is also 10. Specify the price as 15.00. 
     * Verify that the ticket data is updated in the available tickets collection 
     * accordingly.
     * @throws FailedConstraint 
     */
    @Test
    public void testExecute3() throws FailedConstraint
    {
        /* Get a record of the current ticket volume and price */
        Integer prevVolume = availableTickets.getTicket(currentEvent, seller).getVolume();
        Double prevPrice = availableTickets.getTicket(currentEvent, seller).getPrice();
        
        /* Execute the transaction and verify the ticket data has been updated */
        sell = new Sell(currentEvent, seller, volume, newPrice, transaction);
        sell.execute(currentAccounts, availableTickets);
        
        /* Now, volume should be previous volume + volume, price set to new price */
        assertEquals((Integer) (prevVolume + volume), availableTickets.getTicket(currentEvent, seller).getVolume());
        assertEquals(newPrice, availableTickets.getTicket(currentEvent, seller).getPrice());
    }
    
    /**
     * Test method for {@link Sell#getTransaction()}.
     * 
     * Tests the getTransaction method in the Sell class, by executing the method. 
     * This method is a simple accessor method with only one return call.
     */
    @Test
    public void testGetTransaction()
    {
        /* Verify the correct transaction returned */
        sell = new Sell(currentEvent, seller, volume, price, transaction);
        assertEquals(transaction, sell.getTransaction());
    }

}
