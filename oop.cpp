#include <iostream>
#include <vector>
using namespace std;

// Class for Bank Account
class BankAccount {
private:
    int accountNumber;
    string owner;
    double balance;

public:
    // Constructor
    BankAccount(int accNo, string name, double initialBalance = 0) {
        accountNumber = accNo;
        owner = name;
        balance = initialBalance;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited $" << amount << endl;
    }

    void withdraw(double amount) {
        if (amount > balance)
            cout << "Insufficient balance!\n";
        else {
            balance -= amount;
            cout << "Withdrew $" << amount << endl;
        }
    }

    void display() {
        cout << "Account #" << accountNumber
             << ", Owner: " << owner
             << ", Balance: $" << balance << endl;
    }

    int getAccountNumber() { return accountNumber; }
};

int main() {
    vector<BankAccount> accounts;
    int choice;

    do {
        cout << "\n--- Bank Menu ---\n";
        cout << "1. Create Account\n2. Deposit\n3. Withdraw\n4. Display Account\n0. Exit\n";
        cin >> choice;

        if (choice == 1) {
            int accNo;
            string name;
            cout << "Enter account number: "; cin >> accNo;
            cout << "Enter owner name: "; cin >> ws; getline(cin, name);
            accounts.push_back(BankAccount(accNo, name));
            cout << "Account created!\n";
        } 
        else if (choice == 2) {
            int accNo; double amount;
            cout << "Enter account number: "; cin >> accNo;
            cout << "Enter amount to deposit: "; cin >> amount;

            bool found = false;
            for (auto &acc : accounts) {
                if (acc.getAccountNumber() == accNo) {
                    acc.deposit(amount);
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Account not found!\n";
        }
        else if (choice == 3) {
            int accNo; double amount;
            cout << "Enter account number: "; cin >> accNo;
            cout << "Enter amount to withdraw: "; cin >> amount;

            bool found = false;
            for (auto &acc : accounts) {
                if (acc.getAccountNumber() == accNo) {
                    acc.withdraw(amount);
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Account not found!\n";
        }
        else if (choice == 4) {
            int accNo;
            cout << "Enter account number: "; cin >> accNo;

            bool found = false;
            for (auto &acc : accounts) {
                if (acc.getAccountNumber() == accNo) {
                    acc.display();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Account not found!\n";
        }

    } while (choice != 0);

    cout << "Thanks for using the bank!\n";
    return 0;
}