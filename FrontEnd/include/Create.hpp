class Create : Transaction
{

private:
    string types[];
    string new_username;

public:
    Create(User current_user);
   
    void process_username(string input, CurrentUserAccounts user_account);
   
    void process_type(string input);
};
