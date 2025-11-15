#include "Menu.h"
#include "Book.h"
#include "Movie.h"
#include "Magazine.h"

void Menu::DisplayMenu()
{
    std::cout << "=== Library Inventory System Menu ===\n";
    std::cout << "1. Add Item\n";
    std::cout << "2. Check Out Item\n";
    std::cout << "3. Check In Item\n";
    std::cout << "4. Print Items In Storage\n";
    std::cout << "5. Print Storage\n";
    std::cout << "6. Print Checked Out Items\n";
    std::cout << "7. Swap Items\n";
    std::cout << "8. Exit\n";
    std::cout << "Please select an option (1-8): ";
}

void Menu::AddItemMenu()
{
    // Implementation for adding an item
}

void Menu::CheckOutItemMenu(LibraryStorage& libraryInventory)
{
    int shelfIndex{};
    int compartmentIndex{};
    string yourName{};
    string dueDate{};
    bool validName{};
    bool validDate{};

    // shelf index validation
    do
    {
        cout << "Enter shelf index: ";
        cin  >> shelfIndex;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            shelfIndex = -1;
        }
        else if (shelfIndex < 0 || shelfIndex >= LibraryStorage::NUM_SHELVES)
        {
            cout << "Invalid shelf index. Please try again." << endl;
        }
    } while (shelfIndex < 0 || shelfIndex >= LibraryStorage::NUM_SHELVES);

    // compartment index validation
    do
    {
        cout << "Enter compartment index: ";
        cin  >> compartmentIndex;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            compartmentIndex = -1;
        }
        else if (compartmentIndex < 0 || compartmentIndex >= Shelf::NUM_COMPARTS)
        {
            cout << "Invalid compartment index. Please try again." << endl;
        }
    } while (compartmentIndex < 0 || compartmentIndex >= Shelf::NUM_COMPARTS);

    cin.ignore(10000, '\n');

    // name validation, only characters and spaces
    do
    {
        cout << "Enter your name: ";
        getline(cin, yourName);

        validName = true;

        if (yourName.empty())
        {
            cout << "Name cannot be empty." << endl;
            validName = false;
        }

        else
        {
            for (char c : yourName)
            {
                if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ')) 
                {
                    cout << "Name can only contain alphabetic characters and spaces." << endl;
                    validName = false;
                    break;
                }
            }
        }
    } while (!validName);
    
    do
    {
        cout << "Enter due date (MM/DD/YYYY): ";
        getline(cin, dueDate);
        
        validDate = true;  // Assume valid, then check
        
        // Check format
        if (dueDate.length() != 10 || dueDate[2] != '/' || dueDate[5] != '/')
        {
            cout << "Invalid date format. Please use MM/DD/YYYY." << endl;
            validDate = false;
            continue;
        }
        
        // Check if month digits are valid (positions 0 and 1)
        if (dueDate[0] < '0' || dueDate[0] > '9' || dueDate[1] < '0' || dueDate[1] > '9') 
        {
            cout << "Invalid date. Month must be numbers.\n";
            validDate = false;
        }
        // Check if day digits are valid (positions 3 and 4)
        else if (dueDate[3] < '0' || dueDate[3] > '9' || dueDate[4] < '0' || dueDate[4] > '9') 
        {
            cout << "Invalid date. Day must be numbers.\n";
            validDate = false;
        }
        // Check if year digits are valid (positions 6, 7, 8, 9)
        else if (dueDate[6] < '0' || dueDate[6] > '9' || dueDate[7] < '0' || dueDate[7] > '9' ||
                dueDate[8] < '0' || dueDate[8] > '9' || dueDate[9] < '0' || dueDate[9] > '9') 
        {
                    cout << "Invalid date. Year must be numbers.\n";
                    validDate = false;
                }
        
        if (!validDate) continue;  // Skip stoi if digits invalid
        
        // Convert to integers
        string monthStr = dueDate.substr(0, 2);
        string dayStr   = dueDate.substr(3, 2);
        string yearStr  = dueDate.substr(6, 4);
        
        int month = stoi(monthStr);
        int day   = stoi(dayStr);
        int year  = stoi(yearStr);
        
        // Validate ranges
        if (month < 1 || month > 12)
        {
            cout << "Invalid month. Please enter a month between 01 and 12." << endl;
            validDate = false;
        }
        else if (day < 1 || day > 31)
        {
            cout << "Invalid day. Please enter a day between 01 and 31." << endl;
            validDate = false;
        }
        else if (year < 2025) 
        {
            cout << "Invalid year. Please enter a year of 2025 or later." << endl;
            validDate = false;
        }
        
    } while (!validDate);
    
    libraryInventory.CheckOutItem(shelfIndex, compartmentIndex, yourName, dueDate);
}

void Menu::CheckInItemMenu(LibraryStorage& libraryInventory)
{
    int shelfIndex{};
    int compartmentIndex{};

    // shelf index validation
    do
    {
        cout << "Enter shelf index: ";
        cin  >> shelfIndex;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            shelfIndex = -1;
        }
        else if (shelfIndex < 0 || shelfIndex >= LibraryStorage::NUM_SHELVES)
        {
            cout << "Invalid shelf index. Please try again." << endl;
        }
    } while (shelfIndex < 0 || shelfIndex >= LibraryStorage::NUM_SHELVES);

    // compartment index validation
    do
    {
        cout << "Enter compartment index: ";
        cin  >> compartmentIndex;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            compartmentIndex = -1;
        }
        else if (compartmentIndex < 0 || compartmentIndex >= Shelf::NUM_COMPARTS)
        {
            cout << "Invalid compartment index. Please try again." << endl;
        }
    } while (compartmentIndex < 0 || compartmentIndex >= Shelf::NUM_COMPARTS);

   libraryInventory.CheckInItem(shelfIndex, compartmentIndex);
}

void Menu::PrintItemsMenu()
{
    // Implementation for printing items
}

void Menu::PrintStorageMenu()
{
    // Implementation for printing storage
}

void Menu::PrintCheckedOutItemsMenu()
{
    // Implementation for printing checked out items
}

void Menu::SwapItemsMenu()
{
    // Implementation for swapping items
}