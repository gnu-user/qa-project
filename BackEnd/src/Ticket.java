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
public class Ticket
{
    private String event;
    private String seller;
    private Integer volume;
    private Double price;


    /**
     * 
     * @param event
     * @param volume
     * @param price
     */
    public Ticket(String event, String seller, Integer volume, Double price)
    {
        this.event = event;
        this.seller = seller;
        this.volume = volume;
        this.price = price;
    }

    /**
     * @return the event
     */
    public String getEvent()
    {
        return event;
    }

    /**
     * @return the seller
     */
    public String getSeller()
    {
        return seller;
    }
    
    public Integer getVolume()
    {
        return this.volume;
    }

    /**
     * 
     * @param volume
     */
    public void setVolume(Integer volume)
    {
        this.volume = volume;
    }

    public Double getPrice()
    {
        return this.price;
    }

    /**
     * 
     * @param price
     */
    public void setPrice(Double price)
    {
        this.price = price;
    }

}