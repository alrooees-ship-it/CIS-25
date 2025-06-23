#include <iostream>
using namespace std;
int main() {
    int choice;
    
    cout << "1. Add Item\t2. View Items\t3. Exit\t";
    cout << "Choose an option: ";
    cin >> choice;

    if (choice == 1) cout << "Item added!\n";
    else if (choice == 2) cout << "Displaying items...\n";
    else if (choice == 3) cout << "Exiting...\n";
    else cout << "Invalid option. Try Again\n";
    return 0;
}