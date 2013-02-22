class Sell : Transaction
{

private:
    Ticket* ticket;
    string title;
    double price;
    int volume;

public:
    Sell(User current_user);
   
    void process_title(string input);
   
    void process_price(string input);
   
    void process_volume(string input);
};
