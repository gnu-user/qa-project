/**
 * Swift Ticket -- Front End Interface
 *
 * Copyright (C) 2013, Jonathan Gillett, Daniel Smullen, and Rayan Alfaheid
 * All rights reserved.
 *
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
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
