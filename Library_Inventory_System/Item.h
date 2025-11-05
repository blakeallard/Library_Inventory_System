#ifndef ITEM_H_ 
#define ITEM_H_

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
    string getName() { return name; }

    
    void setDescript(const string& descript) { this->descript = descript; }
    string getDescript() { return descript; }

    
    void setID(int id) { this->id = id; }
    int getID() { return id; }

    ostream& operator<<(ostream& stream);

    virtual void display() const;
    virtual ~Item();
    
};

#endif  //ITEM_H_
