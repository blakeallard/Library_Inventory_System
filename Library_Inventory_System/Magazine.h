#ifndef MAGAZINE_H_
#define MAGAZINE_H_
#include "Item.h"

class Magazine : public Item 
{
private:
    int edition{};
    string artTitle{};

public:
    Magazine(const string& artTitle, 
             const string& id, 
             const string& descript,
             int edition);

    void display(ostream& os) const override;

    string GetType()  const override;
    string GetTitle() const override;
};

#endif  // MAGAZINE_H_
