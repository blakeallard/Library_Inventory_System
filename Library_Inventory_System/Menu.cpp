#include "Menu.h"

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
        cin.ignore(10000, '\n');

        if (itemTypeChoice < 1 || itemTypeChoice > 3)
        {
            cout << "Invalid choice. Please enter a number between 1 - 3: ";
        }
    } while (itemTypeChoice < 1 || itemTypeChoice > 3);

    
    cout << "Enter add location for the item:\n";
    int shelfIndex       = GetValidShelfIndex();
    int compartmentIndex = GetValidCompartmentIndex();

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
    int shelfIndex = GetValidShelfIndex();
    int compartmentIndex = GetValidCompartmentIndex();
    string yourName = GetValidName();
    string dueDate = GetValidDate();

    libraryInventory.CheckOutItem(shelfIndex, compartmentIndex, yourName,
                                  dueDate);
}



void Menu::SwapItemsMenu(LibraryStorage& libraryInventory) {
    cout << "Enter 1st Item's details: \n";

    int shelfIndex1 = GetValidShelfIndex();
    int compartmentIndex1 = GetValidCompartmentIndex();

    cout << "Enter 2nd Item's details: \n";

    int shelfIndex2 = GetValidShelfIndex();
    int compartmentIndex2 = GetValidCompartmentIndex();

    try {
        libraryInventory.SwapItems(shelfIndex1, compartmentIndex1, shelfIndex2,
                                   compartmentIndex2);
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

int Menu::GetValidShelfIndex() {
    int shelfIndex{};
    // shelf index validation
    do {
        cout << "Enter shelf index: ";
        cin >> shelfIndex;
        shelfIndex--;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            shelfIndex = -1;
        } else if (shelfIndex < 0 ||
                   shelfIndex >= LibraryStorage::NUM_SHELVES) {
            cout << "Invalid shelf index. Please try again." << endl;
        }
    } while (shelfIndex < 0 || shelfIndex >= LibraryStorage::NUM_SHELVES);
    return shelfIndex;
}

int Menu::GetValidCompartmentIndex() {
    int compartmentIndex{};

    do {
        cout << "Enter compartment index: ";
        cin >> compartmentIndex;
        compartmentIndex--;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            compartmentIndex = -1;
        } else if (compartmentIndex < 0 ||
                   compartmentIndex >= Shelf::NUM_COMPARTS) {
            cout << "Invalid compartment index. Please try again." << endl;
        }
    } while (compartmentIndex < 0 || compartmentIndex >= Shelf::NUM_COMPARTS);
    cin.ignore(10000, '\n');

    return compartmentIndex;
}

string Menu::GetValidName() {
    string yourName{};
    bool validName = false;

    do {
        validName = true;
        cout << "Enter your name: ";
        getline(cin, yourName);

        if (yourName.empty()) {
            cout << "Name cannot be empty." << endl;
            validName = false;
        }

        else {
            for (char c : yourName) {
                if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
                      c == ' ')) {
                    cout << "Name can only contain alphabetic characters and "
                            "spaces."
                         << endl;
                    validName = false;
                    break;
                }
            }
        }
    } while (!validName);

    return yourName;
}

string Menu::GetValidDate() {
    string dueDate{};
    bool validDate = true;

    do {
        cout << "Enter due date (MM/DD/YYYY): ";
        getline(cin, dueDate);

        validDate = true;

        // Check date format
        if (dueDate.length() != 10 || dueDate[2] != '/' || dueDate[5] != '/') {
            cout << "Invalid date format. Please use MM/DD/YYYY." << endl;
            validDate = false;
            continue;
        }

        // Check if month digits are valid
        if (dueDate[0] < '0' || dueDate[0] > '9' || dueDate[1] < '0' ||
            dueDate[1] > '9') {
            cout << "Invalid date. Month must be numbers.\n";
            validDate = false;
        }
        // Check if day digits are valid
        else if (dueDate[3] < '0' || dueDate[3] > '9' || dueDate[4] < '0' ||
                 dueDate[4] > '9') {
            cout << "Invalid date. Day must be numbers.\n";
            validDate = false;
        }
        // Check if year digits are valid *YYYY*
        else if (dueDate[6] < '0' || dueDate[6] > '9' || dueDate[7] < '0' ||
                 dueDate[7] > '9' || dueDate[8] < '0' || dueDate[8] > '9' ||
                 dueDate[9] < '0' || dueDate[9] > '9') {
            cout << "Invalid date. Year must be numbers.\n";
            validDate = false;
        }

        if (!validDate) continue;  // Skip string to int if digits invalid

        // Convert to integers
        string monthStr = dueDate.substr(0, 2);
        string dayStr = dueDate.substr(3, 2);
        string yearStr = dueDate.substr(6, 4);

        int month = stoi(monthStr);
        int day = stoi(dayStr);
        int year = stoi(yearStr);

        // Validate date ranges
        if (month < 1 || month > 12) {
            cout << "Invalid month. Please enter a month between 01 and 12."
                 << endl;
            validDate = false;
        } else if (day < 1 || day > 31) {
            cout << "Invalid day. Please enter a day between 01 and 31."
                 << endl;
            validDate = false;
        } else if (year < 2025) {
            cout << "Invalid year. Please enter a year of 2025 or later."
                 << endl;
            validDate = false;
        }
    } while (!validDate);
    return dueDate;
}
