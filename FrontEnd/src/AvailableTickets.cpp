#include "../include/AvailableTickets.hpp"
#include "Poco/File.h"
#include "Poco/Path.h"
#include "Poco/FileStream.h"
#include <cassert>
#include <iostream>	// TODO remove

using namespace std;
using Poco::File;
using Poco::Path;
using Poco::FileInputStream;

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
    throw Exception(NOT_YET_IMPLEMENTED);
}

bool AvailableTickets::has_seller(string username)
{
    throw Exception(NOT_YET_IMPLEMENTED);
}

Ticket AvailableTickets::get_ticket(string event, string username)
{
    throw Exception(NOT_YET_IMPLEMENTED);
}

void AvailableTickets::parse()
{
	/* Read the contents of the available tickets file and store each ticket */
	FileInputStream fis(this->atf_file);

	assert(fis.good());
	if (fis.good())
	{
		string read;

		while (getline(fis, read))
		{
			cout << read << endl;
		}
	}
	else
	{
		throw Exception(CORRUPT_ATF);
	}
}
