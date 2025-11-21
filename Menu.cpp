#include "Menu.h"
#include "LibraryStorage.h"
#include "Book.h"
#include "Magazine.h"
#include "Movie.h"
using std::exception;

void Menu::DisplayMenu() {
    std::cout << "=== Library Inventory System Menu ===\n";
    std::cout << "1. Add Item\n";
    std::cout << "2. Check Out Item\n";
    std::cout << "3. Check In Item\n";
    std::cout << "4. Print Items In Storage\n";
    std::cout << "5. Print Checked Out Items\n";
    std::cout << "6. Swap Items\n";
    std::cout << "7. Exit\n";
    std::cout << "Please select an option (1-7): ";
}

// Function to handle adding an item by user input
void Menu::AddItemMenu(LibraryStorage& libraryInventory)
{
    string descript;
    string id;


    cout << "Select item type to add:\n";
    cout << "1. Book\n";
    cout << "2. Movie\n";
    cout << "3. Magazine\n";
    cout << "Enter choice (1-3): ";

    int itemTypeChoice{};
    do
    {
        cin >> itemTypeChoice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid choice. Please enter a number between 1 - 3: ";
        }
        else if (itemTypeChoice < 1 || itemTypeChoice > 3)
        {
            cout << "Invalid choice. Please enter a number between 1 - 3: ";
        }
    } while (itemTypeChoice < 1 || itemTypeChoice > 3);

    
    cout << "Enter add location for the item:\n";
    int shelfIndex       = LibraryStorage::GetValidShelfIndex();
    int compartmentIndex = LibraryStorage::GetValidCompartmentIndex();

    try
    {
        switch (itemTypeChoice)
        {
            case 1:
                {
                    cout << "Enter Book Details:\n";
                    string title, author, crDate;

                    cout << "Title: ";
                    getline(cin, title);
                    cout << "Author: ";
                    getline(cin, author);
                    cout << "Description: ";
                    getline(cin, descript);
                    cout << "ID: ";
                    getline(cin, id);
                    cout << "Creation Date: ";
                    getline(cin, crDate);

                    Book newItem(title, author, descript, id, crDate);
                    libraryInventory.AddItem(shelfIndex, compartmentIndex, std::make_unique<Book>(newItem));
                    break;
                }
            case 2:
                {
                    cout << "Enter Movie Details:\n";
                    string title, director;
                    int numActors;

                    cout << "Title: ";
                    getline(cin, title);
                    cout << "Director: ";
                    getline(cin, director);
                    cout << "Description: ";
                    getline(cin, descript);
                    cout << "ID: ";
                    getline(cin, id);
                    cout << "Number of Main Actors: ";
                    cin >> numActors;
                    cin.ignore(10000, '\n');

                    vector<string> mainActors;
                    for (int i = 0; i < numActors; i++)
                    {
                        string actorName;
                        cout << "Enter name of actor #" << (i + 1) << ": ";
                        getline(cin, actorName);
                        mainActors.push_back(actorName);
                    }

                    Movie newItem(title, director, id, descript, mainActors);
                    libraryInventory.AddItem(shelfIndex, compartmentIndex, std::make_unique<Movie>(newItem));
                    break;
                }
            case 3:
                {
                    cout << "Enter Magazine Details:\n";
                    string artTitle;
                    int edition;

                    cout << "Article Title: ";
                    getline(cin, artTitle);
                    cout << "Edition: ";
                    cin >> edition;
                    cin.ignore(10000, '\n');

                    Magazine newItem(artTitle, id, descript, edition);
                    libraryInventory.AddItem(shelfIndex, compartmentIndex, std::make_unique<Magazine>(newItem));
                    break;
                }
        }
    }
    catch (const exception& e)
    {
        cout << "Error: " << e.what() << endl;
    }
}

void Menu::CheckOutItemMenu(LibraryStorage& libraryInventory) {
    int shelfIndex = LibraryStorage::GetValidShelfIndex();
    int compartmentIndex = LibraryStorage::GetValidCompartmentIndex();
    string yourName = LibraryStorage::GetValidName();
    string dueDate = LibraryStorage::GetValidDate();

    libraryInventory.CheckOutItem(shelfIndex, compartmentIndex, yourName,
                                  dueDate);
}

void Menu::CheckInItemMenu(LibraryStorage& libraryInventory)
{
    int shelfIndex = LibraryStorage::GetValidShelfIndex();
    int compartmentIndex = LibraryStorage::GetValidCompartmentIndex();

    try
    {
        bool success = libraryInventory.CheckInItem(shelfIndex, compartmentIndex);

        if (success)
        {
            cout << "\nItem at Shelf " << shelfIndex + 1
                << ", Compartment " << compartmentIndex + 1
                << " has been successfully checked in.\n\n";
        }
    }
    catch (const std::exception& e)
    {
        cout << "Error: " << e.what() << endl;
    }
}

void Menu::SwapItemsMenu(LibraryStorage& libraryInventory) {
    cout << "Enter 1st Item's details: \n";

    int shelfIndex1 = LibraryStorage::GetValidShelfIndex();
    int compartmentIndex1 = LibraryStorage::GetValidCompartmentIndex();

    cout << "Enter 2nd Item's details: \n";

    int shelfIndex2 = LibraryStorage::GetValidShelfIndex();
    int compartmentIndex2 = LibraryStorage::GetValidCompartmentIndex();

    try {
        libraryInventory.SwapItems(shelfIndex1, compartmentIndex1, shelfIndex2,
                                   compartmentIndex2);
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}
