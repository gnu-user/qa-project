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
public class Sell implements Transaction
{
    private String event;
    private String seller;
    private Integer volume;
    private Double price;
    private String transaction;


    /**
     * 
     * @param event
     * @param seller
     * @param volume
     * @param price
     */
    public Sell(String event, String seller, Integer volume, Double price, String transaction)
    {
        this.event = event;
        this.seller = seller;
        this.volume = volume;
        this.price = price;
        this.transaction = transaction;
    }

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

        throw new UnsupportedOperationException();
    }

	public String getTransaction() {
		return transaction;
	}

}