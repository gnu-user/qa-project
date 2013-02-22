class CurrentUserAccounts
{

private:
    std::vector<User> users;
    std::string cua_file;

public:
    CurrentUserAccounts(std::string cua_file);
   
    bool has_user(std::string username);
   
    User get_user(std::string username);

private:
    void parse();
};
