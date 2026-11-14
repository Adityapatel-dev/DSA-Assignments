#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* next;

Node(string studentName) {
        name = studentName;
        next = nullptr;
    }
};

void insert(Node*& head, string name) {
    Node* newNode = new Node(name);

if (head == nullptr) {
        head = newNode;
        return;
    }

Node* temp = head;

while (temp->next != nullptr) {
        temp = temp->next;
    }

temp->next = newNode;
}

void display(Node* head) {
    while (head != nullptr) {
        cout << head->name << " ";
        head = head->next;
    }

cout << endl;
}

Node* mergeLists(Node* first, Node* second) {
    if (first == nullptr) {
        return second;
    }

Node* temp = first;

while (temp->next != nullptr) {
        temp = temp->next;
    }

temp->next = second;
    return first;
}

int main() {
    Node* classA = nullptr;
    Node* classB = nullptr;

int n, m;
    string name;

cout << "Enter number of students in Class A: ";
    cin >> n;

for (int i = 0; i < n; i++) {
        cout << "Enter name: ";
        cin >> name;
        insert(classA, name);
    }

cout << "\nEnter number of students in Class B: ";
    cin >> m;

for (int i = 0; i < m; i++) {
        cout << "Enter name: ";
        cin >> name;
        insert(classB, name);
    }

Node* mergedList = mergeLists(classA, classB);

cout << "\nMerged student list: ";
    display(mergedList);

return 0;
}
