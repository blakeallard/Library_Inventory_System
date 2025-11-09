#ifndef ITEM_H_ 
#define ITEM_H_
#include "Compartment.h"
#include <iostream>
#include <string>
using std::string, std::ostream;

class Item 
{
private:
    string name{};
    string descript{};
    int    id{};

public:
    Item();

    void setName(const string& name) { this->name = name; }
    string getName() const { return name; }

    
    void setDescript(const string& descript) { this->descript = descript; }
    string getDescript() const { return descript; }

    
    void setID(int id) { this->id = id; }
    int getID() const { return id; }

    friend ostream& operator<<(ostream& stream, const Item& item);

    virtual void display() const = 0;
    virtual ~Item();

};

#endif  //ITEM_H_
