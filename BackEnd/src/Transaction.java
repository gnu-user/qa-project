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
 * Transaction This interface guarantees that all transactions that the back-end
 * implements contain an access method for obtaining the original transaction string,
 * and a method to execute the transaction.
 * 
 * @author Jonathan Gillett
 * @author Daniel Smullen
 * @author Rayan Alfaheid
 */
public interface Transaction
{
	/**
	 * Generic access method for obtaining the original transaction
	 * string for the transaction.
	 * 
	 * @return Returns the original transaction string.
	 */
	public String getTransaction();

	
    /**
     * Signature template for each transaction's method of execution. This method
     * is implemented differently for each transaction.
     * 
     * @param cua A reference to the current user accounts file.
     * @param atf A reference to the available tickets file.
     * 
     * @throws FailedConstraint All execute methods are capable of throwing failed constraints.
     * The implementation of these failed constraints differs for each transaction.
     */
    public void execute(CurrentUserAccounts cua, AvailableTickets atf) throws FailedConstraint;

}