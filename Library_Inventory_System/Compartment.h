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
    void AddItem();
    void RemoveItem();
    void CheckIn();
    void CheckOut();
    bool IsEmpty() const;
    bool isValidID(const string& id) const;
    ~Compartment();
};

#endif  // FILENAME_H
