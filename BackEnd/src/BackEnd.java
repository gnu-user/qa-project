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
 * BackEnd The driver class for the back-end. Contains the main methods for
 * execution of the back-end.
 * 
 * @author Jonathan Gillett
 * @author Daniel Smullen
 * @author Rayan Alfaheid
 */
public class BackEnd
{

	/**
	 * main The main execution path for the program.
	 * 
	 * @param args Accepts command-line arguments.
	 * Arguments must take the following form: 
	 * <br>
	 * ./BackEnd path1 path2 path3
	 * <br>
	 * The path items specified are:
	 * <br>path1: The path to the current user accounts file.
	 * <br>path2: The path to the available tickets file.
	 * <br>path3: The path to the daily transaction files' directory.
	 */
	public static void main(String[] args)
	{
	    if (args.length < 3)
	    {
	        System.err.println("Usage:   java BackEnd path1 path2 path3");
	        System.err.println("The path items specified are:");
	        System.err.println("path1: The path to the current user accounts file.");
    		System.err.println("path2: The path to the available tickets file.");
			System.err.println("path3: The path to the daily transaction files' directory.");
	        System.err.println("\nExample: java BackEnd accounts.cua tickets.atf transactions/");
	        
	        System.exit(1);
	    }
		try
        {
            AvailableTickets availableTickets = new AvailableTickets(args[0]);
            System.out.println("Current user accounts file read successfully.");
            availableTickets.displayTickets();
            
            CurrentUserAccounts currentAccounts = new CurrentUserAccounts(args[1]);
            System.out.println("Available tickets file read successfully.");
            currentAccounts.displayUsers();
            
            DailyTransactions transactions = new DailyTransactions(args[2]);
            System.out.println("Daily transactions files read successfully.");
            transactions.displayTransactions();
            
            /* Write the data in memory to file */
            availableTickets.write();
            currentAccounts.write();
        }
        catch (FatalError e)
        {
            System.err.println(e.getMessage());
            System.err.println("Cause of Error: " + e.getCause().getMessage());
            System.exit(1);
        }
	}
}
