#ifndef ITEM_H_ 
#define ITEM_H_
#include <iostream>
#include <memory>
#include <string>
using std::string, std::ostream, std::unique_ptr, std::make_unique;

class Item 
{
private:
    string name{};
    string descript{};
    int    id{};

public:
    Item();

    void setName(const string& name);
    string getName() const; 

    
    void setDescript(const string& descript);
    string getDescript() const;

    
    void setID(int id);
    int getID() const;

    friend ostream& operator<<(ostream& stream, const Item& item);

    virtual unique_ptr<Item> CreateItem() const = 0;
    virtual void display() const = 0;
    virtual ~Item();
};

#endif  //ITEM_H_
