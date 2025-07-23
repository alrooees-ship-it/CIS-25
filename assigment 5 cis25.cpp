#include <iostream>
#include <string>
using namespace std;

// do the struct first
struct Item {
    string name;
    int id;
};

// Binary search function definition to search for ID in the array
int binarySearch(Item* items, int size, int targetId) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (items[mid].id == targetId) {
            return mid;
        } else if (items[mid].id < targetId) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // this is for when the id is Not found
}

int main() {
    // Step 3: Create and fill array using new
    int size = 5;
    Item* items = new Item[size]; // dynamically allocate memory

    // Step 4: Fill array with sorted sample data by ID
    items[0] = {"moisturizer", 101};
    items[1] = {"SPF", 203};
    items[2] = {"Lip balm", 305};
    items[3] = {"eyeshadow", 412};
    items[4] = {"hand lotion", 589};

    // Step 5: Ask user for ID to search
    int searchId;
    cout << "Enter an ID to search for: ";
    cin >> searchId;

    // Step 6: Search for the ID using binary search
    int resultIndex = binarySearch(items, size, searchId);

    // Step 7: Display result
    if (resultIndex != -1) {
        cout << "Item found: " << items[resultIndex].name
             << " (ID: " << items[resultIndex].id << ")" << endl;
    } else {
        cout << "Item with ID " << searchId << " not found." << endl;
    }

    // Step 8: Free memory
    delete[] items;

    return 0;
}

