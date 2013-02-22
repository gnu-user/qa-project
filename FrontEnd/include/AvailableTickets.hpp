class AvailableTickets
{

private:
    std::vector<Tickets> tickets;
    std::string atf_file;

public:
    AvailableTickets(std::string atf_file);
   
    bool has_event(std::string event);
   
    bool has_seller(std::string username);
   
    Ticket get_ticket(std::string event, std::string username);

private:
    void parse();
};
