import org.junit.runner.RunWith;
import org.junit.runners.Suite;
import org.junit.runners.Suite.SuiteClasses;


@RunWith(Suite.class)
@SuiteClasses({TicketTest.class, UserTest.class, ValidateTest.class, CreateTest.class, 
    DeleteTest.class, BuyTest.class, ExceptionCodesTest.class, FailedConstraintTest.class, 
    FatalErrorTest.class, LogoutTest.class, SellTest.class})
public class AllTests
{

}
