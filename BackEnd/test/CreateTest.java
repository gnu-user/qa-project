import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;


public class CreateTest
{
    /* Objects used for executing the create test suite */
    private AvailableTickets availableTickets;
    private CurrentUserAccounts currentAccounts;
 
    /* Parameters used for the tests */
    private static final String username = "newuser";
    private static final String existingUsername = "administrator";
    private static final String type = "BS";
    private static final Double credit = 0.0;
    private static final String transaction = "01_newuser_________BS_000000.00";
    
    /**
     * Test setup, create the objects needed to execute the tests
     * 
     * @throws Exception
     */
    @Before
    public void setUp() throws Exception
    {
        availableTickets = new AvailableTickets("CreateTest.atf");
        currentAccounts = new CurrentUserAccounts("CreateTest.cua");
    }

    /**
     * Test method for {@link Create#execute()}.
     * 
     * Test the execute method in the Create class, by providing a valid username, 
     * resulting in the true execution branch (the method being executed to satisfy 
     * this branch is tested elsewhere). Verify that the User object is instantiated, 
     * and the object is added to the cua collection.
     * 
     * @throws FailedConstraint 
     */
    @Test
    public void testExecute1() throws FailedConstraint
    {
        /* Create an instance of a create transaction */
        Create create = new Create(username, type, credit, transaction);
        create.execute(currentAccounts, availableTickets);
       
        /* Verify the create statement was executed */
        assertTrue(currentAccounts.hasUser(username));
    }

    /**
     * Test method for {@link Create#execute()}.
     * 
     * Test the execute method in the Create class, by providing an invalid username, 
     * resulting in the false execution branch (the method being executed to satisfy 
     * this branch is tested elsewhere). Verify that an exception is thrown for a 
     * Failed Constraint.
     * 
     * @throws FailedConstraint 
     */
    @Test(expected=FailedConstraint.class)
    public void testExecute2() throws FailedConstraint
    {
        /* Create an instance of a create transaction */
        Create create = new Create(existingUsername, type, credit, transaction);
        create.execute(currentAccounts, availableTickets);
    }
    
    /**
     * Test method for {@link Create#getTransaction()}.
     * 
     * Tests the getTransaction method in the Create class, by executing the method. 
     * This method is a simple accessor method with only one return call.
     * @throws FailedConstraint 
     */
    @Test
    public void testGetTransaction() throws FailedConstraint
    {
        /* Verify the transaction returned is correct */
        Create create = new Create(username, type, credit, transaction);
        assertEquals(create.getTransaction(), transaction);
    }
}
