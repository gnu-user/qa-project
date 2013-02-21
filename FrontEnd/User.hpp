class User
{

private:
    std::string username;
    std::string type;
    double credit;
    std::vector<std::string> permissions;

public:
    User(std::string username, std::string type, double credit);
   
    std::string get_username();
   
    std::string get_type();
   
    double get_credit();
   
    bool has_permissions(std::string transaction);
};
