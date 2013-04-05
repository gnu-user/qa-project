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
import org.junit.Test;


public class ValidateTest
{
    /**
     * Test method for {@link Validate#atfEntry(java.lang.String)}.
     * 
     * Tests the atfEntry method in the Validate class, covering execution 
     * where the regular expression returns true.
     */
    @Test
    public void testAtfEntry1()
    {
        assertTrue(Validate.atfEntry("The_Godfather_III___seller__________100_010.00"));
    }

    /**
     * Test method for {@link Validate#atfEntry(java.lang.String)}.
     * 
     * Tests the atfEntry method in the Validate class, covering execution 
     * where the regular expression returns false.
     */
    @Test
    public void testAtfEntry2()
    {
       assertFalse(Validate.atfEntry("THIS_TITLE_IS_TOO_LONG....___seller__________100_010.00")); 
    }
    
    /**
     * Test method for {@link Validate#cuaEntry(java.lang.String)}.
     * 
     * Tests the cuaEntry method in the Validate class, covering execution 
     * where the regular expression returns true.
     */
    @Test
    public void testCuaEntry1()
    {
        assertTrue(Validate.cuaEntry("seller__________SS_000135.00"));
    }

    
    /**
     * Test method for {@link Validate#cuaEntry(java.lang.String)}.
     * 
     * Tests the cuaEntry method in the Validate class, covering execution 
     * where the regular expression returns false.
     */
    @Test
    public void testCuaEntry2()
    {
        assertFalse(Validate.cuaEntry("INVALID#@USER!__SS_000135.00"));
    }    
    
    /**
     * Test method for {@link Validate#dtfEntry(java.lang.String)}.
     * 
     * Tests the dtfEntry method in the Validate class, covering execution 
     * where the daily transaction entry matches logout, create, delete, or
     * addcredit, and returns tru
     */
    @Test
    public void testDtfEntry1()
    {
        assertTrue(Validate.dtfEntry("06_buyer___________BS_000010.00"));
    }

    /**
     * Test method for {@link Validate#dtfEntry(java.lang.String)}.
     * 
     * Tests the dtfEntry method in the Validate class, covering execution 
     * where the daily transaction entry matches refund, and returns true.
     */
    @Test
    public void testDtfEntry2()
    {
        assertTrue(Validate.dtfEntry("05_buyer___________seller__________000005.00"));
    }
    
    /**
     * Test method for {@link Validate#dtfEntry(java.lang.String)}.
     * 
     * Tests the dtfEntry method in the Validate class, covering execution where 
     * the daily transaction entry matches buy or sell, and returns true.
     */
    @Test
    public void testDtfEntry3()
    {
        assertTrue(Validate.dtfEntry("03_The_Goosebumps______administrator___023_012.00"));
    }
    
    /**
     * Test method for {@link Validate#dtfEntry(java.lang.String)}.
     * 
     * Tests the dtfEntry method in the Validate class, covering execution 
     * where the daily transaction entry matches none of the specified 
     * transactions, and returns false.
     */
    @Test
    public void testDtfEntry4()
    {
        /* An invalid dtf entry, such as an entry from an ATF */
        assertFalse(Validate.dtfEntry("The_Goosebumps______administrator___046_012.00"));
    }
}
