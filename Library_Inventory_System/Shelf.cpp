#include "Shelf.h"
#include "Compartment.h"

Shelf::Shelf()
{
    for (int i = 0; i < NUM_COMPARTS; i++)
    {
        compartments[i] = make_unique<Compartment>();
    }
}
