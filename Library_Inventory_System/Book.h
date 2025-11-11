#ifndef BOOK_H_
#define BOOK_H_ 
#include "Item.h"
using std::make_unique, std::unique_ptr;


class Book : public Item
{
private:
    string title{};
    string author{};
    string crDate{};

public:
    Book();
    Book(const string& title, const string& author, const string& crDate);
    
    unique_ptr<Item>CreateItem() const override;
    void display() const override;
    ~Book();
};

#endif  // FILENAME_H
