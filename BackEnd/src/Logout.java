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

/**
 * Logout Provides methods and attributes for processing the logout
 * transaction.
 * 
 * @author Jonathan Gillett
 * @author Daniel Smullen
 * @author Rayan Alfaheid
 */
public class Logout implements Transaction
{
    private String username;
    private String type;
    private Double credit;
    private String transaction;


    /**
     * Constructor for the class. Accepts and populates class attributes with values passed in.
     * 
     * @param username String value for the username of the user which is logging out.
     * @param type String value for the type of the user who is logging out.
     * @param credit String value for the credit amount of the user who is logging out.
     */
    public Logout(String username, String type, Double credit, String transaction)
    {
        this.username = username;
        this.type = type;
        this.credit = credit;
        this.transaction = transaction;
    }

    /**
     * Performs the logout transaction. Resets the amount of credit added this session
     * and logs the user out.
     * 
     * @param cua A reference to the CurrentUserAccounts object used by the back-end.
     * @param atf A reference to the AvailableTickets object used by the back-end.
     * 
     * @see Transaction#execute(CurrentUserAccounts, AvailableTickets)
     */
    public void execute(CurrentUserAccounts cua, AvailableTickets atf)
    {
    	for (User user : cua.getAllUsers())
    	{
    		user.setCreditAdded(0.00);
    	}
    }

	/* (non-Javadoc)
	 * @see Transaction#getTransaction()
	 */
	public String getTransaction() {
		return transaction;
	}

}