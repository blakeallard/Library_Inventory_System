#include "Movie.h"


Movie::Movie(const string& title, const string& director, const vector<string>& mainActors)
    : Item(name, descript, id)
{
    this->title      = title;
    this->director   = director;
    this->mainActors = mainActors;
}


bool Movie::isValidMovieID(const string& id) const
{

}

void Movie::display() const
{

}

unique_ptr<Item> Movie::CreateItem() const
{
    return make_unique<Movie>(*this);
}

Movie::~Movie()
{
}