#include "Compartment.h"
#include "Item.h"
using std::cout, std::endl, std::make_unique;


Compartment::Compartment()
{
    item         = nullptr;
    checkedOutBy = "";
    dueDate      = "";
}

void Compartment::AddItem(unique_ptr<Item> newItem)
{
    if (item != nullptr)
    {
        cout << "Error: Compartment already has an item" << endl;
        return;
    }

    item = std::move(newItem);

}

unique_ptr<Item> Compartment::RemoveItem()
{
    if (item == nullptr)
    {
        cout << "Error: Compartment is already empty" << endl;
        return nullptr;
    }

    if (!this->checkedOutBy.empty())
    {
        cout << "Error: Cannot remove item while it is checked out" << endl;
        return nullptr;
    }

    this->checkedOutBy = "";
    this->dueDate      = "";
    return std::move(item);
}

const Item* Compartment::GetItem() const
{
    return item.get();
}

string Compartment::getCheckedOutBy() const 
{ 
    return checkedOutBy; 
}

string Compartment::getDueDate() const 
{
    return dueDate;
}

bool Compartment::CheckIn()
{
    if (item == nullptr)
    {
        cout << "Error: Compartment is empty\n";
        return false;
    }

    if (this->checkedOutBy.empty())
    {
        cout << "Error: Item is not checked out\n";
        return false;
    }

    this->checkedOutBy = "";
    this->dueDate      = "";
    return true;
}

bool Compartment::CheckOut(const string& checkedOutBy, const string& dueDate)
{
    if (item == nullptr)
    {
        cout << "Error: Compartment is empty\n";
        return false;
    }

    if (!this->checkedOutBy.empty())
    {
        cout << "Error: Item is already checked out\n";
        return false;
    }

    this->checkedOutBy = checkedOutBy;
    this->dueDate      = dueDate;

    cout << "\nThank You " << checkedOutBy << "!\n";
    cout << "You have successfully checked out the " 
         << item->GetType()  << " titled \"" 
         << item->GetTitle() << "\"\n\n"
         << "We'll see you back on " << dueDate << "!\n\n";
         
    return true;
}

bool Compartment::IsCheckedOut() const
{
    return !checkedOutBy.empty();
}

bool Compartment::IsEmpty() const
{
    return item == nullptr;
}

void Compartment::swap(Compartment& otherItem) 
{
    std::swap(this->item, otherItem.item);
    std::swap(this->checkedOutBy, otherItem.checkedOutBy);
    std::swap(this->dueDate, otherItem.dueDate);
}

Compartment::~Compartment() = default;