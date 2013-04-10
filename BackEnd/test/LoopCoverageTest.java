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


public class LoopCoverageTest
{
    /* Objects used for executing the test suite */
    private CurrentUserAccounts currentAccounts;
    
    /* Parameters used for the tests */
    private static final String knownUser = "administrator";
    
    
    /**
     * Test method for {@link CurrentUserAccounts#hasUser(java.lang.String)}.
     * 
     * A test that provides loop coverage for the hasUser method of the 
     * CurrentUserAccounts class, by providing an empty current user accounts 
     * file such that the loop body is executed zero times.
     * @throws IOException 
     * @throws FatalError 
     * @throws NumberFormatException 
     */
    @Test
    public void testLoop1() throws NumberFormatException, FatalError, IOException
    {
        /* Load an empty current user accounts file, loop executed zero times */
        currentAccounts = new CurrentUserAccounts("files/LoopCoverageTest1.cua");  
        assertFalse(currentAccounts.hasUser(knownUser));
    }

    /**
     * Test method for {@link CurrentUserAccounts#hasUser(java.lang.String)}.
     * 
     * A test that provides loop coverage for the hasUser method of the 
     * CurrentUserAccounts class, by providing an  current user accounts 
     * file with one user such that the loop body is executed once.
     * @throws IOException 
     * @throws FatalError 
     * @throws NumberFormatException 
     */
    @Test
    public void testLoop2() throws NumberFormatException, FatalError, IOException
    {
        /* Load a current user accounts file with one user, the loop body executed once */
        currentAccounts = new CurrentUserAccounts("files/LoopCoverageTest2.cua");  
        assertTrue(currentAccounts.hasUser(knownUser));
    }
    
    /**
     * Test method for {@link CurrentUserAccounts#hasUser(java.lang.String)}.
     * 
     * A test that provides loop coverage for the hasUser method of the 
     * CurrentUserAccounts class, by providing an  current user accounts 
     * file with two users such that the loop body is executed twice.
     * @throws IOException 
     * @throws FatalError 
     * @throws NumberFormatException 
     */
    @Test
    public void testLoop3() throws NumberFormatException, FatalError, IOException
    {
        /* Load a current user accounts file with two users, the loop body executed twice */
        currentAccounts = new CurrentUserAccounts("files/LoopCoverageTest2.cua");  
        assertTrue(currentAccounts.hasUser(knownUser));
    }
    
    /**
     * Test method for {@link CurrentUserAccounts#hasUser(java.lang.String)}.
     * 
     * A test that provides loop coverage for the hasUser method of the 
     * CurrentUserAccounts class, by providing an  current user accounts 
     * file with many users such that the loop body is executed many times.
     * @throws IOException 
     * @throws FatalError 
     * @throws NumberFormatException 
     */
    @Test
    public void testLoop4() throws NumberFormatException, FatalError, IOException
    {
        /* Load a current user accounts file with multiple users, loop is executed many times */
        currentAccounts = new CurrentUserAccounts("files/LoopCoverageTest2.cua");  
        assertTrue(currentAccounts.hasUser(knownUser));
    }
}
