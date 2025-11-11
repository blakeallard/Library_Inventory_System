#include "Magazine.h"

Magazine::Magazine()
{
    edition  = "";
    artTitle = "";
}

void Magazine::display() const
{

}

unique_ptr<Item> Magazine::CreateItem() const
{
    return make_unique<Magazine>(*this);
}



Magazine::~Magazine()
{

}
