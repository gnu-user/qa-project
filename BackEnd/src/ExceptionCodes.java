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
 * ExceptionCodes An enumeration that maps various error/exception codes to
 * phrases and descriptions for easy reading.
 * 
 * @author Jonathan Gillett
 * @author Daniel Smullen
 * @author Rayan Alfaheid
 */
public enum ExceptionCodes
{
    /* Fatal error exception codes */
    ATF_NOT_FOUND("ATF_NOT_FOUND", "Available tickets file not found, check arguments provided."),
    CUA_NOT_FOUND("CUA_NOT_FOUND", "Current user accounts file not found, check arguments provided."),
    DTF_DIR_FOUND("DTF_DIR_FOUND", "Daily transactions directory not found, check arguments provided."),
    DTF_NOT_FOUND("DTF_NOT_FOUND", "Daily transactions file not found, check arguments provided."),
    CORRUPT_ATF("CORRUPT_ATF", "An error occurred reading the available tickets file, data corrupted."),
    CORRUPT_CUA("CORRUPT_CUA", "An error occurred reading the current user account file, data corrupted."),
    CORRUPT_DTF("CORRUPT_DTF", "An error occurred reading the daily transactions file, data corrupted."),
    ATF_WRITE_ERROR("ATF_WRITE_ERROR", "An error occurred writing the available tickets file."),
    CUA_WRITE_ERROR("CUA_WRITE_ERROR", "An error occurred writing the current user accounts file."),
    
    /* Failed constraints exception codes */
    INVALID_USER_EXISTS("INVALID_USER_EXISTS", "Invalid username, user already exists."),
    UNKNOWN_USER("UNKNOWN_USER", "Invalid username, username does not exist."),
    USER_CREDIT_NEGATIVE("USER_CREDIT_NEGATIVE", "Invalid credit amount, user credit cannot be less than 0.00."),
    USER_CREDIT_OVERFLOW("USER_CREDIT_OVERFLOW", "Invalid credit amount, user credit cannot exceed 999999.99."),
    USER_CREDIT_SESSION_OVERFLOW("USER_CREDIT_SESSION_OVERFLOW", "Invalid credit value, amount of credit added per session cannot exceed 1000.00."),
    TICKET_VOLUME_NEGATIVE("TICKET_VOLUME_NEGATIVE", "Invalid number of tickets, volume cannot be less than 0."),
    TICKET_VOLUME_OVERFLOW("TICKET_VOLUME_OVERFLOW", "Invalid number of tickets, volume cannot exceed 100."),
    
    NOT_YET_IMPLEMENTED("NOT_YET_IMPLEMENTED", "Not yet implemented");
    
    private String type;
    private String description;
    
    /**
     * Constructor for the enumeration. Made private in order to fulfil Java enumeration template.
     * 
     * @param type The enumeration phrase.
     * @param description The description of the exception code.
     */
    private ExceptionCodes(String type, String description)
    {
        this.type = type;
        this.description = description;
    }

    /**
     * getType Access method for the enumeration type.
     * 
     * @return Returns a string containing the type of error code.
     */
    public String getType()
    {
        return type;
    }

    /**
     * getDescription Access method for the enumeration description.
     * 
     * @return Returns a string containing the error description.
     */
    public String getDescription()
    {
        return description;
    }
    
    /**
     * toString Overrides the standard Object toString method, outputting the
     * error code in a human readable string. The format contains the type of error,
     * a colon, and the description.
     */
    @Override
    public String toString()
    {
        return type + ": " + description;
    }
}
