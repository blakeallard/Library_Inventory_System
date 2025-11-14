#include "Movie.h"


Movie::Movie(const string& descript, const string& id,
             const string& title, const string& director, const vector<string>& mainActors)
    : Item("Movie", descript, id)
{
    this->title      = title;
    this->director   = director;
    this->mainActors = mainActors;
}

void Movie::display(ostream& os) const
{
    os << "=== MOVIE ===\n";
    Item::display(os);
    os << "Title: "     << title    << "\n";
    os << "Director: "  << director << "\n";
    os << "Main Actors: ";

    bool first = true;
    for (const string& actor : mainActors)
    {
        if (!first)
        {
            os << ", ";
        }
        os << actor;
        first = false;
    }
    os << "\n";
}

unique_ptr<Item> Movie::CreateItem() const
{
    return make_unique<Movie>(*this);
}
