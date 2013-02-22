class Transaction
{

protected:
    User* user;
    std::string code;
    std::string transaction;
   
    virtual void save_transaction() = 0;

public:
    std::string get_transaction();
};
