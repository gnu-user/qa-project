#include "../include/Ticket.hpp"

Ticket::Ticket(string event, string seller, int volume, double price)
{
    this->event = event;
    this->seller = seller;
    this->volume = volume;
    this->price = price;
}

string Ticket::get_event()
{
    return event;
}

string Ticket::get_seller()
{
    return seller;
}

int Ticket::get_volume()
{
    return volume;
}

double Ticket::get_price()
{
    return price;
}
