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
public class Refund implements Transaction
{
    private String buyer;
    private String seller;
    private Double credit;
    private String transaction;


    /**
     * 
     * @param buyer
     * @param seller
     * @param credit
     */
    public Refund(String buyer, String seller, Double credit, String transaction)
    {
        this.buyer = buyer;
        this.seller = seller;
        this.credit = credit;
        this.transaction = transaction;
    }

    public void execute(CurrentUserAccounts cua, AvailableTickets atf) throws FailedConstraint
    {
    	if (cua.hasUser(buyer) && cua.hasUser(seller))
    	{
    		if (cua.getUser(buyer).getCredit() + credit < 999999.99)
    		{
    			if (cua.getUser(seller).getCredit() - credit > 0.00)
    			{
    				cua.getUser(buyer).setCredit(cua.getUser(buyer).getCredit() + credit);
    				cua.getUser(seller).setCredit(cua.getUser(seller).getCredit() - credit);
    			}
    			else
    			{
    				throw new FailedConstraint(ExceptionCodes.USER_CREDIT_NEGATIVE, transaction);
    			}
    		}
    		else 
    		{
    			throw new FailedConstraint(ExceptionCodes.USER_CREDIT_OVERFLOW, transaction);
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