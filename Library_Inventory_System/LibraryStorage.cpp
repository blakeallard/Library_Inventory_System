#include "LibraryStorage.h"
#include "Book.h"
#include "Movie.h"
#include "Magazine.h"

LibraryStorage::LibraryStorage()
{
    for (int i = 0; i < NUM_SHELVES; i++) 
    {
        shelves.push_back(Shelf());
    }
}


// to add items to shelves, 
// must know shelf index and compartment index
bool LibraryStorage::AddItem(int shelfIndex, int compartmentIndex, unique_ptr<Item> item)
{
    if (shelfIndex < 0 || shelfIndex >= shelves.size())
    {
        throw out_of_range("Shelf index out of range");
    }
    
    if (compartmentIndex < 0 || compartmentIndex >= Shelf::NUM_COMPARTS)
    {
        throw out_of_range("Compartment index out of range");
    }

    if (!shelves[shelfIndex][compartmentIndex].IsEmpty())
    {
        cout << "Error: Compartment already has an item" << endl;
        return false;
    }

    shelves[shelfIndex][compartmentIndex].AddItem(move(item));
    return true; 
}

bool LibraryStorage::CheckInItem(int shelfIndex, int compartmentIndex)
{
    if (shelfIndex < 0 || shelfIndex >= shelves.size())
    {
        throw out_of_range("Shelf index out of range");
    }

    if (compartmentIndex < 0 || compartmentIndex >= Shelf::NUM_COMPARTS)
    {
        throw out_of_range("Compartment index out of range");
    }

    return shelves[shelfIndex][compartmentIndex].CheckIn();
}

bool LibraryStorage::CheckOutItem(int shelfIndex, int compartmentIndex, const string& borrowerName, const string& dueDate)
{
    if (shelfIndex < 0 || shelfIndex >= shelves.size())
    {
        throw out_of_range("Shelf index out of range");
    }
    
    if (compartmentIndex < 0 || compartmentIndex >= Shelf::NUM_COMPARTS)
    {
        throw out_of_range("Compartment index out of range");
    }

    return shelves[shelfIndex][compartmentIndex].CheckOut(borrowerName, dueDate);

}

void LibraryStorage::SwapItems(int shelfIndex1, int compartmentIndex1, int shelfIndex2, int compartmentIndex2)
{
    if (shelfIndex1 < 0 || shelfIndex1 >= shelves.size())
    {
        throw out_of_range("Shelf index 1 out of range");
    }

    if (compartmentIndex1 < 0 || compartmentIndex1 >= Shelf::NUM_COMPARTS)
    {
        throw out_of_range("Compartment index 1 out of range");
    }

    if (shelfIndex2 < 0 || shelfIndex2 >= shelves.size())
    {
        throw out_of_range("Shelf index 2 out of range");
    }

    if (compartmentIndex2 < 0 || compartmentIndex2 >= Shelf::NUM_COMPARTS)
    {
        throw out_of_range("Compartment index 2 out of range");
    }

    if (shelves[shelfIndex1][compartmentIndex1].IsEmpty() || shelves[shelfIndex2][compartmentIndex2].IsEmpty())
    {
        cout << "Error: One or both compartments are empty, cannot swap items." << endl;
        return;
    }

    shelves[shelfIndex1][compartmentIndex1].swap(shelves[shelfIndex2][compartmentIndex2]);

}

void LibraryStorage::PrintStorage() const
{
    cout << "\n========== LIBRARY STORAGE ==========\n";

        for (int s = 0; s < shelves.size(); s++)
        {
            cout << "\n--- Shelf " << s << " ---\n";

            for (int c = 0; c < Shelf::NUM_COMPARTS; ++c)
            {
                const Compartment& comp = shelves[s][c];

                cout << "  [" << c << "] ";

                if (comp.IsEmpty())
                {
                    cout << "(empty)\n";
                    continue;
                }

                const Item* item = comp.GetItem();
                cout << item->getName() << "  (ID: " << item->getID() << ")";

                if (comp.IsCheckedOut())
                {
                    cout << "  -- CHECKED OUT by " 
                         << comp.getCheckedOutBy()
                         << ", due " << comp.getDueDate();
                }
                else
                {
                    cout << "  -- Available";
                }

                cout << "\n";
            }
        }

        cout << "=====================================\n\n";
}

