#include "Item.h"

Item::Item(const string& name, const string& descript, const string& id)
{
    this->name     = name;
    this->descript = descript;
    this->id       = id;
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
