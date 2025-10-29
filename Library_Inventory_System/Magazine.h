#ifndef MAGAZINE_H_
#define MAGAZINE_H_
#include "Item.h"


class Magazine 
{
private:
    string edition{};
    string artTitle{};


public:
    Magazine();

    void display() const;
    ~Magazine();
    
};

#endif  // MAGAZINE_H_
