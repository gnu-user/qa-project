class AddCredit : Transaction
{

private:
    std::string username;
    double credit;

public:
    AddCredit(User current_user);
   
    void process_username(std::string input, CurrentUserAccounts user_accounts);
   
    void process_credit(std::string input);
};
