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
public class AddCredit implements Transaction
{
    private String username;
    private String type;
    private Double credit;
    private String transaction;


    /**
     * 
     * @param username
     * @param type
     * @param credit
     */
    public AddCredit(String username, String type, Double credit, String transaction)
    {
        this.username = username;
        this.type = type;
        this.credit = credit;
        this.transaction = transaction;
    }

    public void execute(CurrentUserAccounts cua, AvailableTickets atf) throws FailedConstraint
    {
        if (cua.hasUser(username))
        {
        	Double temp_credit;
        	temp_credit = cua.getUser(username).getCredit();
        	if (temp_credit + credit > 999999.99)
        	{
        		throw new FailedConstraint(ExceptionCodes.USER_CREDIT_OVERFLOW, transaction);
        	}
        	else
        	{
				if (cua.getUser(username).getCreditAdded() + credit > 1000)
				{
					throw new FailedConstraint(ExceptionCodes.USER_CREDIT_SESSION_OVERFLOW, transaction);
				}
				else
				{
					cua.getUser(username).setCredit(credit + temp_credit);
					cua.getUser(username).setCreditAdded(cua.getUser(username).getCreditAdded() + credit);
				}
        	}
        }
        else
        {
        	throw new FailedConstraint(ExceptionCodes.UNKNOWN_USER, transaction);
        }
    }

	public String getTransaction() {
		return transaction;
	}

}