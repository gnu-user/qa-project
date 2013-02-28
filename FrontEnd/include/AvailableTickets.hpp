#ifndef AVAILABLETICKETS_HPP_
#define AVAILABLETICKETS_HPP_

#include "Ticket.hpp"
#include "Exception.hpp"
#include <string>
#include <vector>

using namespace std;

/**
 * AvailableTickets Class
 *
 * Used for storing the Available Tickets File, and provides functions for interacting with it.
 */
class AvailableTickets
{

private:
	/**
	 * tickets Stores an array of the actual available tickets.
	 * atf_file Stores the path to the available tickets file on disk.
	 */
    vector<Ticket> tickets;
    string atf_file;

public:
    /* Default nullary constructor */
    AvailableTickets();

    /**
     * AvailableTickets The constructor for the class, requires the location of the available tickets file on disk.
     * @param atf_file The path to the available tickets file on disk.
     */
    AvailableTickets(string atf_file);
   
    /**
     * has_event
     * @param event
     * @return
     */
    bool has_event(string event);
   
    /**
     *
     * @param username
     * @return
     */
    bool has_seller(string username);
   
    /**
     *
     * @param event
     * @param username
     * @return
     */
    Ticket get_ticket(string event, string username);

    /**
     *
     */
    void display_tickets();

private:
    /**
     *
     */
    void parse();
};
#endif /* AVAILABLETICKETS_HPP_ */
