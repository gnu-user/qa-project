class Transaction
{

protected:
    User* user;
    string code;
    string transaction;
   
    virtual void save_transaction() = 0;

public:
    string get_transaction();
};
