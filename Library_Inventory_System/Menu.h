
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
    PRINT_ITEMS     = 4,
    PRINT_STORAGE   = 5,
    PRINT_CHECKEDOUT= 6,
    SWAP_ITEMS      = 7,
    EXIT            = 8
};

class Menu
{
public:
    static void DisplayMenu();
    static void AddItemMenu();
    static void CheckOutItemMenu(LibraryStorage& libraryInventory);
    static void CheckInItemMenu(LibraryStorage& libraryInventory);
    static void PrintItemsMenu();
    static void PrintStorageMenu();
    static void PrintCheckedOutItemsMenu();
    static void SwapItemsMenu();

private:
    bool IsValidDate(const string& date);
};

#endif  // MENU_H_