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
public:
    static const int NUM_COMPARTS = 15;
    Shelf();
    Compartment& operator[](int index);
    // ostream& operator=(ostream& stream) const;

private:
    Compartment compartments[NUM_COMPARTS];
};

#endif  // FILENAME_H
