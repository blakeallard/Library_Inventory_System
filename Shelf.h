#ifndef SHELF_H_
#define SHELF_H_
#include "Compartment.h"
#include <memory>
#include <stdexcept>
#include <array>
using std::array;


class Shelf
{
public:
    static const int NUM_COMPARTS = 15;

    Shelf();

    Compartment& operator[](int index);

    const Compartment& operator[](int index) const;

private:
    array<Compartment, NUM_COMPARTS> compartments;
};

#endif  // FILENAME_H
