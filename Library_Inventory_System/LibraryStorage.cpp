#include "LibraryStorage.h"
#include "Book.h"
#include "Movie.h"
#include "Magazine.h"
#include "Item.h"
#include <iomanip>
using std::out_of_range, std::move, std::endl, std::make_unique, std::invalid_argument;

LibraryStorage::LibraryStorage()
{
    for (int i = 0; i < NUM_SHELVES; i++) 
    {
        shelves.push_back(Shelf());
    }
}

// to add items to shelves, 
// need shelf index and compartment index
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
        throw invalid_argument("One or both compartments are empty, cannot swap!\n\n");
    }
    cout << '\n';
    cout << shelves[shelfIndex1][compartmentIndex1].GetItem()->GetTitle()
         << " (Shelf " << shelfIndex1 + 1 << ", Compartment " << compartmentIndex1 + 1 << ")"
         << " was successfully swapped with\n"
         << shelves[shelfIndex2][compartmentIndex2].GetItem()->GetTitle()
         << " (Shelf " << shelfIndex2 + 1 << ", Compartment " << compartmentIndex2 + 1 << ")"
         << "!\n\n";

    shelves[shelfIndex1][compartmentIndex1].swap(shelves[shelfIndex2][compartmentIndex2]);
}

void LibraryStorage::PrintStorage() const
{
    const int NAME_W = 30;
    const int ID_W = 10;
    const int STATUS_W = 14;
    const int BORROWER_W = 18;
    const int DUE_W = 12;

    cout << "\n========== LIBRARY STORAGE ==========\n\n";

    // Header
    cout << std::left << std::setw(6) << "Shelf" << std::setw(6) << "Comp"
         << std::setw(NAME_W) << "Name" << std::setw(ID_W) << "ID"
         << std::setw(STATUS_W) << "Status" << std::setw(BORROWER_W)
         << "Borrower" << std::setw(DUE_W) << "Due" << '\n';

    cout << string(6 + 6 + NAME_W + ID_W + STATUS_W + BORROWER_W + DUE_W, '-')
         << '\n';

    for (int s = 0; s < shelves.size(); s++) {
        for (int c = 0; c < Shelf::NUM_COMPARTS; ++c) {
            const Compartment& comp = shelves[s][c];

            cout << std::left << std::setw(6) << s + 1 << std::setw(6) << c + 1;

            if (comp.IsEmpty()) {
                cout << std::setw(NAME_W) << "(empty)" << std::setw(ID_W) << ""
                     << std::setw(STATUS_W) << "" << std::setw(BORROWER_W) << ""
                     << std::setw(DUE_W) << "" << '\n';
                continue;
            }

            const Item* item = comp.GetItem();
            string name = item->GetTitle();
            if ((int)name.size() > NAME_W - 1) {
                name = name.substr(0, NAME_W - 4) + "...";
            }

            string status = comp.IsCheckedOut() ? "Checked out" : "Available";

            cout << std::setw(NAME_W) << name << std::setw(ID_W)
                 << item->getID() << std::setw(STATUS_W) << status;

            if (comp.IsCheckedOut()) {
                cout << std::setw(BORROWER_W) << comp.getCheckedOutBy()
                     << std::setw(DUE_W) << comp.getDueDate();
            } else {
                cout << std::setw(BORROWER_W) << "" << std::setw(DUE_W) << "";
            }

            cout << '\n';
        }
    }

    cout << "=====================================\n\n";
    // cout << "\n========== LIBRARY STORAGE ==========\n";

    //     for (int i = 0; i < shelves.size(); i++)
    //     {
    //         cout << "\n--- Shelf " << i << " ---\n";

    //         for (int j = 0; j < Shelf::NUM_COMPARTS; j++)
    //         {
    //             const Compartment& comp = shelves[i][j];

    //             cout << "  [" << j << "] ";

    //             if (comp.IsEmpty())
    //             {
    //                 cout << "(empty)\n";
    //                 continue;
    //             }

    //             const Item* item = comp.GetItem();
    //             cout << item->getName() << "  (ID: " << item->getID() << ")";
    //             cout << " - Title: " << item->GetTitle();
                

    //             if (comp.IsCheckedOut())
    //             {
    //                 cout << "  -- CHECKED OUT by " 
    //                      << comp.getCheckedOutBy()
    //                      << ", due " << comp.getDueDate();
    //             }
    //             else
    //             {
    //                 cout << "  -- Available";
    //             }

    //             cout << "\n";
    //         }
    //     }

    //     cout << "=====================================\n\n";
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

const Shelf& LibraryStorage::operator[](int index) const
{
    if (index < 0 || index >= shelves.size())
    {
        throw out_of_range("Shelf index out of range");
    }
    return shelves[index];
}

void LibraryStorage::InitSampleData()
{
    AddItem(0, 0, make_unique<Book>("The Great Gatsby", 
                                                     "F. Scott Fitzgerald", 
                                                     "A novel set in the Jazz Age", 
                                                     "B001", 
                                                     "1925"));
    AddItem(0, 1, make_unique<Book>("1984", 
                                                     "George Orwell", 
                                                     "Dystopian social science fiction novel", 
                                                     "B002", 
                                                     "1949"));
    AddItem(0, 2, make_unique<Book>("To Kill a Mockingbird", 
                                                     "Harper Lee", 
                                                     "Novel about racial injustice", 
                                                     "B003", 
                                                     "1960"));
    AddItem(0, 3, make_unique<Book>("The Catcher in the Rye", 
                                                     "J.D. Salinger", 
                                                     "Story about adolescent alienation", 
                                                     "B004", 
                                                     "1951"));
    AddItem(0, 4, make_unique<Book>("Pride and Prejudice", 
                                                     "Jane Austen", 
                                                     "Romantic novel of manners", 
                                                     "B005", 
                                                     "1813"));
    AddItem(0, 5, make_unique<Book>("Eragon", 
                                                     "Christopher Paolini", 
                                                     "Fantasy novel about a young dragon rider", 
                                                     "B006", 
                                                     "2002"));
    AddItem(0, 6, make_unique<Book>("Fahrenheit 451", 
                                                     "Ray Bradbury", 
                                                     "Dystopian novel about book burning", 
                                                     "B007", 
                                                     "1953"));
    AddItem(0, 7, make_unique<Book>("Moby Dick", 
                                                     "Herman Melville", 
                                                     "Epic tale of a sea captain's obsession", 
                                                     "B008", 
                                                     "1851"));
    AddItem(0, 8, make_unique<Book>("War and Peace", 
                                                     "Leo Tolstoy", 
                                                     "Historical novel set during the Napoleonic Wars", 
                                                     "B009", 
                                                     "1869"));
    AddItem(0, 9, make_unique<Book>("The Odyssey", 
                                                      "Homer", 
                                                      "Ancient Greek epic poem", 
                                                      "B010", 
                                                      "8th Century BC"));
    AddItem(0, 10, make_unique<Movie>("The Matrix", 
                                                      "The Wachowskis", 
                                                      "M002", 
                                                      "A hacker discovers the nature of reality", 
                                                      vector<string>{"Keanu Reeves", "Laurence Fishburne", "Carrie-Anne Moss"}));
    AddItem(0, 11, make_unique<Movie>("The Godfather", 
                                                      "Francis Ford Coppola", 
                                                      "M003", 
                                                      "Crime film about a mafia family", 
                                                      vector<string>{"Marlon Brando", "Al Pacino", "James Caan"}));
    AddItem(0, 12, make_unique<Movie>("Titanic", 
                                                      "James Cameron", 
                                                      "M004", 
                                                      "Romantic drama set on the ill-fated RMS Titanic", 
                                                      vector<string>{"Leonardo DiCaprio", "Kate Winslet"}));
    AddItem(0, 13, make_unique<Movie>("Avatar", 
                                                      "James Cameron", 
                                                      "M005", 
                                                      "Science fiction epic set on the alien world of Pandora", 
                                                      vector<string>{"Sam Worthington", "Zoe Saldana", "Sigourney Weaver"}));
    AddItem(0, 14, make_unique<Movie>("Jurassic Park", 
                                                      "Steven Spielberg", 
                                                      "M006", 
                                                      "Adventure film about a dinosaur theme park", 
                                                      vector<string>{"Sam Neill", "Laura Dern", "Jeff Goldblum"}));
    AddItem(1, 0, make_unique<Movie>("The Lion King", 
                                                      "Roger Allers and Rob Minkoff", 
                                                      "M007", 
                                                      "Animated musical about a lion cub's journey to adulthood", 
                                                      vector<string>{"Matthew Broderick", "Jeremy Irons", "James Earl Jones"}));
    AddItem(1, 1, make_unique<Movie>("The Incredibles", 
                                                      "Brad Bird", 
                                                      "M008", 
                                                      "Animated film about a family of superheroes", 
                                                      vector<string>{"Craig T. Nelson", "Holly Hunter", "Samuel L. Jackson"}));
    AddItem(1, 2, make_unique<Movie>("Finding Nemo", 
                                                      "Andrew Stanton", 
                                                      "M009", 
                                                      "Animated adventure about a clownfish searching for his son", 
                                                      vector<string>{"Albert Brooks", "Ellen DeGeneres", "Alexander Gould"}));
    AddItem(1, 3, make_unique<Movie>("Toy Story", 
                                                      "John Lasseter", 
                                                      "M010", 
                                                      "Animated film about toys coming to life", 
                                                      vector<string>{"Tom Hanks", "Tim Allen", "Don Rickles"}));
    AddItem(1, 4, make_unique<Magazine>("Tech Today", 
                                                         "MG001", 
                                                         "Latest updates in technology", 
                                                         45));
    AddItem(1, 5, make_unique<Magazine>("Health Weekly", 
                                                         "MG002", 
                                                         "Your guide to healthy living", 
                                                         30));
    AddItem(1, 6, make_unique<Magazine>("Travel Explorer", 
                                                         "MG003", 
                                                         "Discover new travel destinations", 
                                                         22));
    AddItem(1, 7, make_unique<Magazine>("Foodie Fun", 
                                                         "MG004", 
                                                         "Delicious recipes and food trends", 
                                                         18));
    AddItem(1, 8, make_unique<Magazine>("Sports Central", 
                                                         "MG005", 
                                                         "All about the world of sports", 
                                                         55));
    AddItem(1, 9, make_unique<Magazine>("Art Monthly", 
                                                         "MG006", 
                                                         "Exploring the world of art", 
                                                         12));
    AddItem(1, 10, make_unique<Magazine>("Science Digest", 
                                                          "MG007", 
                                                          "Latest scientific discoveries", 
                                                          40));
    AddItem(1, 11, make_unique<Magazine>("Fashion Forward", 
                                                          "MG008", 
                                                          "Trends in the fashion industry", 
                                                          27));
    AddItem(1, 12, make_unique<Magazine>("Gaming World", 
                                                          "MG009", 
                                                          "All about video games", 
                                                          33));
    AddItem(1, 13, make_unique<Magazine>("Movie Magic", 
                                                          "MG010", 
                                                          "Behind the scenes of Hollywood", 
                                                          29));
    AddItem(1, 14, make_unique<Movie>("Inception", 
                                                          "Christopher Nolan", 
                                                          "M011", 
                                                          "A thief who steals corporate secrets through dream-sharing technology", 
                                                          vector<string>{"Leonardo DiCaprio", "Joseph Gordon-Levitt", "Ellen Page"}));
    AddItem(2, 0, make_unique<Movie>("The Matrix", 
                                                          "The Wachowskis", 
                                                          "M012", 
                                                          "A hacker discovers the nature of reality", 
                                                          vector<string>{"Keanu Reeves", "Laurence Fishburne", "Carrie-Anne Moss"}));
    AddItem(2, 1, make_unique<Movie>("Trainspotting", 
                                                          "Danny Boyle", 
                                                          "M013", 
                                                          "A group of heroin addicts in Edinburgh", 
                                                          vector<string>{"Ewan McGregor", "Ewen Bremner", "Jonny Lee Miller"}));
    AddItem(2, 2, make_unique<Movie>("The Godfather", 
                                                          "Francis Ford Coppola", 
                                                          "M014", 
                                                          "Crime film about a mafia family", 
                                                          vector<string>{"Marlon Brando", "Al Pacino", "James Caan"}));
    AddItem(2, 3, make_unique<Movie>("Pulp Fiction", 
                                                          "Quentin Tarantino", 
                                                          "M015", 
                                                          "Interconnected stories of crime in Los Angeles", 
                                                          vector<string>{"John Travolta", "Uma Thurman", "Samuel L. Jackson"}));
    AddItem(2, 4, make_unique<Movie>("The Dark Knight", 
                                                          "Christopher Nolan", 
                                                          "M016", 
                                                          "Batman faces off against the Joker", 
                                                          vector<string>{"Christian Bale", "Heath Ledger", "Aaron Eckhart"}));
    AddItem(2, 5, make_unique<Movie>("Forrest Gump", 
                                                          "Robert Zemeckis", 
                                                          "M017", 
                                                          "The life journey of Forrest Gump", 
                                                          vector<string>{"Tom Hanks", "Robin Wright", "Gary Sinise"}));
    AddItem(2, 6, make_unique<Movie>("The Shawshank Redemption", 
                                                          "Frank Darabont", 
                                                          "M018",                                                          
                                                          "Two imprisoned men bond over a number of years", 
                                                          vector<string>{"Tim Robbins", "Morgan Freeman", "Bob Gunton"}));
    AddItem(2, 7, make_unique<Movie>("Fight Club", 
                                                          "David Fincher", 
                                                          "M019", 
                                                          "An insomniac office worker forms an underground fight club", 
                                                          vector<string>{"Brad Pitt", "Edward Norton", "Helena Bonham Carter"}));
    AddItem(2, 8, make_unique<Movie>("The Social Network", 
                                                          "David Fincher", 
                                                          "M020", 
                                                          "The founding of Facebook", 
                                                          vector<string>{"Jesse Eisenberg", "Andrew Garfield", "Justin Timberlake"})); 
    AddItem(2, 9, make_unique<Movie>("Gladiator", 
                                                          "Ridley Scott", 
                                                          "M021", 
                                                          "A former Roman General seeks revenge", 
                                                          vector<string>{"Russell Crowe", "Joaquin Phoenix", "Connie Nielsen"}));
    AddItem(2, 10, make_unique<Movie>("The Departed", 
                                                          "Martin Scorsese", 
                                                          "M022", 
                                                          "An undercover cop and a mole in the police attempt to identify each other", 
                                                          vector<string>{"Leonardo DiCaprio", "Matt Damon", "Jack Nicholson"}));
    AddItem(2, 11, make_unique<Book>("Harry Potter and the Half-Blood Prince", 
                                                     "J.K. Rowling", 
                                                     "The sixth book in the Harry Potter series", 
                                                     "B011", 
                                                     "2005"));
    AddItem(2, 12, make_unique<Book>("Dracula", 
                                                     "Bram Stoker", 
                                                     "Gothic horror novel about the vampire Count Dracula", 
                                                     "B012", 
                                                     "1897"));
    AddItem(2, 13, make_unique<Book>("Percy Jackson & The Olympians: The Lightning Thief", 
                                                     "Rick Riordan", 
                                                     "Fantasy novel about a modern-day demigod", 
                                                     "B013", 
                                                     "2005"));
    AddItem(2, 14, make_unique<Book>("Young Goodman Brown", 
                                                     "Nathaniel Hawthorne", 
                                                     "Short story about a Puritan's encounter with the devil", 
                                                     "B014", 
                                                     "1835"));
}