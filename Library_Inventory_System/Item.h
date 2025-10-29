#ifndef ITEM_H_ 
#define ITEM_H_

#include <iostream>
#include <string>
using std::string;

class Item 
{
private:
    string name{};
    string descript{};
    int    id{};

public:
    Item();

    virtual void display() const;
    ~Item();
    
};

#endif  //ITEM_H_
