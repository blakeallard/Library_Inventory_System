#ifndef LIBRARY_STORAGE_H_
#define LIBRARY_STORAGE_H_
#include "Shelf.h"
#include <iostream>
#include <memory>
#include <vector>
using std::cout, std::vector, std::unique_ptr;

class LibraryStorage 
{
private:
    vector<Shelf> shelves{};

public:
    static const int NUM_SHELVES = 3;

    LibraryStorage();

    bool AddItem(int shelfIndex, int compartmentIndex, unique_ptr<Item> item);

    bool CheckInItem(int shelfIndex, int compartmentIndex);

    bool CheckOutItem(int shelfIndex, int compartmentIndex, 
        const string& borrowerName, const string& dueDate);

    void SwapItems(int shelfIndex1, int compartmentIndex1, 
                   int shelfIndex2, int compartmentIndex2);

    void PrintStorage() const;

    void PrintCheckedOutItems() const;

    Shelf& operator[](int index);
    
    const Shelf& operator[](int index) const;
    
    void InitSampleData();
};

#endif  // FILENAME_H
