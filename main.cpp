#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

struct Expense {
    string category;
    double amount;
    string description;
};

vector<Expense> expenses;

void addExpense() {
    Expense e;

    cout << "\nEnter category: ";
    cin >> e.category;

    cout << "Enter amount: ";
    while (!(cin >> e.amount) || e.amount < 0) {
        cout << "Invalid amount. Enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter description: ";
    cin.ignore();
    getline(cin, e.description);

    expenses.push_back(e);

    cout << "\nExpense added successfully!\n";
}

void listExpenses() {
    if (expenses.empty()) {
        cout << "\nNo expenses recorded.\n";
        return;
    }

    cout << "\n--- Expense List ---\n";

    for (size_t i = 0; i < expenses.size(); ++i) {
        cout << i + 1 << ". "
             << "Category: " << expenses[i].category
             << " | Amount: " << fixed << setprecision(2)
             << expenses[i].amount
             << " | Description: " << expenses[i].description
             << '\n';
    }
}

void showTotal() {
    double total = 0;

    for (const auto& e : expenses) {
        total += e.amount;
    }

    cout << "\nOverall Total: ₹"
         << fixed << setprecision(2) << total << '\n';
}

int main() {
    int choice;

    while (true) {
        cout << "\n===== C++ Expense Tracker =====\n";
        cout << "1. Add Expense\n";
        cout << "2. List Expenses\n";
        cout << "3. Show Overall Total\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addExpense();
                break;

            case 2:
                listExpenses();
                break;

            case 3:
                showTotal();
                break;

            case 4:
                cout << "\nThank you for using Expense Tracker!\n";
                return 0;

            default:
                cout << "Invalid choice. Please select 1-4.\n";
        }
    }

    return 0;
}
