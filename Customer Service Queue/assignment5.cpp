#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<string> customers;
    int choice;
    string name;

do {
        cout << "\n===== Customer Service Queue =====\n";
        cout << "1. Add customer\n";
        cout << "2. Serve customer\n";
        cout << "3. Display customers\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

switch (choice) {
            case 1:
                cout << "Enter customer name: ";
                cin >> name;

customers.push(name);
                cout << "Customer joined the queue.\n";
                break;

case 2:
                if (customers.empty()) {
                    cout << "Queue is empty.\n";
                } else {
                    cout << "Serving: " << customers.front() << endl;
                    customers.pop();
                }
                break;

case 3:
                if (customers.empty()) {
                    cout << "Queue is empty.\n";
                } else {
                    queue<string> copy = customers;

cout << "Customers in queue:\n";

while (!copy.empty()) {
                        cout << copy.front() << endl;
                        copy.pop();
                    }
                }
                break;

case 0:
                cout << "Program ended.\n";
                break;

default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

return 0;
}
