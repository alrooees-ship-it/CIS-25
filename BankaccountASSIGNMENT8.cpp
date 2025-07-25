#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class BankAccount {
private:
    double balance;
    string filename = "transactions.txt";

    void saveTransaction(const string& action, double amount) {
        ofstream file(filename, ios::app); // Open file in append mode
        if (file.is_open()) {
            file << action << ": $" << amount << " | New Balance: $" << balance << endl;
            file.close();
        } else {
            cout << "Unable to open transaction file." << endl;
        }
    }

public:
    BankAccount() {
        balance = 0.0;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited $" << amount << endl;
        saveTransaction("Deposit", amount);
    }

    void makePurchase(const string& description, double amount) {
        if (amount > balance) {
            cout << "Insufficient funds for: " << description << endl;
        } else {
            balance -= amount;
            cout << "Purchase: " << description << " - $" << amount << endl;
            saveTransaction("Purchase - " + description, amount);
        }
    }

    void printBalance() const {
        cout << "Current Balance: $" << balance << endl;
    }
};

int main() {
    BankAccount myAccount;

    myAccount.deposit(100.0); // Initial deposit
    myAccount.makePurchase("Groceries", 25.50);
    myAccount.makePurchase("Books", 40.75);

    myAccount.printBalance();

    return 0;
}
