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
 * FailedConstraint A special type of exception class that allows for the inclusion of
 * data within the exception itself. This includes error codes and transaction strings
 * that cause failed constraints within the back-end.
 * 
 * @author Jonathan Gillett
 * @author Daniel Smullen
 * @author Rayan Alfaheid
 */
public class FailedConstraint extends Exception
{
	// Must be included in exceptions.
    private static final long serialVersionUID = 2801771587969692843L;

    /**
     * The constructor for the class. Takes an exception code and a transaction string
     * in order to generate a standard exception by calling the superclass constructor
     * method.
     * 
     * @param exception The ExceptionCodes object containing the exception being thrown.
     * @param transaction A string containing the transaction string that caused the error.
     */
    public FailedConstraint(ExceptionCodes exception, String transaction)
    {
        super(exception.toString(), new Throwable(transaction));
    }

}