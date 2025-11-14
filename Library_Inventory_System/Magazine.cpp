#include "Magazine.h"

Magazine::Magazine(const string& descript, const string& id,
                   int edition, const string& artTitle)
    : Item("Magazine", descript, id)
{
    this->edition  = edition;
    this->artTitle = artTitle;
}

void Magazine::display(ostream& os) const
{
    os << "=== MAGAZINE ===\n";
    Item::display(os);
    os << "Edition: "       << edition  << "\n";
    os << "Article Title: " << artTitle << "\n";
}

unique_ptr<Item> Magazine::CreateItem() const
{
    return make_unique<Magazine>(*this);
}
