#include "LibraryStorage.h"
#include "Magazine.h"
#include "Book.h"
#include "Movie.h"
#include "Menu.h"
using std::cin;

int main()
{
    LibraryStorage libraryInventory;
    int choice{};
    
    // Create items
    libraryInventory.InitSampleData();
    
    do
    {
        Menu::DisplayMenu();
        cin >> choice;
        cin.ignore(10000, '\n');

        switch (choice)
        {
            case ADD_ITEM:
                cout << "Add Item selected.\n";
                Menu::AddItemMenu(libraryInventory);
                break;
            case CHECK_OUT_ITEM:
                cout << "Check Out Item selected.\n";
                Menu::CheckOutItemMenu(libraryInventory);
                break;
            case CHECK_IN_ITEM:
                cout << "Check In Item selected.\n";
                Menu::CheckInItemMenu(libraryInventory);
                break;
            case PRINT_STORAGE:
                cout << "Print Storage selected.\n";
                libraryInventory.PrintStorage();
                break;
            case PRINT_CHECKEDOUT:
                cout << "Print Checked Out Items selected.\n";
                libraryInventory.PrintCheckedOutItems();
                break;
            case SWAP_ITEMS:
                cout << "Swap Items selected.\n";
                Menu::SwapItemsMenu(libraryInventory);
                break;
            case EXIT:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != EXIT);

    return 0;
}