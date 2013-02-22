class AvailableTickets
{

private:
    vector<Tickets> tickets;
    string atf_file;

public:
    AvailableTickets(string atf_file);
   
    bool has_event(string event);
   
    bool has_seller(string username);
   
    Ticket get_ticket(string event, string username);

private:
    void parse();
};
