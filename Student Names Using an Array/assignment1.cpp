#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 100;

// Display all student names
void displayStudents(string students[], int size) {
    cout << "\nStudent names:\n";

for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << students[i] << endl;
    }
}

// Insert a student at a given position
void insertStudent(string students[], int& size, string name, int position) {
    if (size == MAX_SIZE) {
        cout << "Array is full. Insertion not possible.\n";
        return;
    }

if (position < 0 || position > size) {
        cout << "Invalid position.\n";
        return;
    }

// Shift elements one position to the right
    for (int i = size; i > position; i--) {
        students[i] = students[i - 1];
    }

students[position] = name;
    size++;

cout << "Student inserted successfully.\n";
}

// Delete a student from a given position
void deleteStudent(string students[], int& size, int position) {
    if (size == 0) {
        cout << "Array is empty. Deletion not possible.\n";
        return;
    }

if (position < 0 || position >= size) {
        cout << "Invalid position.\n";
        return;
    }

// Shift elements one position to the left
    for (int i = position; i < size - 1; i++) {
        students[i] = students[i + 1];
    }

size--;

cout << "Student deleted successfully.\n";
}

int main() {
    string students[MAX_SIZE];
    int size = 0;
    int choice;

do {
        cout << "\n===== Student Array Menu =====\n";
        cout << "1. Insert student\n";
        cout << "2. Delete student\n";
        cout << "3. Display students\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

switch (choice) {
            case 1: {
                string name;
                int position;

cout << "Enter student name: ";
                cin >> name;

cout << "Enter position from 1 to " << size + 1 << ": ";
                cin >> position;

insertStudent(students, size, name, position - 1);
                break;
            }

case 2: {
                int position;

if (size == 0) {
                    cout << "No students available.\n";
                    break;
                }

cout << "Enter position from 1 to " << size << ": ";
                cin >> position;

deleteStudent(students, size, position - 1);
                break;
            }

case 3:
                displayStudents(students, size);
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
