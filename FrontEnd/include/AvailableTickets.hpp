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
 * Used for storing the Available Tickets File, and provides functions for
 * interacting with it.
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
     * AvailableTickets The constructor for the class, requires the location of
     * the available tickets file on disk.
     * @param atf_file The path to the available tickets file on disk.
     */
    AvailableTickets(string atf_file);
   
    /**
     * has_event Determines whether an event exists within the available
     * tickets file.
     * @param event Specifies which event to check for.
     * @return Returns true if the event exists, false if it does not.
     */
    bool has_event(string event);
   
    /**
     * has_seller Determines whether a valid seller exists for an event.
     * @param username Specifies which username to check for.
     * @return Returns true if the seller exists, false if it does not.
     */
    bool has_seller(string username);
   
    /**
     * get_ticket Gets the tickets for a specific event, from a
     * specified seller.
     * @param event Specifies which event to obtain tickets for.
     * @param username Specifies which username to use as the seller.
     * @return Returns true if the tickets are available for the given
     * seller and event, false if they are not.
     */
    Ticket get_ticket(string event, string username);

    /**
     * display_tickets Displays the tickets which are available.
     */
    void display_tickets();

private:
    /**
     * parse Takes in the available ticket file, and parses it. The output is stored
     * within the AvailableTickets object.
     */
    void parse();
};
#endif /* AVAILABLETICKETS_HPP_ */
