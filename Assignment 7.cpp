#include <iostream>
using namespace std;

// Abstract base class
class Item {
public:
    // Pure virtual function (makes this class abstract)
    virtual void display() = 0;
};

// Derived class: Perishable
class Perishable : public Item {
public:
    void display() override {
        cout << "Perishable Item" << endl;
    }
};

// Derived class: NonPerishable
class NonPerishable : public Item {
public:
    void display() override {
        cout << "Non-Perishable Item" << endl;
    }
};

int main() {
    // Create derived objects
    Perishable perishableItem;
    NonPerishable nonPerishableItem;

    // Use base class pointer
    Item* itemPtr;

    
    itemPtr = &perishableItem;
    itemPtr->display();  // Output: Perishable Item

    itemPtr = &nonPerishableItem;
    itemPtr->display();  // Output: Non-Perishable Item

    return 0;
}
