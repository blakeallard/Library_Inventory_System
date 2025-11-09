#ifndef SHELF_H_
#define SHELF_H_
#include "Compartment.h"
#include <memory>
#include <iostream>
#include <stdexcept>
using std::make_unique, std::unique_ptr, std::ostream, std::out_of_range;



// Forward declaration
class Item;


class Shelf
{
private:
    static const int NUM_COMPARTS = 15;
    Compartment compartments[NUM_COMPARTS];

public:
    Shelf();
    Compartment& operator[](int index);
};

#endif  // FILENAME_H
