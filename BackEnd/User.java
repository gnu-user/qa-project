public class User
{
    private String username;
    private String type;
    private Double credit;
    private Double creditAdded;


    /**
     * 
     * @param username
     * @param type
     * @param credit
     */
    public User(String username, String type, Double credit)
    {
        throw new UnsupportedOperationException();
    }

    public String getUsername()
    {
        return this.username;
    }

    public String getType()
    {
        return this.type;
    }

    public Double getCredit()
    {
        return this.credit;
    }

    /**
     * 
     * @param credit
     */
    public void setCredit(Double credit)
    {
        this.credit = credit;
    }

    public Double getCreditAdded()
    {
        return this.creditAdded;
    }

}