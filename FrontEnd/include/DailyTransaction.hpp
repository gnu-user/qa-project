class DailyTransaction
{

private:
    std::vector<Transaction> transactions;
    std::string dtf_file;

public:
    DailyTransaction(std::string dtf_file);
   
    void save(Transaction transaction);
   
    void write();
};
