// Inventory Manager

# include <iostream> 
using namespace std;

# include "Item.h"
# include "Interaction.h"

int main()
{   
    
    welcome();

    addItem();

    viewInventory();

    // the program will stay in this field of statements forever so that user can keep adding/removing items
    while (main) {
        askToAdd();

        viewInventory();

        askToRem();

        viewInventory();
    }
    
    return 0;
}
