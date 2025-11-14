#include "LibraryStorage.h"
#include "Shelf.h"
#include "Compartment.h"


LibraryStorage::LibraryStorage() 
{
    shelves.resize(NUM_SHELVES);
}

// in order to add items to shelves, 
// must know which shelf index and compartment index
bool LibraryStorage::AddItem(int shelfIndex, int compartmentIndex, unique_ptr<Item> item)
{
    if (shelfIndex < 0 || shelfIndex >= shelves.size())
    {
        throw out_of_range("Shelf index out of range");
    }
    
    if (compartmentIndex < 0 || compartmentIndex >= Shelf::NUM_COMPARTS)
    {
        throw out_of_range("Compartment index out of range");
    }

    if (!shelves[shelfIndex][compartmentIndex].IsEmpty())
    {
        cout << "Error: Compartment already has an item" << endl;
        return false;
    }

    shelves[shelfIndex][compartmentIndex].AddItem(move(item));
    return true; 
}

bool LibraryStorage::CheckInItem(int shelfIndex, int compartmentIndex)
{
    if (shelfIndex < 0 || shelfIndex >= shelves.size())
    {
        throw out_of_range("Shelf index out of range");
    }

    if (compartmentIndex < 0 || compartmentIndex >= Shelf::NUM_COMPARTS)
    {
        throw out_of_range("Compartment index out of range");
    }

    return shelves[shelfIndex][compartmentIndex].CheckIn();
}

bool LibraryStorage::CheckOutItem(int shelfIndex, int compartmentIndex, const string& borrowerName, const string& dueDate)
{
    if (shelfIndex < 0 || shelfIndex >= shelves.size())
    {
        throw out_of_range("Shelf index out of range");
    }
    
    if (compartmentIndex < 0 || compartmentIndex >= Shelf::NUM_COMPARTS)
    {
        throw out_of_range("Compartment index out of range");
    }

    return shelves[shelfIndex][compartmentIndex].CheckOut(borrowerName, dueDate);

}

void LibraryStorage::SwapItems(int shelfIndex1, int compartmentIndex1, int shelfIndex2, int compartmentIndex2)
{
    if (shelfIndex1 < 0 || shelfIndex1 >= shelves.size())
    {
        throw out_of_range("Shelf index 1 out of range");
    }

    if (compartmentIndex1 < 0 || compartmentIndex1 >= Shelf::NUM_COMPARTS)
    {
        throw out_of_range("Compartment index 1 out of range");
    }

    if (shelfIndex2 < 0 || shelfIndex2 >= shelves.size())
    {
        throw out_of_range("Shelf index 2 out of range");
    }

    if (compartmentIndex2 < 0 || compartmentIndex2 >= Shelf::NUM_COMPARTS)
    {
        throw out_of_range("Compartment index 2 out of range");
    }

    if (shelves[shelfIndex1][compartmentIndex1].IsEmpty() || shelves[shelfIndex2][compartmentIndex2].IsEmpty())
    {
        cout << "Error: One or both compartments are empty, cannot swap items." << endl;
        return;
    }

    shelves[shelfIndex1][compartmentIndex1].swap(shelves[shelfIndex2][compartmentIndex2]);

}

void LibraryStorage::PrintStorage() const
{

}

void LibraryStorage::PrintCheckedOutItems() const
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
