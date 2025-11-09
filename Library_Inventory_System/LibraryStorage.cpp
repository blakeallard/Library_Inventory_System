#include "LibraryStorage.h"
#include "Shelf.h"
#include "Compartment.h"


LibraryStorage::LibraryStorage()
{

}

// in order to add items to shelves, 
// must know which shelf index and compartment index
void LibraryStorage::AddItem(int shelfIndex, int compartmentIndex, const Item& item)
{
    if (shelfIndex < 0 || shelfIndex >= shelves.size())
    {
        throw out_of_range("Shelf index out of range");
    }
    
    if (compartmentIndex < 0 || compartmentIndex >= NUM_COMPARTS)
    {
        throw out_of_range("Compartment index out of range");
    }

    if (shelves[shelfIndex][compartmentIndex].IsEmpty())
    {
        shelves[shelfIndex][compartmentIndex].AddItem(item);
    }
    else
    {
        cout << "Compartment is already occupied.\n";
    }
}

void LibraryStorage::CheckInItem()
{

}

void LibraryStorage::CheckOutItem()
{

}

void LibraryStorage::SwapItems()
{

}

void LibraryStorage::PrintStorage()
{

}

void LibraryStorage::PrintCheckedOutItems()
{

}

Shelf& LibraryStorage::operator[](int index)
{
    if (index < 0 || index >= shelves.size())
    {
        throw out_of_range("Shelf index out of range");
    }
    return shelves[index];
}