void LibraryStorage::PrintCheckedOutItems() const
{
    cout << "\n========== CHECKED OUT ITEMS ==========\n";

        bool foundAny = false;

        for (int s = 0; s < shelves.size(); ++s)
        {
            for (int c = 0; c < Shelf::NUM_COMPARTS; ++c)
            {
                const Compartment& comp = shelves[s][c];

                if (!comp.IsEmpty() && comp.IsCheckedOut())
                {
                    foundAny = true;

                    const Item* item = comp.GetItem();

                    cout << "- " << item->getName()
                        << "  (ID: "         << item->getID()          << ")\n"
                        << "    Borrower: "  << comp.getCheckedOutBy() << "\n"
                        << "    Due Date: "  << comp.getDueDate()      << "\n"
                        << "    Shelf: "     << s 
                        << ", Compartment: " << c                      << "\n\n";
                }
            }
        }

        if (!foundAny)
        {
            cout << "No items are currently checked out.\n";
        }

        cout << "=======================================\n\n";
}

Shelf& LibraryStorage::operator[](int index)
{
    if (index < 0 || index >= shelves.size())
    {
        throw out_of_range("Shelf index out of range");
    }
    return shelves[index];
}

void LibraryStorage::InitSampleData(LibraryStorage &libraryInventory)
{
    libraryInventory.AddItem(0, 0, make_unique<Book>("The Great Gatsby", 
                                                     "F. Scott Fitzgerald", 
                                                     "A novel set in the Jazz Age", 
                                                     "B001", 
                                                     "1925"));
    libraryInventory.AddItem(0, 1, make_unique<Book>("1984", 
                                                     "George Orwell", 
                                                     "Dystopian social science fiction novel", 
                                                     "B002", 
                                                     "1949"));
    libraryInventory.AddItem(0, 2, make_unique<Book>("To Kill a Mockingbird", 
                                                     "Harper Lee", 
                                                     "Novel about racial injustice", 
                                                     "B003", 
                                                     "1960"));
    libraryInventory.AddItem(0, 3, make_unique<Book>("The Catcher in the Rye", 
                                                     "J.D. Salinger", 
                                                     "Story about adolescent alienation", 
                                                     "B004", 
                                                     "1951"));
    libraryInventory.AddItem(0, 4, make_unique<Book>("Pride and Prejudice", 
                                                     "Jane Austen", 
                                                     "Romantic novel of manners", 
                                                     "B005", 
                                                     "1813"));
    libraryInventory.AddItem(0, 5, make_unique<Book>("Eragon", 
                                                     "Christopher Paolini", 
                                                     "Fantasy novel about a young dragon rider", 
                                                     "B006", 
                                                     "2002"));
    libraryInventory.AddItem(0, 6, make_unique<Book>("Fahrenheit 451", 
                                                     "Ray Bradbury", 
                                                     "Dystopian novel about book burning", 
                                                     "B007", 
                                                     "1953"));
    libraryInventory.AddItem(0, 7, make_unique<Book>("Moby Dick", 
                                                     "Herman Melville", 
                                                     "Epic tale of a sea captain's obsession", 
                                                     "B008", 
                                                     "1851"));
    libraryInventory.AddItem(0, 8, make_unique<Book>("War and Peace", 
                                                     "Leo Tolstoy", 
                                                     "Historical novel set during the Napoleonic Wars", 
                                                     "B009", 
                                                     "1869"));
    libraryInventory.AddItem(0, 9, make_unique<Book>("The Odyssey", 
                                                      "Homer", 
                                                      "Ancient Greek epic poem", 
                                                      "B010", 
                                                      "8th Century BC"));
    libraryInventory.AddItem(0, 10, make_unique<Movie>("The Matrix", 
                                                      "The Wachowskis", 
                                                      "M002", 
                                                      "A hacker discovers the nature of reality", 
                                                      vector<string>{"Keanu Reeves", "Laurence Fishburne", "Carrie-Anne Moss"}));
    libraryInventory.AddItem(0, 11, make_unique<Movie>("The Godfather", 
                                                      "Francis Ford Coppola", 
                                                      "M003", 
                                                      "Crime film about a mafia family", 
                                                      vector<string>{"Marlon Brando", "Al Pacino", "James Caan"}));
    libraryInventory.AddItem(0, 12, make_unique<Movie>("Titanic", 
                                                      "James Cameron", 
                                                      "M004", 
                                                      "Romantic drama set on the ill-fated RMS Titanic", 
                                                      vector<string>{"Leonardo DiCaprio", "Kate Winslet"}));
    libraryInventory.AddItem(0, 13, make_unique<Movie>("Avatar", 
                                                      "James Cameron", 
                                                      "M005", 
                                                      "Science fiction epic set on the alien world of Pandora", 
                                                      vector<string>{"Sam Worthington", "Zoe Saldana", "Sigourney Weaver"}));
    libraryInventory.AddItem(0, 14, make_unique<Movie>("Jurassic Park", 
                                                      "Steven Spielberg", 
                                                      "M006", 
                                                      "Adventure film about a dinosaur theme park", 
                                                      vector<string>{"Sam Neill", "Laura Dern", "Jeff Goldblum"}));
    libraryInventory.AddItem(1, 0, make_unique<Movie>("The Lion King", 
                                                      "Roger Allers and Rob Minkoff", 
                                                      "M007", 
                                                      "Animated musical about a lion cub's journey to adulthood", 
                                                      vector<string>{"Matthew Broderick", "Jeremy Irons", "James Earl Jones"}));
    libraryInventory.AddItem(1, 1, make_unique<Movie>("The Incredibles", 
                                                      "Brad Bird", 
                                                      "M008", 
                                                      "Animated film about a family of superheroes", 
                                                      vector<string>{"Craig T. Nelson", "Holly Hunter", "Samuel L. Jackson"}));
    libraryInventory.AddItem(1, 2, make_unique<Movie>("Finding Nemo", 
                                                      "Andrew Stanton", 
                                                      "M009", 
                                                      "Animated adventure about a clownfish searching for his son", 
                                                      vector<string>{"Albert Brooks", "Ellen DeGeneres", "Alexander Gould"}));
    libraryInventory.AddItem(1, 3, make_unique<Movie>("Toy Story", 
                                                      "John Lasseter", 
                                                      "M010", 
                                                      "Animated film about toys coming to life", 
                                                      vector<string>{"Tom Hanks", "Tim Allen", "Don Rickles"}));
    libraryInventory.AddItem(1, 4, make_unique<Magazine>("Tech Today", 
                                                         "MG001", 
                                                         "Latest updates in technology", 
                                                         45));
    libraryInventory.AddItem(1, 5, make_unique<Magazine>("Health Weekly", 
                                                         "MG002", 
                                                         "Your guide to healthy living", 
                                                         30));
    libraryInventory.AddItem(1, 6, make_unique<Magazine>("Travel Explorer", 
                                                         "MG003", 
                                                         "Discover new travel destinations", 
                                                         22));
    libraryInventory.AddItem(1, 7, make_unique<Magazine>("Foodie Fun", 
                                                         "MG004", 
                                                         "Delicious recipes and food trends", 
                                                         18));
    libraryInventory.AddItem(1, 8, make_unique<Magazine>("Sports Central", 
                                                         "MG005", 
                                                         "All about the world of sports", 
                                                         55));
    libraryInventory.AddItem(1, 9, make_unique<Magazine>("Art Monthly", 
                                                         "MG006", 
                                                         "Exploring the world of art", 
                                                         12));
    libraryInventory.AddItem(1, 10, make_unique<Magazine>("Science Digest", 
                                                          "MG007", 
                                                          "Latest scientific discoveries", 
                                                          40));
    libraryInventory.AddItem(1, 11, make_unique<Magazine>("Fashion Forward", 
                                                          "MG008", 
                                                          "Trends in the fashion industry", 
                                                          27));
    libraryInventory.AddItem(1, 12, make_unique<Magazine>("Gaming World", 
                                                          "MG009", 
                                                          "All about video games", 
                                                          33));
    libraryInventory.AddItem(1, 13, make_unique<Magazine>("Movie Magic", 
                                                          "MG010", 
                                                          "Behind the scenes of Hollywood", 
                                                          29));
}