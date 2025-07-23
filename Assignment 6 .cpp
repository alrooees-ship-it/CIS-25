#include <iostream>
#include <fstream>  // For I/O
#include <string>
using namespace std;

class Item {
public:
    string name;
    int quantity;

    // Method to save item data to a file
    void saveToFile() {
        ofstream outFile("items.txt"); // Open file for writing
        if (outFile.is_open()) {
            outFile << name << "," << quantity << endl;
            outFile.close();
            cout << "Item saved to file.\n";
        } else {
            cout << "Error opening file.\n";
        }
    }

    // (Optional) Method to load and display data from the file
    void loadFromFile() {
        ifstream inFile("items.txt"); // Open file for reading
        string line;
        if (inFile.is_open()) {
            while (getline(inFile, line)) {
                cout << "Data from file: " << line << endl;
            }
            inFile.close();
        } else {
            cout << "Error reading file.\n";
        }
    }
};

int main() {
    // Create an instance of Item
    Item myItem;

    // Assign values
    myItem.name = "Milk";
    myItem.quantity = 2;

    // Save item data to file
    myItem.saveToFile();

    // (Optional) Read from file
    myItem.loadFromFile();

    return 0;
}
