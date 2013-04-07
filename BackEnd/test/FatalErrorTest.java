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
import org.junit.Test;


public class FatalErrorTest
{
    /**
     * Test method for {@link FatalError#FatalError(ExceptionCodes, java.lang.String)}.
     * 
     * Tests the constructor for the FatalError class by executing the method. 
     * This method is a simple constructor, and must only instantiate an Exception. 
     * Verify that an exception is thrown.
     * @throws FatalError 
     */
    @Test(expected=FatalError.class)
    public void testFatalError() throws FatalError
    {
        throw new FatalError(ExceptionCodes.ATF_NOT_FOUND, "wrongfile.atf");
    }
}
