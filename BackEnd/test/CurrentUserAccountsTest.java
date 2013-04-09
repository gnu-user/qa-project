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

import org.junit.Before;
import org.junit.Test;


public class CurrentUserAccountsTest
{
	private CurrentUserAccounts currentAccounts;
	private User testUser;
	
	private static final String invalidUser = "invalid";
	private static final String knownUser = "administrator";
	private static final String userType = "AA";
	private static final Double userCredit = 100.00;
	

    /**
     * Test method for {@link CurrentUserAccounts#addUser(User)}.
     * 
     * Tests the addUsermethod in the CurrentUserAccounts class, by executing the 
     * method using a valid User object. This method is a simple mutator method 
     * which only adds the provided object to the collection internally.
     * @throws IOException 
     * @throws FatalError 
     * @throws NumberFormatException 
     */
    @Test
    public void testAddUser() throws NumberFormatException, FatalError, IOException
    {
    	currentAccounts = new CurrentUserAccounts("files/CurrentUserAccountsTestAddUser.cua");
    	
    	testUser = new User (knownUser, userType, userCredit);
    	currentAccounts.addUser(testUser);
    	
    	assertEquals(testUser, currentAccounts.getUser(knownUser));
    }

    /**
     * Test method for {@link CurrentUserAccounts#deleteUser(java.lang.String)}.
     * 
     * Tests the deleteUser method in the CurrentUserAccounts class, by executing 
     * the method using a valid username for one of the User objects in the internal 
     * collection. Verify that the object is deleted.
     * @throws IOException 
     * @throws FatalError 
     * @throws NumberFormatException 
     */
    @Test
    public void testDeleteUser() throws NumberFormatException, FatalError, IOException
    {
    	currentAccounts = new CurrentUserAccounts("files/CurrentUserAccountsTestDeleteUser.cua");
    	
    	currentAccounts.deleteUser(knownUser);
    	
    	assertEquals(currentAccounts.getAllUsers().size(), 0);
    }

    /**
     * Test method for {@link CurrentUserAccounts#getAllUsers()}.
     * 
     * Tests the getAllUsers method in the CurrentUserAccounts class, by executing 
     * the method. This method is a simple accessor method with only one return 
     * call.
     * @throws IOException 
     * @throws FatalError 
     * @throws NumberFormatException 
     */
    @Test
    public void testGetAllUsers() throws NumberFormatException, FatalError, IOException
    {
    	currentAccounts = new CurrentUserAccounts("files/CurrentUserAccountsTestGetAllUsers.cua");
    	
    	for (User user : currentAccounts.getAllUsers())
    	{
    		assertEquals(knownUser, user.getUsername());
    	}
    }
    
    /**
     * Test method for {@link CurrentUserAccounts#getUser(java.lang.String)}.
     * 
     * Tests the getUser method in the CurrentUserAccounts class, by executing the 
     * method, providing a valid username for a User that exists. Verify that the 
     * User object associated with that username exists.
     * @throws IOException 
     * @throws FatalError 
     * @throws NumberFormatException 
     */
    @Test
    public void testGetUser1() throws NumberFormatException, FatalError, IOException
    {
    	currentAccounts = new CurrentUserAccounts("files/CurrentUserAccountsTestGetUser1.cua");
    	testUser = new User(knownUser, userType, userCredit);
    	
    	//Can't check whether the two objects are equal, because they'll have different GUIDs.
    	//Instead, check all the attributes are the same.
    	assertEquals(testUser.getUsername(), currentAccounts.getUser(knownUser).getUsername());
    	assertEquals(testUser.getCredit(), currentAccounts.getUser(knownUser).getCredit());
    	assertEquals(testUser.getType(), currentAccounts.getUser(knownUser).getType());
    }

    /**
     * Test method for {@link CurrentUserAccounts#getUser(java.lang.String)}.
     * 
     * Tests the getUser method in the CurrentUserAccounts class, by executing the 
     * method, providing an invalid username for a User that does not exist. 
     * Verify that null is returned.
     * @throws IOException 
     * @throws FatalError 
     * @throws NumberFormatException 
     */
    @Test
    public void testGetUser2() throws NumberFormatException, FatalError, IOException
    {
    	currentAccounts = new CurrentUserAccounts("files/CurrentUserAccountsTestGetUser2.cua");
    	
    	assertEquals(null, currentAccounts.getUser(invalidUser));
    }
    
    /**
     * Test method for {@link CurrentUserAccounts#hasUser(java.lang.String)}.
     * 
     * Tests the hasUser method in the CurrentUserAccounts class, by executing the 
     * method, providing a valid username for a User that exists. Verify that the 
     * method returns true.
     * @throws IOException 
     * @throws FatalError 
     * @throws NumberFormatException 
     */
    @Test
    public void testHasUser1() throws NumberFormatException, FatalError, IOException
    {
    	currentAccounts = new CurrentUserAccounts("files/CurrentUserAccountsTestHasUser1.cua");
    	
    	assertTrue(currentAccounts.hasUser(knownUser));
    }

    /**
     * Test method for {@link CurrentUserAccounts#hasUser(java.lang.String)}.
     * 
     * Tests the hasUser method in the CurrentUserAccounts class, by executing the 
     * method, providing an invalid username for a User that does exist. Verify that 
     * the method returns false.
     * @throws IOException 
     * @throws FatalError 
     * @throws NumberFormatException 
     */
    @Test
    public void testHasUser2() throws NumberFormatException, FatalError, IOException
    {
    	currentAccounts = new CurrentUserAccounts("files/CurrentUserAccountsTestHasUser2.cua");
    	
    	assertFalse(currentAccounts.hasUser(invalidUser));
    }
    
    /**
     * Test method for {@link CurrentUserAccounts#write()}.
     * 
     * Tests the write method in the CurrentUserAccounts class, by executing the 
     * method, providing a filename that exists. The output must be written to the 
     * file, and the file closed.
     * @throws IOException 
     * @throws FatalError 
     * @throws NumberFormatException 
     */
    @Test
    public void testWrite() throws NumberFormatException, FatalError, IOException
    {
    	//Read in the blank CUA file.
    	currentAccounts = new CurrentUserAccounts("files/CurrentUserAccountsTestWrite.cua");
    	
    	//Create a User and add it to the CUA file.
    	testUser = new User(knownUser, userType, userCredit);
    	currentAccounts.addUser(testUser);
    	//Write the CUA file to disk.
    	currentAccounts.write();
    	
    	//Read in the modified CUA file.
    	currentAccounts = new CurrentUserAccounts("files/CurrentUserAccountsTestWrite.cua");
    	
    	//Check that the modified CUA file has the user we added.
    	assertTrue(currentAccounts.hasUser(knownUser));
    	
    	//Clean up.
    	currentAccounts.deleteUser(knownUser);
    	currentAccounts.write();
    }
    
    /**
     * Test method for {@link CurrentUserAccounts#parse()}.
     */
    @Test
    public void testParse1()
    {
        fail("Not yet implemented"); // TODO
    }
    
    /**
     * Test method for {@link CurrentUserAccounts#parse()}.
     */
    @Test
    public void testParse2()
    {
        fail("Not yet implemented"); // TODO
    }
    
    /**
     * Test method for {@link CurrentUserAccounts#parse()}.
     */
    @Test
    public void testParse3()
    {
        fail("Not yet implemented"); // TODO
    }
}
