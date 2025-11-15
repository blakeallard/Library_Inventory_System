#ifndef COMPARTMENT_H_
#define COMPARTMENT_H_
#include <iostream>
#include <string>
#include <memory>
#include <utility>
using std::string, std::make_unique, std::unique_ptr, std::endl;


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
    void AddItem(unique_ptr<Item> newItem);
    unique_ptr<Item> RemoveItem();
    const Item* GetItem() const;
    string getCheckedOutBy() const;
    string getDueDate() const;
    bool CheckIn();
    bool CheckOut(const string& checkedOutBy, const string& dueDate);
    bool IsCheckedOut() const;
    bool IsEmpty() const;
    void swap(Compartment& otherItem);
    ~Compartment();
};

#endif  // FILENAME_H
