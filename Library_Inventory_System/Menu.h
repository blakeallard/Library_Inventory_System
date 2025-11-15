
#ifndef MENU_H_
#define MENU_H_
#include "LibraryStorage.h"
#include <iostream>
using std::cout, std::cin, std::endl, std::getline;
enum MenuOptions
{
    ADD_ITEM        = 1,
    CHECK_OUT_ITEM  = 2,
    CHECK_IN_ITEM   = 3,
    PRINT_STORAGE   = 4,
    PRINT_CHECKEDOUT= 5,
    SWAP_ITEMS      = 6,
    EXIT            = 7
};

class Menu
{
public:
    static void DisplayMenu();
    static void AddItemMenu(LibraryStorage& libraryInventory);
    static void CheckOutItemMenu(LibraryStorage& libraryInventory);
    static void CheckInItemMenu(LibraryStorage& libraryInventory);
    static void SwapItemsMenu(LibraryStorage& libraryInventory);

private:
    // Helper functions for input validation
    static int GetValidShelfIndex();
    static int GetValidCompartmentIndex();
    static string GetValidName();
    static string GetValidDate();
};

#endif  // MENU_H_