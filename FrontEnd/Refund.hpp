class Refund : Transaction
{

private:
    std::string buyer;
    std::string seller;
    double credit;

public:
    Refund(User current_user);
   
    void process_buyer(std::string input, CurrentUserAccounts user_accounts);
   
    void process_seller(std::string input, AvailableTickets available_tickets);
   
    void process_credit(std::string input);
};
