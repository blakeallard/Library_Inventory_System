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

void Compartment::CheckIn()
{


}

void Compartment::CheckOut()
{

}

bool Compartment::IsEmpty() const
{
    return item == nullptr;
}