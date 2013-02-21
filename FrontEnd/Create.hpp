class Create : Transaction
{

private:
    std::string types[];
    std::string new_username;

public:
    Create(User current_user);
   
    void process_username(std::string input, CurrentUserAccounts user_account);
   
    void process_type(std::string input);
};
