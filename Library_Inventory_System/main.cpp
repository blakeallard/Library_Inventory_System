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
    
    // Create sample data
    libraryInventory.InitSampleData();
    
    do
    {
        Menu::DisplayMenu();
        cin >> choice;
        cin.ignore(10000, '\n');

        switch (choice)
        {
            case ADD_ITEM:
                cout << "\nAdd Item selected.\n";
                Menu::AddItemMenu(libraryInventory);
                break;
            case CHECK_OUT_ITEM:
                cout << "\nCheck Out Item selected.\n";
                Menu::CheckOutItemMenu(libraryInventory);
                break;
            case CHECK_IN_ITEM:
                cout << "\nCheck In Item selected.\n";
                Menu::CheckInItemMenu(libraryInventory);
                break;
            case PRINT_STORAGE:
                cout << "\nPrint Storage selected.\n";
                libraryInventory.PrintStorage();
                break;
            case PRINT_CHECKEDOUT:
                cout << "\nPrint Checked Out Items selected.\n";
                libraryInventory.PrintCheckedOutItems();
                break;
            case SWAP_ITEMS:
                cout << "\nSwap Items selected.\n";
                Menu::SwapItemsMenu(libraryInventory);
                break;
            case EXIT:
                cout << "\nExiting the program.\n";
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    } while (choice != EXIT);

    return 0;
}