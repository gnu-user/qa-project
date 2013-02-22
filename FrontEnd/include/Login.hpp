class Login : Transaction
{


public:
    Login(User current_user);
   
    User* process_username(std::string input, CurrentUserAccounts user_account);
};
