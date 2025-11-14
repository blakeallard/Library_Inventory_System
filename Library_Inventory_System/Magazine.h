#ifndef MAGAZINE_H_
#define MAGAZINE_H_
#include "Item.h"


class Magazine : public Item 
{
private:
    int edition{};
    string artTitle{};

public:
    Magazine(const string& descript, const string& id,
             int edition, const string& artTitle);

    unique_ptr<Item> CreateItem() const override;
    void display(ostream& os) const override;
};

#endif  // MAGAZINE_H_
