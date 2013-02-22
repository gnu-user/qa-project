class Refund : Transaction
{

private:
    string buyer;
    string seller;
    double credit;

public:
    Refund(User current_user);
   
    void process_buyer(string input, CurrentUserAccounts user_accounts);
   
    void process_seller(string input, AvailableTickets available_tickets);
   
    void process_credit(string input);
};
