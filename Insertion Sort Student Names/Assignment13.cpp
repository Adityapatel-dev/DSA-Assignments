#include <iostream>
#include <string>
using namespace std;

void insertionSort(string names[], int n) {
    for (int i = 1; i < n; i++) {
        string key = names[i];
        int j = i - 1;

while (j >= 0 && names[j] > key) {
            names[j + 1] = names[j];
            j--;
        }

names[j + 1] = key;
    }
}

int main() {
    int n;

cout << "Enter number of students: ";
    cin >> n;

string* names = new string[n];

for (int i = 0; i < n; i++) {
        cout << "Enter student name " << i + 1 << ": ";
        cin >> names[i];
    }

insertionSort(names, n);

cout << "Names in alphabetical order:\n";

for (int i = 0; i < n; i++) {
        cout << names[i] << endl;
    }

delete[] names;
    return 0;
}
