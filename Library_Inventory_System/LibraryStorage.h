#ifndef LIBRARY_STORAGE_H_
#define LIBRARY_STORAGE_H_
#include "Shelf.h"
#include <iostream>
#include <vector>
using std::cout, std::vector, std::out_of_range;




class LibraryStorage 
{
private:
    vector<Shelf> shelves{};

public:
    // Default constructor initializes shelves vector 
    // with NUM_SHELVES Shelf objects
    LibraryStorage();

    // in order to add items to shelves, 
    // must know which shelf index and compartment index
    void AddItem(int shelfIndex, int compartmentIndex, const Item& item);


    void CheckInItem();
    void CheckOutItem();
    void SwapItems();
    void PrintStorage();
    void PrintCheckedOutItems();
    Shelf& operator[](int index);
};

#endif  // FILENAME_H
