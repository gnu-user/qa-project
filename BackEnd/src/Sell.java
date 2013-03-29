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
 * Sell Provides methods and attributes for processing the sell
 * transaction.
 * 
 * @author Jonathan Gillett
 * @author Daniel Smullen
 * @author Rayan Alfaheid
 */
public class Sell implements Transaction
{
    private String event;
    private String seller;
    private Integer volume;
    private Double price;
    private String transaction;

    /**
     * Constructor for the class. Accepts and populates class attributes with values passed in.
     * 
     * @param event String for the title of the event.
     * @param seller String for the username of the ticket seller.
     * @param volume Integer for the number of tickets being sold.
     * @param price Dollar value for the price per ticket.
     * @param transaction The transaction string for the sell transaction.
     */
    public Sell(String event, String seller, Integer volume, Double price, String transaction)
    {
        this.event = event;
        this.seller = seller;
        this.volume = volume;
        this.price = price;
        this.transaction = transaction;
    }

    /**
     * execute Performs the sell transaction. Adds the tickets specified to the seller's
     * available tickets, or updates the existing listings if the event already exists.
     * 
     * @param cua A reference to the CurrentUserAccounts object used by the back-end.
     * @param atf A reference to the AvailableTickets object used by the back-end.
     * 
     * @throws FailedConstraint Throws a failed constraint under the following circumstances:
     * 			<br>If the number of tickets being sold for an event exceeds 100.
     * 
     * @see Transaction#execute(CurrentUserAccounts, AvailableTickets)
     */
    public void execute(CurrentUserAccounts cua, AvailableTickets atf) throws FailedConstraint
    {
    	if (atf.hasTicket(event, seller))
    	{
    		if (atf.getTicket(event, seller).getVolume() + volume <= 100)
    		{
    			atf.getTicket(event, seller).setPrice(price);
    			atf.getTicket(event, seller).setVolume(atf.getTicket(event, seller).getVolume() + volume);
    		}
    		else
    		{
    			throw new FailedConstraint(ExceptionCodes.TICKET_VOLUME_OVERFLOW, transaction);
    		}
    	}
    	else
    	{
    		atf.addTicket(new Ticket(event, seller, volume, price));
    	}
    }

	/* (non-Javadoc)
	 * @see Transaction#getTransaction()
	 */
	public String getTransaction() {
		return transaction;
	}

}