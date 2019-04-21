// Item member functions definition

# include <string>
# include <iomanip>
# include <iostream>
using namespace std;

# include "Item.h"

// Default constructor
Item::Item() 
{
    name = "No Name";
    quantity = 0;
    weight = 0.00;
    price =  0.00;
    id = 0;
}

// this function sets the objects' important information
void Item::setAll(string itemName, int itemQuantity, double itemPrice, double itemWeight)
{
    name = itemName;
    quantity = itemQuantity;
    price = itemPrice;
    weight = itemWeight;
    id = SetID;
    ++ SetID; // changes ID for each new object
}

// Define + initialize static data member
int Item::SetID = 10000;

// Sets the item's name
void Item::SetName(string itemName) {
    name = itemName;
}

// Gets the item's name
string Item::GetName() {
    return name;
}

// Sets the item's quantity
void Item::SetQuantity(int itemQuantity) {
    quantity = itemQuantity;
}

// Sets the item's price
void Item::SetPrice(double itemPrice) {
    price = itemPrice;
    // the below command sets precision to 2 digits after decimal point
    cout << fixed << setprecision(2);
} 

// Sets the item's weight
void Item::SetWeight(double itemWeight) {
    weight = itemWeight;
}

// Gets the item's unique ID
int Item::GetID() {
    return id;
}

// Prints out all item information
void Item::Print() const {
    cout << "NAME:        '" << name << "'" << endl;
    cout << "QUANTITY:    " << quantity << endl;
    cout << "PRICE:       " << price << endl;
    cout << "WEIGHT(lbs): " << weight << endl;
    cout << "ID:          " << id << endl << endl;
}


