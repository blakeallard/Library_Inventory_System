#ifndef SHELF_H_
#define SHELF_H_
#include <memory>
using std::make_unique, std::unique_ptr;

const int NUM_COMPARTS = 15;


// Forward declaration
class Compartment;
  

class Shelf 
{
private:
    unique_ptr<Compartment> compartments[NUM_COMPARTS];

public:
    Shelf();
    ~Shelf();
    
};

#endif  // FILENAME_H
