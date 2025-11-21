#ifndef MOVIE_H_
#define MOVIE_H_ 
#include "Item.h"
#include <vector>
using std::vector;

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
    
    void display(ostream& os) const override;

    string GetType()  const override;
    string GetTitle() const override;
};

#endif  // FILENAME_H
