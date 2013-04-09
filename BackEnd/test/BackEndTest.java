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

import org.junit.Rule;
import org.junit.Test;
import org.junit.contrib.java.lang.system.Assertion;
import org.junit.contrib.java.lang.system.ExpectedSystemExit;
import org.junit.contrib.java.lang.system.StandardErrorStreamLog;


public class BackEndTest
{
    /* Parameters used for executing the test suite */
    private static final String corruptDTF = 
            "ERROR: CORRUPT_DTF: An error occurred reading the daily transactions file, data corrupted.\n" +
            "Cause of Error: files/BackEndMain2.dtf\n";
    private static final String sessionOverflow =
            "ERROR: USER_CREDIT_SESSION_OVERFLOW: Invalid credit value, amount of credit added per session cannot exceed 1000.00.\n" +
            "Cause of Error: 06_buyer___________BS_002000.00\n";
    
    @Rule
    public final ExpectedSystemExit exit = ExpectedSystemExit.none();
    
    @Rule
    public final StandardErrorStreamLog log = new StandardErrorStreamLog();
    
    
    /**
     * Test method for {@link BackEnd#main(java.lang.String[])}.
     * 
     * Test the main method by executing it, without providing arguments. 
     * The system usage error message must be output, and the program must exit.
     * @throws IOException 
     */
    @Test
    public void testMain1() throws IOException
    {
        exit.expectSystemExitWithStatus(1);
        BackEnd.main(new String[2]);
    }
    
    /**
     * Test method for {@link BackEnd#main(java.lang.String[])}.
     * 
     * Test the main method by executing it, providing arguments for two valid files, 
     * and one invalid file. This must result in a fatal error.
     * @throws IOException 
     */
    @Test
    public void testMain2() throws IOException
    {
        /* Verify that the error message for corrupted DTF was displayed */
        exit.expectSystemExitWithStatus(1);
        exit.checkAssertionAfterwards(new Assertion() {
            public void checkAssertion() 
            {
                assertEquals(corruptDTF, log.getLog());
            }
          });
        
        /* Execute the BackEnd with two valid files and one that is invalid */
        String[] args = new String[] { "files/BackEndMain2.atf", 
                                        "files/BackEndMain2.cua", 
                                        "files/BackEndMain2.dtf"
                                     };
        BackEnd.main(args);
    }
    
    /**
     * Test method for {@link BackEnd#main(java.lang.String[])}.
     * 
     * Test the main method by executing it, providing arguments for all valid 
     * files, with an invalid entry that results in a failed constraint in one 
     * of the files. This must result in a Failed Constraint exception.
     * @throws IOException 
     */
    @Test
    public void testMain3() throws IOException
    {
        exit.expectSystemExitWithStatus(0);
        
        /* Execute the BackEnd with all valid files */
        String[] args = new String[] { "files/BackEndMain3.atf", 
                                        "files/BackEndMain3.cua", 
                                        "files/BackEndMain3.dtf"
                                     };
        BackEnd.main(args);
        
        /* Verify that an ExceptionCodes.USER_CREDIT_SESSION_OVERFLOW was thrown */
        assertEquals(sessionOverflow, log.getLog());    
    }
    
    /**
     * Test method for {@link BackEnd#main(java.lang.String[])}.
     * 
     * Test the main method by executing it, providing arguments for all valid 
     * files, with valid contents. After processing the file contents, verify 
     * the ATF and CUA are written to disk.
     * @throws IOException 
     */
    @Test
    public void testMain4() throws IOException
    {
        /* Verify that the backend exits successfully with exit status 0 */
        exit.expectSystemExitWithStatus(0);
        
        /* Execute the BackEnd with all valid files */
        String[] args = new String[] { "files/BackEndMain4.atf", 
                                        "files/BackEndMain4.cua", 
                                        "files/BackEndMain4.dtf"
                                     };
        BackEnd.main(args);
        
        /* Verify that no exceptions have been thrown, STDERR empty */
        assertEquals("", log.getLog());
    }
}
