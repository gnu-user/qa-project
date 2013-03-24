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
    public Ticket(String event, Integer volume, Double price)
    {
        throw new UnsupportedOperationException();
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