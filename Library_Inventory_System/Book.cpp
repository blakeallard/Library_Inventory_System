#include "Book.h"

Book::Book(const string& title, const string& author,
           const string& descript, const string& id, const string& crDate)
    : Item("Book", descript, id)
{
    this->title  = title;
    this->author = author;
    this->crDate = crDate;
}

void Book::display(ostream& os) const 
{
    os << "=== BOOK ===\n";
    Item::display(os);
    os << "Title: "         << title  << "\n";
    os << "Author: "        << author << "\n";
    os << "Creation Date: " << crDate << "\n";
}

string Book::GetType() const { return "Book"; }

string Book::GetTitle() const { return title; }