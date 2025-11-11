#include "Movie.h"

Movie::Movie()
{
    title      = "";
    director   = "";
    mainActors = {};
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