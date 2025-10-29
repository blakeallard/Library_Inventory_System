#ifndef MOVIE_H_
#define MOVIE_H_ 

#include "Item.h"


class Movie : public Item
{
private:
    string title{};
    string director{};
    string mainActors{};

public:
    Movie();

    void display() const; 
    ~Movie();

};

#endif  // FILENAME_H
