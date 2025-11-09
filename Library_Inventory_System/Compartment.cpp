#include "Compartment.h"
#include "Item.h"


Compartment::Compartment()
{
    item         = nullptr;
    checkedOutBy = "";
    dueDate      = "";
}


void Compartment::AddItem(const Item& newItem)
{

}
void Compartment::RemoveItem()
{

}

void Compartment::CheckOut()
{

}

void Compartment::CheckIn()
{

}

bool Compartment::IsEmpty()
{
    return item == nullptr;
}