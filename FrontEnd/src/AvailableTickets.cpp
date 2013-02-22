#include "../include/AvailableTickets.hpp"
#include "Poco/File.h"
#include "Poco/Path.h"

using Poco::File;
using Poco::Path;

AvailableTickets::AvailableTickets(string atf_file)
{
	File file = File(atf_file);

	if (file.exists())
	{
		this->atf_file = atf_file;
	}
	else
	{
		throw Exception(ATF_NOT_FOUND);
	}
}

bool AvailableTickets::has_event(string event)
{
    throw "Not yet implemented";
}

bool AvailableTickets::has_seller(string username)
{
    throw "Not yet implemented";
}

Ticket AvailableTickets::get_ticket(string event, string username)
{
    throw "Not yet implemented";
}

void AvailableTickets::parse()
{
    throw "Not yet implemented";
}
