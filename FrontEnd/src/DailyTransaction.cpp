#include "../include/DailyTransaction.hpp"
#include "Poco/FileStream.h"
#include <iostream>

using Poco::FileOutputStream;
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
    FileOutputStream fos(dtf_file);

    if (fos.good())
    {
        for (vector<Transaction>::iterator it = transactions.begin(); it != transactions.end(); ++it)
        {
            fos << it->get_transaction() << endl;
        }
    }
    else
    {
        throw Exception(DTF_WRITE_ERROR);
    }
}
