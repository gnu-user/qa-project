public class Refund implements Transaction
{
    private String buyer;
    private String seller;
    private Double credit;


    /**
     * 
     * @param buyer
     * @param seller
     * @param credit
     */
    public Refund(String buyer, String seller, Double credit)
    {
        throw new UnsupportedOperationException();
    }

    public void execute()
    {
        throw new UnsupportedOperationException();
    }

}