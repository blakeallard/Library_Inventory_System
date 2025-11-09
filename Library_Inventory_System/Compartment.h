#ifndef COMPARTMENT_H_
#define COMPARTMENT_H_
#include <string>
#include <memory>
using std::string, std::make_unique, std::unique_ptr;


// Forward declaration
class Item;


class Compartment
{
private:
    unique_ptr<Item> item;
    string checkedOutBy{};
    string dueDate{};

public:
    Compartment();
    void AddItem(const Item& newItem);
    void RemoveItem();
    void CheckOut();
    void CheckIn();
    bool IsEmpty();
    ~Compartment();

};

#endif  // FILENAME_H
