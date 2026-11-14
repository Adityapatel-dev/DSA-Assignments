#include <iostream>
#include <string>
using namespace std;

struct Node {
    int rollNumber;
    string name;
    float marks;
    Node* next;

Node(int roll, string studentName, float studentMarks) {
        rollNumber = roll;
        name = studentName;
        marks = studentMarks;
        next = nullptr;
    }
};

void insertRecord(Node*& head) {
    int roll;
    string name;
    float marks;

cout << "Enter roll number: ";
    cin >> roll;

cout << "Enter name: ";
    cin >> name;

cout << "Enter marks: ";
    cin >> marks;

Node* newNode = new Node(roll, name, marks);

if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;

while (temp->next != nullptr) {
            temp = temp->next;
        }

temp->next = newNode;
    }

cout << "Record inserted successfully.\n";
}

void deleteRecord(Node*& head) {
    int roll;
    cout << "Enter roll number to delete: ";
    cin >> roll;

if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

if (head->rollNumber == roll) {
        Node* temp = head;
        head = head->next;
        delete temp;

cout << "Record deleted.\n";
        return;
    }

Node* current = head;

while (current->next != nullptr &&
           current->next->rollNumber != roll) {
        current = current->next;
    }

if (current->next == nullptr) {
        cout << "Record not found.\n";
    } else {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;

cout << "Record deleted.\n";
    }
}

void displayRecords(Node* head) {
    if (head == nullptr) {
        cout << "No records available.\n";
        return;
    }

cout << "\nStudent Records:\n";

while (head != nullptr) {
        cout << "Roll Number: " << head->rollNumber << endl;
        cout << "Name: " << head->name << endl;
        cout << "Marks: " << head->marks << endl;
        cout << "-------------------\n";

head = head->next;
    }
}

int main() {
    Node* head = nullptr;
    int choice;

do {
        cout << "\n1. Insert record\n";
        cout << "2. Delete record\n";
        cout << "3. Display records\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

switch (choice) {
            case 1:
                insertRecord(head);
                break;

case 2:
                deleteRecord(head);
                break;

case 3:
                displayRecords(head);
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
