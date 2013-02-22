#ifndef DAILYTRANSACTION_HPP_
#define DAILYTRANSACTION_HPP_

#include "Transaction.hpp"
#include <string>
#include <vector>

using namespace std;

class DailyTransaction
{

private:
    vector<Transaction> transactions;
    string dtf_file;

public:
    DailyTransaction(string dtf_file);
   
    void save(Transaction transaction);
   
    void write();
};
#endif /* DAILYTRANSACTION_HPP_ */