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
