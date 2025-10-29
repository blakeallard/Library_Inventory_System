#ifndef SHELF_H_
#define SHELF_H_

const int NUM_COMPARTS = 15;


// Forward declaration
class Compartment;
  

class Shelf 
{
private:
    Compartment* compartments[NUM_COMPARTS];


public:
    Shelf();
    ~Shelf();
    
};

#endif  // FILENAME_H
