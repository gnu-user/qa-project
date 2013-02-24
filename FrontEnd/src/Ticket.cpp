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
    return this->event;
}

string Ticket::get_seller()
{
    return this->seller;
}

int Ticket::get_volume()
{
    return this->volume;
}

double Ticket::get_price()
{
    return this->price;
}
