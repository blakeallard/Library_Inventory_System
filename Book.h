#ifndef BOOK_H_
#define BOOK_H_ 

#include "Item.h"


class Book : public Item
{
private:
    string title{};
    string author{};
    string crDate{};


public:
    Book();
    void display() const override;
    ~Book();
};

#endif  // FILENAME_H
