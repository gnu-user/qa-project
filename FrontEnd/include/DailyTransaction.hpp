#ifndef DAILYTRANSACTION_HPP_
#define DAILYTRANSACTION_HPP_

#include "Transaction.hpp"
#include "Exception.hpp"
#include <string>
#include <vector>

using namespace std;

/**
 * DailyTransaction Class
 *
 * Used for storing the daily transaction file and
 * provides functions for interacting with it.
 */
class DailyTransaction
{

private:
	/**
	 * transactions The list of transactions currently
	 * in the daily transaction file.
	 * dtf_file The path to the daily transaction file on disk.
	 */
    vector<Transaction> transactions;
    string dtf_file;

public:
    /* Default nullary constructor */
    DailyTransaction();

    /**
     * DailyTransaction The constructor for the class,
     * requires a reference to the daily transaction file path.
     * @param dtf_file The path to the daily transaction file
     * on disk.
     */
    DailyTransaction(string dtf_file);
   
    /**
     * save Saves a transaction to the daily transaction file.
     * @param transaction The transaction to be saved.
     */
    void save(Transaction transaction);
   
    /**
     * write Writes the daily transaction file out to disk.
     */
    void write();
};
#endif /* DAILYTRANSACTION_HPP_ */
