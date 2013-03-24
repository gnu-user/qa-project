public class Sell implements Transaction
{
    private String event;
    private String seller;
    private Integer volume;
    private Double price;


    /**
     * 
     * @param event
     * @param seller
     * @param volume
     * @param price
     */
    public Sell(String event, String seller, Integer volume, Double price)
    {
        throw new UnsupportedOperationException();
    }

    public void execute()
    {
        throw new UnsupportedOperationException();
    }

}