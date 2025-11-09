#include "Item.h"

Item::Item()
{
    name     = "";
    descript = "";
    id       = 0;
}

void Item::setName(const string& name) { this->name = name; }

string Item::getName() const { return name; }

void Item::setDescript(const string& descript) { this->descript = descript; }

string Item::getDescript() const { return descript; }

void Item::setID(int id) { this->id = id; }

int Item::getID() const { return id; }

ostream& operator<<(ostream& stream, const Item& item)
{
    stream << "Item ID: "     << item.getID()       << "\n";
    stream << "Name: "        << item.getName()     << "\n";
    stream << "Description: " << item.getDescript() << "\n";
    return stream;
}

Item::~Item()
{
    
}
