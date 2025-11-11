#include "Shelf.h"

Shelf::Shelf()
{
    for (int i = 0; i < NUM_COMPARTS; ++i)
    {
        compartments[i] = Compartment();
    }
}

Compartment& Shelf::operator[](int index)
{
    if (index < 0 || index >= NUM_COMPARTS)
    {
        throw out_of_range("Compartment index is out of range.\n");
    }
    return compartments[index];
}