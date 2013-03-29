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
 * FatalError A special type of exception class that results in termination
 * of the back-end. This class also allows for the inclusion of data
 * pertaining to the error, specifically which file.
 * 
 * @author Jonathan Gillett
 * @author Daniel Smullen
 * @author Rayan Alfaheid
 */
public class FatalError extends Exception
{
	//Must be included in exceptions.
    private static final long serialVersionUID = 888363566861043122L;

    /**
     * The constructor for the class. Allows for the inclusion of data
     * pertaining to the file that caused the error.
     * 
     * @param exception The exception string.
     * @param file The file which caused the fatal error.
     */
    public FatalError(ExceptionCodes exception, String file)
    {
        super(exception.toString(), new Throwable(file));
    }
}