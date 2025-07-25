#include <iostream>
#include <string>

using namespace std;

class Item {
public:
    string name;
    int quantity;

    Item() {
        name = "";
        quantity = 0;
    }

    void display() const {
        cout << "Item: " << name << ", Quantity: " << quantity << endl;
    }
};

// Function to search for an item by name
void searchItem(Item items[], int size, const string& searchName) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (items[i].name == searchName) {
            cout << "Found: " << items[i].name << " | Quantity: " << items[i].quantity << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Item not found in inventory." << endl;
    }
}

int main() {
    const int SIZE = 5;
    Item inventory[SIZE];

    // Input items
    cout << "Enter item name and quantity for 5 items:\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << "Item " << i + 1 << " name: ";
        getline(cin, inventory[i].name);
        cout << "Item " << i + 1 << " quantity: ";
        cin >> inventory[i].quantity;
        cin.ignore(); // Clear newline from input buffer
    }

    // Display inventory
    cout << "\n--- Inventory ---\n";
    for (int i = 0; i < SIZE; ++i) {
        inventory[i].display();
    }

    // Search for an item
    string searchName;
    cout << "\nEnter item name to search for: ";
    getline(cin, searchName);

    searchItem(inventory, SIZE, searchName);

    return 0;
}
