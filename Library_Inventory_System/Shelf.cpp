#include "Shelf.h"


Shelf::Shelf() {}

Compartment& Shelf::operator[](int index)
{
    if (index < 0 || index >= NUM_COMPARTS)
    {
        throw out_of_range("Compartment index is out of range.\n");
    }
    return compartments[index];
}

const Compartment& Shelf::operator[](int index) const
{
    if (index < 0 || index >= NUM_COMPARTS)
    {
        throw out_of_range("Compartment index is out of range.\n");
    }
    return compartments[index];
}
