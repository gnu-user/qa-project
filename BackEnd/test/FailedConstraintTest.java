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


public class FailedConstraintTest
{
    /* Parameters used for the test */
    private static final String transaction = "04_The_Godfather_______unknownuser___004_010.00";
    /**
     * Test method for {@link FailedConstraint#FailedConstraint(ExceptionCodes, java.lang.String)}.
     * 
     * Tests the constructor for the FailedConstraint class by executing the method.
     * This method is a simple constructor, and must only instantiate an Exception. Verify 
     * that an exception is thrown.
     * @throws FailedConstraint 
     */
    @Test(expected=FailedConstraint.class)
    public void testFailedConstraint() throws FailedConstraint
    {
        throw new FailedConstraint(ExceptionCodes.UNKNOWN_USER, transaction);
    }
}
