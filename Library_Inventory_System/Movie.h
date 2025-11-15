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
    Movie(const string& title, 
          const string& director,
          const string& id, 
          const string& descript, 
          const vector<string>& mainActors);
    
    //unique_ptr<Item> CreateItem() const override;

    void display(ostream& os) const override; 
};

#endif  // FILENAME_H
