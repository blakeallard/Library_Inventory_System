#ifndef ITEM_H_ 
#define ITEM_H_
#include <iostream>
#include <memory>
#include <string>
using std::string, std::ostream, std::unique_ptr;

class Item 
{
protected:
    string name{};
    string descript{};
    string id{};

public:
    Item(const string& name, const string& descript, const string& id);
    
    void   setName(const string& name);
    string getName() const; 

    void   setDescript(const string& descript);
    string getDescript() const;

    void   setID(const string& id);
    string getID() const;

    virtual string GetType()  const = 0;
    virtual string GetTitle() const = 0;

    virtual void display(ostream& os) const;
    virtual ~Item();

    friend ostream& operator<<(ostream& stream, const Item& item);
};

#endif  //ITEM_H_
