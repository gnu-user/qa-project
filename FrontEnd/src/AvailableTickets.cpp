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
#include "../include/AvailableTickets.hpp"
#include "../include/Validate.hpp"
#include "Poco/File.h"
#include "Poco/Path.h"
#include "Poco/String.h"
#include "Poco/FileStream.h"
#include "Poco/RegularExpression.h"
#include "Poco/NumberParser.h"
#include <iostream>

using namespace std;
using Poco::File;
using Poco::Path;
using Poco::replace;
using Poco::FileInputStream;
using Poco::RegularExpression;
using Poco::NumberParser;

AvailableTickets::AvailableTickets()
{

}

AvailableTickets::AvailableTickets(string atf_file)
{
    File file = File(atf_file);

    if (file.exists())
    {
        this->atf_file = atf_file;

        /* Parse the available tickets file */
        this->parse();
    }
    else
    {
        throw Exception(ATF_NOT_FOUND);
    }
}

bool AvailableTickets::has_event(string event)
{
    for (vector<Ticket>::iterator it = tickets.begin(); it != tickets.end(); ++it)
    {
        if (it->get_event().compare(event) == 0)
        {
            return true;
        }
    }

    return false;
}

bool AvailableTickets::has_seller(string username)
{
    for (vector<Ticket>::iterator it = tickets.begin(); it != tickets.end(); ++it)
    {
        if (it->get_seller().compare(username) == 0)
        {
            return true;
        }
    }

    return false;
}

Ticket AvailableTickets::get_ticket(string event, string username)
{
    for (vector<Ticket>::iterator it = tickets.begin(); it != tickets.end(); ++it)
    {
        if (   it->get_event().compare(event) == 0
            && it->get_seller().compare(username) == 0)
        {
            return *it;
        }
    }

    throw Exception(TICKET_NOT_FOUND);
}

void AvailableTickets::display_tickets()
{
    for (vector<Ticket>::iterator it = tickets.begin(); it != tickets.end(); ++it)
    {
        cout << it->get_event()  << " " << it->get_seller() << " "
             << it->get_volume() << " " << it->get_price() << endl;
    }
}

void AvailableTickets::parse()
{
    /* Read the contents of the current user accounts and store each user */
    FileInputStream fis(atf_file);

    if (fis.good())
    {
        string read;
        RegularExpression re("^(.{1,19}?)_+_([A-Za-z0-9_]{1,15}?)_+([0-9]{3})_([0-9]{3}\\.[0-9]{2})$");
        RegularExpression re_end("END_{33}0{3}_0{3}\\.0{2}");
        RegularExpression::MatchVec matches;

        while (getline(fis, read))
        {
            /* Stop if END of file reached */
            if (re_end.match(read))
            {
                return;
            }

            /* Add each ticket found to the list of tickets */
            if (Validate::atf_entry(read))
            {
                re.match(read, 0, matches);

                /* Replace each _ with a space character for event title */
                string event = replace(read.substr(matches[1].offset, matches[1].length), "_", " ");

                string seller = read.substr(matches[2].offset, matches[2].length);
                int volume = NumberParser::parse((read.substr(matches[3].offset, matches[3].length)));
                double price = NumberParser::parseFloat(read.substr(matches[4].offset, matches[4].length));

                /* Add the ticket to the list of tickets */
                this->tickets.push_back(Ticket(event, seller, volume, price));
            }
            /* Corrupted entry in file */
            else
            {
                throw Exception(CORRUPT_ATF);
            }
        }
    }

    /* No END of file identifier found or file corrupted */
    throw Exception(CORRUPT_ATF);
}
