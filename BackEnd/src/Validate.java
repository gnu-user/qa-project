package src;
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
public abstract class Validate
{
    /**
     * Validates available tickets file entries, and
     * determines if they conform to the correct format and constraints.
     *
     * @param entry An entry in the available tickets file.
     * @return Returns true if the entry is valid, false if not.
     */
    public static boolean atfEntry(String entry)
    {
    	return entry.matches("^.{19}_[A-Za-z0-9_]{15}_[0-9]{3}_[0-9]{3}\\.[0-9]{2}$");
    }

    /**
     * Validates current user accounts file entries, and
     * determines if they conform to the correct format and constraints.
     * 
     * @param entry An entry in the current user accounts file.
     * @return Returns true if the entry is valid, false if not.
     */
    public static boolean cuaEntry(String entry)
    {
    	return entry.matches("^[A-Za-z0-9_]{15}_(AA|FS|BS|SS)_[0-9]{6}\\.[0-9]{2}$");
    }

    /**
     * Validates daily transaction file entries and determines if they
     * conforms to the correct format and constraints.
     * 
     * @param entry An entry in the daily transaction file.
     * @return Returns true if the entry is valid, false if not.
     */
    public static boolean dtfEntry(String entry)
    {
        /* Daily transaction entry matches logout, create, delete, or addcredit */
        if (entry.matches("^(00|01|02|06)_[A-Za-z0-9_]{15}_(AA|FS|BS|SS)_[0-9]{6}\\.[0-9]{2}$"))
        {
            return true;
        }
        /* Daily transaction entry matches refund */
        else if (entry.matches("^05_[A-Za-z0-9_]{15}_[A-Za-z0-9_]{15}_[0-9]{6}\\.[0-9]{2}$"))
        {
            return true;
        }
        /* Daily transaction entry matches buy or sell */
        else if (entry.matches("^(03|04)_.{19}_[A-Za-z0-9_]{15}_[0-9]{3}_[0-9]{3}\\.[0-9]{2}$"))
        {
            return true;
        }
        
        return false;
    }
}