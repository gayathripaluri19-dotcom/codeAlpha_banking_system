#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Transaction {
public:
    string type;
    double amount;

    Transaction(string t, double a) {
        type = t;
        amount = a;
    }
};

class Account {
private:
    int accountNumber;
    double balance;
    vector<Transaction> transactions;

public:
    Account(int accNo) {
        accountNumber = accNo;
        balance = 0;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
        transactions.push_back(Transaction("Deposit", amount));
        cout << "Amount Deposited Successfully!\n";
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient Balance!\n";
            return;
        }
        balance -= amount;
        transactions.push_back(Transaction("Withdrawal", amount));
        cout << "Amount Withdrawn Successfully!\n";
    }

    void transfer(Account &receiver, double amount) {
        if (amount > balance) {
            cout << "Insufficient Balance!\n";
            return;
        }

        balance -= amount;
        receiver.balance += amount;

        transactions.push_back(Transaction("Transfer Sent", amount));
        receiver.transactions.push_back(Transaction("Transfer Received", amount));

        cout << "Transfer Successful!\n";
    }

    void showTransactions() {
        cout << "\nTransaction History:\n";
        for (auto &t : transactions) {
            cout << t.type << " : Rs." << t.amount << endl;
        }
    }

    void showAccountDetails() {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nBalance: Rs." << balance << endl;
    }
};

class Customer {
public:
    string name;
    Account account;

    Customer(string n, int accNo) : account(accNo) {
        name = n;
    }

    void displayCustomer() {
        cout << "\nCustomer Name: " << name << endl;
        account.showAccountDetails();
    }
};

int main() {
    Customer customer1("Gayathri", 1001);
    Customer customer2("Ravi", 1002);

    int choice;
    double amount;

    do {
        cout << "\n===== BANKING SYSTEM =====\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Transfer Funds\n";
        cout << "4. View Account Details\n";
        cout << "5. View Transaction History\n";
        cout << "6. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Amount: ";
            cin >> amount;
            customer1.account.deposit(amount);
            break;

        case 2:
            cout << "Enter Amount: ";
            cin >> amount;
            customer1.account.withdraw(amount);
            break;

        case 3:
            cout << "Enter Amount to Transfer: ";
            cin >> amount;
            customer1.account.transfer(customer2.account, amount);
            break;

        case 4:
            customer1.displayCustomer();
            break;

        case 5:
            customer1.account.showTransactions();
            break;

        case 6:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}