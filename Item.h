// Item class declaration

#ifndef ITEM_H
#define ITEM_H

# include <string>
using namespace std;

// Declaring the class: Items
class Item {
    // public access specifier contains functions that can be used outside class
    public:
        Item();
        void setAll(string itemName, int itemQuantity, double itemPrice, double itemWeight);
        bool SetEntOrEx(string enOrEx);
        void SetName(string itemName);
        string GetName();
        void SetQuantity(int itemQuantity);
        void SetPrice(double itemPrice);
        void SetWeight(double itemWeight);
        int GetID();
        static int SetID;
        void Print() const;
    // private access specifier contains data members that can NOT be used outside class definition
    private:
        string enter, name;
        double price, weight;
        int id = 0, quantity;
};

# endif