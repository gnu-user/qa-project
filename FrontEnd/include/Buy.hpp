class Buy : Transaction
{

private:
    Ticket* ticket;
    string title;
    int volume;
    string seller;

public:
    Buy(User current_user);
   
    void process_title(string input, AvailableTickets available_tickets);
   
    void process_volume(string input);
   
    void process_seller(string input, AvailableTickets available_tickets);
   
    void process_confirmation(string input);
};
