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
import org.junit.runner.RunWith;
import org.junit.runners.Suite;
import org.junit.runners.Suite.SuiteClasses;


@RunWith(Suite.class)
@SuiteClasses({
    AddCreditTest.class,
    AvailableTicketsTest.class,
    BackEndTest.class,
    BuyTest.class,
    CreateTest.class,
    CurrentUserAccountsTest.class, 
    DailyTransactionsTest.class, 
    DeleteTest.class,
    ExceptionCodesTest.class, 
    FailedConstraintTest.class, 
    FatalErrorTest.class,
    LogoutTest.class,
    RefundTest.class,
    SellTest.class,
    TicketTest.class, 
    UserTest.class, 
    ValidateTest.class
})
public class AllTests
{

}