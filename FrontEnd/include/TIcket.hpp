class TIcket
{

private:
    std::string event;
    std::string seller;
    int volume;
    double price;

public:
    std::string get_event();
   
    std::string get_seller();
   
    int get_volume();
   
    double get_price();
};
