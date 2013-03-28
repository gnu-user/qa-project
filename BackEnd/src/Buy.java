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
 * Buy Provides methods and attributes for processing the buy transaction.
 * 
 * @author Jonathan Gillett
 * @author Daniel Smullen
 * @author Rayan Alfaheid
 */
public class Buy implements Transaction
{
    private String event;
    private String seller;
    private Integer volume;
    private Double price;
    private String transaction;


    /**
     * Constructor for the class. Accepts and populates class attributes with values passed in.
     * 
     * @param event String value for the name of the event to buy a ticket to.
     * @param seller String value for the ticket seller.
     * @param volume Integer value for the amount of tickets to buy.
     * @param price Dollar value for the price of the ticket sale.
     * @param transaction String containing the original transaction string from the 
     * daily transaction file.
     */
    public Buy(String event, String seller, Integer volume, Double price, String transaction)
    {
        this.event = event;
        this.seller = seller;
        this.volume = volume;
        this.price = price;
        this.transaction = transaction;
    }

    /* (non-Javadoc)
     * @see Transaction#execute(CurrentUserAccounts, AvailableTickets)
     */
    public void execute(CurrentUserAccounts cua, AvailableTickets atf)
    {
        //if (cua.hasUser(seller))
        //{
            
        //}
        //check if buyer exists (cua)
        //check if seller exists (cua)
        //check that the amount of money required is available (cua)
        //check if the money transfer will result in an overflow for the seller's balance (cua)
        //check if the volume of tickets are available (atf)
        //take the money out of the buyer (cua)
        //add the money to the seller (cua)
        //remove the tickets from the seller (atf)
    }

	/* (non-Javadoc)
	 * @see Transaction#getTransaction()
	 */
	public String getTransaction() {
		return transaction;
	}

}