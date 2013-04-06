import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

/**
 * 
 */

/**
 * @author jon
 *
 */
public class TicketTest
{
    /* Ticket object user for the tests */
    private Ticket ticket;
    
    /* Parameters for the Ticket object and used for tests */
    private static final String event = "The Godfather II";
    private static final String seller = "seller";
    private static final Integer volume = 50;
    private static final Integer newVolume = 25;
    private static final Double price = 10.00;
    private static final Double newPrice = 5.00;
    
    /**
     * Setup the tests by creating the Ticket object 
     * 
     * @throws java.lang.Exception
     */
    @Before
    public void setUp() throws Exception
    {
        ticket = new Ticket(event, seller, volume, price);
    }

    /**
     * Test method for {@link Ticket#getEvent()}.
     * 
     * Tests the getEvent method in the Ticket class, by executing the method. 
     * This method is a simple accessor method with only one return call.
     */
    @Test
    public void testGetEvent()
    {
        assertEquals(ticket.getEvent(), event);
    }

    /**
     * Test method for {@link Ticket#getSeller()}.
     * 
     * Tests the getSeller method in the Ticket class, by executing the method. 
     * This method is a simple accessor method with only one return call.
     */
    @Test
    public void testGetSeller()
    {
        assertEquals(ticket.getSeller(), seller);
    }

    /**
     * Test method for {@link Ticket#getVolume()}.
     * 
     * Tests the getVolume method in the Ticket class, by executing the method. 
     * This method is a simple accessor method with only one return call. 
     */
    @Test
    public void testGetVolume()
    {
        assertEquals(ticket.getVolume(), volume);
    }

    /**
     * Test method for {@link Ticket#setVolume(java.lang.Integer)}.
     * 
     * Tests the setVolume method in the Ticket class, by executing the method 
     * using a random value. This method is a simple mutator method which only 
     * sets the value of the volume attribute internally.
     */
    @Test
    public void testSetVolume()
    {
        ticket.setVolume(newVolume);
        assertEquals(ticket.getVolume(), newVolume);
    }

    /**
     * Test method for {@link Ticket#getPrice()}.
     * 
     * Tests the getPrice method in the Ticket class, by executing the method. 
     * This method is a simple accessor method with only one return call.
     */
    @Test
    public void testGetPrice()
    {
        assertEquals(ticket.getPrice(), price);
    }

    /**
     * Test method for {@link Ticket#setPrice(java.lang.Double)}.
     * 
     * Tests the setPrice method in the Ticket class, by executing the method 
     * using a random value. This method is a simple mutator method which only 
     * sets the value of the volume attribute internally.
     */
    @Test
    public void testSetPrice()
    {
        ticket.setPrice(newPrice);
        assertEquals(ticket.getPrice(), newPrice);
    }

}
