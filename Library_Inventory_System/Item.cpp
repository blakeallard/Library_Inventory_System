#include "Item.h"

Item::Item(const string& name, const string& descript, const string& id)
{
    this->name     = name;
    this->descript = descript;
    this->id       = id;
}

//void Item::setName(const string& name) { this->name = name; }

string Item::getName() const { return name; }

//void Item::setDescript(const string& descript) { this->descript = descript; }

string Item::getDescript() const { return descript; }

//void Item::setID(const string& id) { this->id = id; }

string Item::getID() const { return id; }

void Item::display(ostream& os) const
{
    os << "Item ID: "     << id       << "\n";
    os << "Name: "        << name     << "\n";
    os << "Description: " << descript << "\n";
}

ostream& operator<<(ostream& stream, const Item& item)
{
    item.display(stream);
    return stream;
}

Item::~Item()
{
    
}
