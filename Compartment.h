#ifndef COMPARTMENT_H_
#define COMPARTMENT_H_
#include <string>
using std::string;


// Forward declaration
class Item;


class Compartment
{
private:
    Item* item;
    string checkedOutBy{};
    string dueDate{};


public:
    Compartment();
    ~Compartment();

};

#endif  // FILENAME_H
