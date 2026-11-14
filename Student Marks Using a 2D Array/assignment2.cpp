#include <iostream>
using namespace std;

int main() {
    const int students = 3;
    const int subjects = 3;

int marks[students][subjects];

for (int i = 0; i < students; i++) {
        cout << "Enter marks for Student " << i + 1 << ":\n";

for (int j = 0; j < subjects; j++) {
            cout << "Subject " << j + 1 << ": ";
            cin >> marks[i][j];
        }
    }

cout << "\nStudent Marks:\n";

for (int i = 0; i < students; i++) {
        cout << "Student " << i + 1 << ": ";

for (int j = 0; j < subjects; j++) {
            cout << marks[i][j] << " ";
        }

cout << endl;
    }

return 0;
}
