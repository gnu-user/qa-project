class Buy : Transaction
{

private:
    Ticket* ticket;
    std::string title;
    int volume;
    std::string seller;

public:
    Buy(User current_user);
   
    void process_title(std::string input, AvailableTickets available_tickets);
   
    void process_volume(std::string input);
   
    void process_seller(std::string input, AvailableTickets available_tickets);
   
    void process_confirmation(std::string input);
};
