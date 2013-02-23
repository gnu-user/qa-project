#ifndef TICKET_HPP_
#define TICKET_HPP_

#include "Exception.hpp"
#include <string>

using namespace std;

class Ticket
{

private:
    string event;
    string seller;
    int volume;
    double price;

public:
    Ticket(string event, string seller, int volume, double price);

    string get_event();
   
    string get_seller();
   
    int get_volume();
   
    double get_price();
};
#endif /* TICKET_HPP_ */
