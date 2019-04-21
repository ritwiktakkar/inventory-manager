// functions for interaction in main()

#ifndef INTERACTION_H
#define INTERACTION_H

# include <string>
# include <iostream>
# include <vector>
using namespace std;

# include "Item.h" // including class header file to get access to data members + objects

// declaring variables to be used in this file
string _name, userAnsToAdd, userAnsToRem, remItem;
int _quantity, userAdd; 
double _weight;
double _price;
unsigned int i;
vector<Item> itemList;

// this function sizes the vector containing objects to the initial size specified by the user
void welcome() {
    cout << "Welcome to my inventory management system!" << endl << endl;
    cout << "Let's add some items. ";
    cout << "How many items would you like to add? ";
    cin >> userAdd;
    itemList.resize(userAdd);
}

// this is a troubleshooting function used to check and ensure the vector size is right
void view() {
    cout << "vector size is: " << itemList.size();
}

// this function adds the items to the inventory based on initial interaction
void addItem() {
    for (i=0; i < userAdd; ++i) {
        cout << endl << "Enter the following information pertaining to item #" << i+1 << ": ";
        cout << "\nNAME (ex. MacBook): ";
        cin.ignore();
        getline(cin, _name);
        cout << "QUANTITY (ex. 5): ";
        cin >> _quantity;
        cout << "PRICE (ex. 3.99): ";
        cin >> _price;
        cout << "WEIGHT (lbs) (ex. 25.6): ";
        cin >> _weight;
        cout << endl;
        itemList.at(i).setAll(_name, _quantity, _price, _weight);
    } 
}

// this function adds item(s) to the inventory after the user has been asked if they would like to add extra
void addItemOAT() {
    cout << "How many items would you like to add? ";
    cin >> userAdd;
    itemList.resize(userAdd+itemList.size());
    // the for loop below begins the indexing in a manner that causes new objects to be placed at the end of the existing vector from the initial interaction
    for (i=(itemList.size()-userAdd); i < itemList.size(); ++i) {
        cout << endl << "Enter the following information pertaining to item #" << i+1 << ": ";
        cout << "\nNAME (ex. MacBook): ";
        cin.ignore();
        getline(cin, _name);
        cout << "QUANTITY (ex. 5): ";
        cin >> _quantity;
        cout << "PRICE (ex. 3.99): ";
        cin >> _price;
        cout << "WEIGHT (lbs) (ex. 25.6): ";
        cin >> _weight;
        cout << endl;
        itemList.at(i).setAll(_name, _quantity, _price, _weight);
    }
} 

// this function is used to remove items from the item with name matching user input
void remItemOAT() {
    cout << "Type the name of the item you would like to remove: ";
    cin.ignore();
    getline(cin, remItem);
    cout << "Nothing will happen if the item you typed isn't in the inventory." << endl;
    for (i=0; i<itemList.size(); ++i) {
        if (remItem == itemList.at(i).GetName()) {
            itemList.erase(itemList.begin()+i);
        }
    }
}

// this function calls Print() from the Item.h file and prints current inventory + 
void viewInventory() {
    cout << "-------------------------" << endl;
    cout << "Here is your current inventory: " << endl << endl;
    for (i=0; i < itemList.size(); ++i) {
        itemList.at(i).Print();
        cout << endl;
    }
    cout << "-------------------------" << endl;
    cout << itemList.size() << " DIFFERENT TYPES OF ITEMS" << endl << endl;
} 

// this function asks the user if they would like to add items to the inventory and adds it by calling the add function
void askToAdd() {
    cout << "Would you like to add item(s)? Type 'y' if yes, or 'n' if not: ";
    cin >> userAnsToAdd;
    while (userAnsToAdd != "n") {
        addItemOAT();
        cout << "Would you like to add another item? Type 'y' if yes, or 'n' if not: ";
        cin >> userAnsToAdd;
    }
}

// this function asks if the user wants to remove anything from the inventory and removes it by calling the remove function
void askToRem() {
    cout << "Would you like to remove item(s)? Type 'y' if yes, or 'n' if not: ";
    cin >> userAnsToRem;
    while (userAnsToRem != "n") {
        remItemOAT();
        cout << "Would you like to remove another item? Type 'y' if yes, or 'n' if not: ";
        cin >> userAnsToRem;
    }
}


# endif