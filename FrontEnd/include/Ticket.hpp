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
    string get_event();
   
    string get_seller();
   
    int get_volume();
   
    double get_price();
};
