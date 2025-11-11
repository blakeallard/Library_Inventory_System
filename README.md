# Library_Inventory_System
# Library Inventory System

Library Inventory System is a C++ console project that models a physical library’s storage. It demonstrates inheritance, polymorphism, operator overloading, and value semantics for a collection of items stored on shelves, checked in/out by patrons, and reported through the CLI.

## Project Structure

```
Library_Inventory_System/
├── Item.h / Item.cpp           # Abstract base type + common metadata/printing helpers
├── Book.*, Magazine.*, Movie.* # Item specializations (title/author/etc.)
├── Compartment.*               # Owns a single Item instance + checkout metadata
├── Shelf.*                     # Fixed-size array (15) of compartments + bounds-checked []
├── LibraryStorage.*            # Vector of shelves + system operations (add/checkout/swap/print)
└── main.cpp                    # Manual test harness exercising the API
```

## Core Concepts

- **Encapsulation of ownership** – `Compartment` stores a `std::unique_ptr<Item>` and clones any incoming `Item` so each compartment truly owns its content.
- **Inheritance** – `Book`, `Magazine`, and `Movie` inherit from `Item` and override `display()` plus `CreateItem()` (polymorphic copy constructor).
- **Operator overloading** – `operator<<` on `Item` streams the common metadata and delegates to each subclass for its extra fields.
- **Safe indexing** – `Shelf::operator[]` and `LibraryStorage::operator[]` validate indices and throw `std::out_of_range` to prevent undefined behavior.
- **Checkout bookkeeping** – Compartments track `checkedOutBy` and `dueDate`, enabling the storage to print both in-library and checked-out inventories.

## Key APIs

```cpp
LibraryStorage::AddItem(int shelfIndex,
                        int compartmentIndex,
                        const Item& item);
LibraryStorage::CheckOutItem(/* location + patron/due */);
LibraryStorage::CheckInItem(/* location */);
LibraryStorage::SwapItems(/* location A, location B */);
LibraryStorage::PrintStorage() const;
LibraryStorage::PrintCheckedOutItems() const;
LibraryStorage::operator[](int index); // direct shelf access
```

Each `Shelf` exposes `operator[](int)` to retrieve a `Compartment`, so callers can chain `storage[shelf][compartment]` to perform fine-grained operations.

## Building and Running

1. From the project root, compile all sources:
   ```bash
   g++ -std=c++17 -Wall -Wextra -pedantic *.cpp -o library_inventory
   ```
2. Execute the program:
   ```bash
   ./library_inventory
   ```

`main.cpp` should be expanded into a proper demo that:
1. Instantiates `LibraryStorage`.
2. Creates several `Book`, `Magazine`, and `Movie` objects.
3. Adds them to different compartments.
4. Demonstrates checkout/check-in flows, swapping, and both reporting functions.

## Testing Checklist

- Add three different item types and verify they print with specialized fields.
- Attempt to add an item to an occupied compartment and confirm the guardrails.
- Check out an item, print checked-out inventory, then check it back in.
- Try invalid indices for shelves/compartments and ensure exceptions are thrown.
- Swap two compartments successfully, then attempt to swap when one slot is empty to verify error messaging.

## Future Enhancements

- Persist inventory to disk (JSON/CSV) to retain state between runs.
- Add date validation utilities to prevent malformed due dates.
- Provide a menu-driven UI or hook up to unit tests (e.g., using Catch2) for automated verification.
- Extend `Item` hierarchy with additional media types (audio books, games, etc.).

## Requirements Recap

- C++17 or newer compiler.
- Standard library only (no external dependencies).
- Follows the UML shown in `docs/` (or project brief) with the additional `CreateItem()` helper to support polymorphic cloning.

Feel free to adapt the testing scaffold in `main.cpp` to automate more scenarios as the system evolves.

