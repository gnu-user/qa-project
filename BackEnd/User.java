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
public class User
{
    private String username;
    private String type;
    private Double credit;
    private Double creditAdded;


    /**
     * 
     * @param username
     * @param type
     * @param credit
     */
    public User(String username, String type, Double credit)
    {
        this.username = username;
        this.type = type;
        this.credit = credit;
    }

    public String getUsername()
    {
        return this.username;
    }

    public String getType()
    {
        return this.type;
    }

    public Double getCredit()
    {
        return this.credit;
    }

    /**
     * 
     * @param credit
     */
    public void setCredit(Double credit)
    {
        this.credit = credit;
    }

    public void setCreditAdded(Double creditAdded)
    {
        this.creditAdded = creditAdded;
    }
    
    public Double getCreditAdded()
    {
        return this.creditAdded;
    }

}