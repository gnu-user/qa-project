#include "../include/DailyTransaction.hpp"
#include <iostream>

using namespace std;

DailyTransaction::DailyTransaction()
{

}

DailyTransaction::DailyTransaction(string dtf_file)
{
    this->dtf_file = dtf_file;
}

void DailyTransaction::save(Transaction transaction)
{
    this->transactions.push_back(transaction);
}

void DailyTransaction::write()
{
    for (vector<Transaction>::iterator it = this->transactions.begin(); it != this->transactions.end(); ++it)
    {
        cout << it->get_transaction() << endl;
    }
}
