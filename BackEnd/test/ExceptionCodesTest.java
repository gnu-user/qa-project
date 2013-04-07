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


public class ExceptionCodesTest
{

    /* Objects used for executing the test suite */
    private static ExceptionCodes exception;
    
    
    /**
     * Test setup, create the exception object used for the tests
     * 
     * @throws java.lang.Exception
     */
    @Before
    public void setUp() throws Exception
    {
        exception = ExceptionCodes.NOT_YET_IMPLEMENTED;
    }

    /**
     * Test method for {@link ExceptionCodes#toString()}.
     * 
     * Tests the toString method in the ExceptionCodes enumeration, by executing
     * the method. This method is a simple override of the basic Object toString 
     * method, with only one return call.
     */
    @Test
    public void testToString()
    {
        assertEquals(ExceptionCodes.NOT_YET_IMPLEMENTED.toString(), exception.toString());
    }
}