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
            "Cause of Error: /home/jon/Source/github/qa-project/BackEnd/files/BackEndMain2.dtf\n";
    
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
                                        "files/"
                                     };
        BackEnd.main(args);
    }
    
    /**
     * Test method for {@link BackEnd#main(java.lang.String[])}.
     */
    @Test
    public void testMain3()
    {
        fail("Not yet implemented"); // TODO
    }
    
    /**
     * Test method for {@link BackEnd#main(java.lang.String[])}.
     */
    @Test
    public void testMain4()
    {
        fail("Not yet implemented"); // TODO
    }
    
    /**
     * Test method for {@link BackEnd#main(java.lang.String[])}.
     */
    @Test
    public void testMain5()
    {
        fail("Not yet implemented"); // TODO
    }

}
