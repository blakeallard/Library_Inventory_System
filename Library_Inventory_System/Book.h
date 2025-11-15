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
    Book(const string& title, 
         const string& author,
         const string& descript, 
         const string& id, 
         const string& crDate);
    
    unique_ptr<Item>CreateItem() const override;
    void display(ostream& os) const override;
};

#endif  // FILENAME_H
