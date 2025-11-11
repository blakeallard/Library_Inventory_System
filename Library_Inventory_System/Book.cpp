#include "Book.h"

Book::Book()
{
    title  = "";
    author = "";
    crDate = "";
}

void Book::display() const
{

}

unique_ptr<Item> Book::CreateItem() const
{
    return make_unique<Book>(*this);
}

Book::~Book()
{

}
