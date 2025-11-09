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
    Magazine(const string& edition, const string& artTitle);

    void display() const;
    ~Magazine();
    
};

#endif  // MAGAZINE_H_
