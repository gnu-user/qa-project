#ifndef AVAILABLETICKETS_HPP_
#define AVAILABLETICKETS_HPP_

#include "Ticket.hpp"
#include "Exception.hpp"
#include <string>
#include <vector>

using namespace std;

class AvailableTickets
{

private:
    vector<Ticket> tickets;
    string atf_file;

public:
    AvailableTickets(string atf_file);
   
    bool has_event(string event);
   
    bool has_seller(string username);
   
    Ticket get_ticket(string event, string username);

private:
    void parse();
};
#endif /* AVAILABLETICKETS_HPP_ */
