class Validate
{


public:
    bool username(std::string username);
   
    bool event(std::string event);
   
    bool cua_entry(std::string entry);
   
    bool atf_entry(std::string entry);
   
    bool dollars(std::string amount, double& converted);
   
    bool volume(std::string amount, int& converted);
};
