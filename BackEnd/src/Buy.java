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
    private String buyer;
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
    public Buy(String event, String buyer, String seller, Integer volume, Double price, String transaction)
    {
        this.event = event;
        this.buyer = buyer;
        this.seller = seller;
        this.volume = volume;
        this.price = price;
        this.transaction = transaction;
    }

    /* (non-Javadoc)
     * @see Transaction#execute(CurrentUserAccounts, AvailableTickets)
     */
    public void execute(CurrentUserAccounts cua, AvailableTickets atf) throws FailedConstraint
    {         
        /* Check that both the buyer and seller exist */
        if (! cua.hasUser(buyer) ||  ! cua.hasUser(seller))
        {
            throw new FailedConstraint(ExceptionCodes.UNKNOWN_USER, transaction);
        }
        
        /* Verify that the user has enough credit to purchase the tickets */
        if (cua.getUser(buyer).getCredit() - (volume * price) >= 0)
        {
            /* Verify the seller doesn't overflow credit from the purchase */
            if (cua.getUser(seller).getCredit() + (volume * price) <= 999999.99)
            {
                /* If the seller has enough tickets to sell, complete the transaction */
                if (atf.getTicket(event, seller).getVolume() >= volume)
                {
                    /* Transfer money from the buyer to the seller */
                    cua.getUser(seller).setCredit(cua.getUser(seller).getCredit() + (volume * price));
                    cua.getUser(buyer).setCredit(cua.getUser(buyer).getCredit() - (volume * price));
                    
                    /* Remove tickets sold from the sellers inventory */
                    atf.getTicket(event, seller).setVolume(atf.getTicket(event, seller).getVolume() - volume);
                }
                else
                {
                    throw new FailedConstraint(ExceptionCodes.TICKET_VOLUME_NEGATIVE, transaction);
                } 
            }
            else
            {
                throw new FailedConstraint(ExceptionCodes.USER_CREDIT_OVERFLOW, transaction);
            }
        }
        else
        {
            throw new FailedConstraint(ExceptionCodes.USER_CREDIT_NEGATIVE, transaction);
        }
    }

	/* (non-Javadoc)
	 * @see Transaction#getTransaction()
	 */
	public String getTransaction() {
		return transaction;
	}

}