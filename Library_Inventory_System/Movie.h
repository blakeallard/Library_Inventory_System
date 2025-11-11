#ifndef MOVIE_H_
#define MOVIE_H_ 

#include "Item.h"
#include <string>
#include <vector>
using std::string, std::vector;

class Movie : public Item
{
private:
    string title{};
    string director{};
    vector<string> mainActors{};

public:
    Movie();
    Movie(const string& title, const string& director, const vector<string>& mainActors);
    
    virtual unique_ptr<Item> CreateItem() const;
    void display() const; 
    ~Movie();

};

#endif  // FILENAME_H
