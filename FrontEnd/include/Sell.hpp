class Sell : Transaction
{

private:
    Ticket* ticket;
    std::string title;
    double price;
    int volume;

public:
    Sell(User current_user);
   
    void process_title(std::string input);
   
    void process_price(std::string input);
   
    void process_volume(std::string input);
};
