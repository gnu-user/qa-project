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


public class UserTest
{
    /* User object used for the tests */
    private User user;
    
    /* Parameters for the User object and used for tests */
    private static final String username = "buyer";
    private static final String type = "BS";
    private static final Double credit = 100.00;
    private static final Double newCredit = 50.00;
    private static final Double intialCreditAdded = 0.0;
    private static final Double creditAdded = 25.00;
    
    /**
     * Test setup, create the User object used for the tests
     * 
     * @throws java.lang.Exception
     */
    @Before
    public void setUp() throws Exception
    {
        user = new User(username, type, credit);
    }

    /**
     * Test method for {@link User#getUsername()}.
     * 
     * Tests the getUsername method in the User class, by executing the method. 
     * This method is a simple accessor method with only one return call.
     */
    @Test
    public void testGetUsername()
    {
        assertEquals(user.getUsername(), username);
    }

    /**
     * Test method for {@link User#getType()}.
     * 
     * Tests the getType method in the User class, by executing the method. 
     * This method is a simple accessor method with only one return call.
     */
    @Test
    public void testGetType()
    {
        assertEquals(user.getType(), type);
    }

    /**
     * Test method for {@link User#getCredit()}.
     * 
     * Tests the getCredit method in the User class, by executing the method. 
     * This method is a simple accessor method with only one return call.
     */
    @Test
    public void testGetCredit()
    {
        assertEquals(user.getCredit(), credit);
    }

    /**
     * Test method for {@link User#setCredit(java.lang.Double)}.
     * 
     * Tests the setCredit method in the User class, by executing the method 
     * using a random value. This method is a simple mutator method which only 
     * sets the value of the volume attribute internally.
     */
    @Test
    public void testSetCredit()
    {
        user.setCredit(newCredit);
        assertEquals(user.getCredit(), newCredit);
    }

    /**
     * Test method for {@link User#getCreditAdded()}.
     */
    @Test
    public void testGetCreditAdded()
    {
        assertEquals(user.getCreditAdded(), intialCreditAdded);
    }
    
    /**
     * Test method for {@link User#setCreditAdded(java.lang.Double)}.
     */
    @Test
    public void testSetCreditAdded()
    {
        user.setCreditAdded(creditAdded);
        assertEquals(user.getCreditAdded(), creditAdded);
    }
}
