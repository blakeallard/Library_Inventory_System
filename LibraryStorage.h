#ifndef LIBRARY_STORAGE_H_
#define LIBRARY_STORAGE_H_


// Forward declaration
class Shelf;


const int NUM_SHELVES = 15;


class LibraryStorage 
{
private:
    Shelf* shelves[NUM_SHELVES];

public:
    LibraryStorage();
    ~LibraryStorage();
    
};

#endif  // FILENAME_H
