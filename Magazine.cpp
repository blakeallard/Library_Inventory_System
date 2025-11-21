#include "Magazine.h"

Magazine::Magazine(const string& artTitle, const string& id,
                   const string& descript, int edition)
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

string Magazine::GetType() const { return "Magazine"; }

string Magazine::GetTitle() const { return artTitle; }