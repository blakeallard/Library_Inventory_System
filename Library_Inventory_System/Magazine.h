#ifndef MAGAZINE_H_
#define MAGAZINE_H_
#include "Item.h"


class Magazine : public Item 
{
private:
    string edition{};
    string artTitle{};

public:
    Magazine();
    Magazine(const string& edition, const string& artTitle);

    virtual unique_ptr<Item> CreateItem() const override;
    void display() const;
    ~Magazine();
    
};

#endif  // MAGAZINE_H_
