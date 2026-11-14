#include <iostream>
using namespace std;

void bubbleSort(int marks[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

for (int j = 0; j < n - i - 1; j++) {
            if (marks[j] > marks[j + 1]) {
                swap(marks[j], marks[j + 1]);
                swapped = true;
            }
        }

if (!swapped) {
            break;
        }
    }
}

int main() {
    int n;

cout << "Enter number of students: ";
    cin >> n;

int* marks = new int[n];

for (int i = 0; i < n; i++) {
        cout << "Enter marks of student " << i + 1 << ": ";
        cin >> marks[i];
    }

bubbleSort(marks, n);

cout << "Marks in ascending order:\n";

for (int i = 0; i < n; i++) {
        cout << marks[i] << " ";
    }

delete[] marks;
    return 0;
}
