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
#include "../include/Transaction.hpp"
#include "Poco/String.h"
#include "Poco/NumberFormatter.h"

using Poco::replace;
using Poco::NumberFormatter;

string Transaction::get_transaction()
{
    return this->transaction;
}

/**
 * Formats the transaction as follows:
 *
 * XX_UUUUUUUUUUUUUUU_TT_CCCCCCCCC
 *
 */
string Transaction::format(string code, string username, string type, double credit)
{
    string transaction;

    /* Format the XX_ */
    transaction = code + "_";

    /* Format the UUUUUUUUUUUUUUU_ */
    transaction += string(16, '_').replace(0, username.length(), username);

    /* Format the TT_ */
    transaction += type + "_";

    /* Format the credit */
    transaction += replace(NumberFormatter::format(credit, 9, 2), " ", "0");

    return transaction;
}

/**
 * This is only used to format a refund transaction, it
 * formats the transaction as follows:
 *
 * XX_UUUUUUUUUUUUUUU_SSSSSSSSSSSSSSS_CCCCCCCCC
 *
 */
string Transaction::format(string code, string username, string type, string seller, double refund)
{
    string transaction;

    /* Format the XX_ */
    transaction = code + "_";

    /* Format the UUUUUUUUUUUUUUU_ */
    transaction += string(16, '_').replace(0, username.length(), username);

    /* Format the SSSSSSSSSSSSSSS_ */
    transaction += string(16, '_').replace(0, seller.length(), seller);

    /* Format the refund amount */
    transaction += replace(NumberFormatter::format(refund, 9, 2), " ", "0");

    return transaction;
}

/**
 * This is used to format buy and sell transactions, it formats
 * the transaction as follows:
 *
 * XX_EEEEEEEEEEEEEEEEEEE_SSSSSSSSSSSSSSS_TTT_PPPPPP
 *
 */
string Transaction::format(string code, string event, string seller, int volume, double price)
{
    string transaction;

    /* Format the XX_ */
    transaction = code + "_";

    /* Format the EEEEEEEEEEEEEEEEEEE_ */
    transaction += replace((string(20, '_').replace(0, event.length(), event)), " ", "_");

    /* Format the SSSSSSSSSSSSSSS_ */
    transaction += string(16, '_').replace(0, seller.length(), seller);

    /* Format the TTT_ */
    transaction += NumberFormatter::format0(volume, 3) + "_";

    /* Format the ticket price */
    transaction += replace(NumberFormatter::format(price, 6, 2), " ", "0");

    return transaction;
}

void Transaction::save_transaction()
{
    throw Exception(NOT_YET_IMPLEMENTED);
}
