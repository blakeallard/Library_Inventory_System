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
    Book(const string& title, 
         const string& author,
         const string& descript, 
         const string& id, 
         const string& crDate);
    
    void display(ostream& os) const override;

    string GetType()  const override;
    string GetTitle() const override;
};

#endif  // FILENAME_H
