
#include <iostream>
#include <string>
using namespace std;

struct Node {
    int rollNumber;
    string name;
    Node* left;
    Node* right;

    Node(int roll, string studentName) {
        rollNumber = roll;
        name = studentName;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int roll, string name) {
    if (root == nullptr) {
        return new Node(roll, name);
    }

    if (roll < root->rollNumber) {
        root->left = insert(root->left, roll, name);
    } else {
        root->right = insert(root->right, roll, name);
    }

    return root;
}

Node* search(Node* root, int roll) {
    if (root == nullptr || root->rollNumber == roll) {
        return root;
    }

    if (roll < root->rollNumber) {
        return search(root->left, roll);
    }

    return search(root->right, roll);
}

void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left);
    cout << root->rollNumber << " - " << root->name << endl;
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int roll;
        string name;

        cout << "Enter roll number: ";
        cin >> roll;

        cout << "Enter name: ";
        cin >> name;

        root = insert(root, roll, name);
    }

    cout << "\nStudents in sorted roll-number order:\n";
    inorder(root);

    int rollToSearch;

    cout << "\nEnter roll number to search: ";
    cin >> rollToSearch;

    Node* result = search(root, rollToSearch);

    if (result != nullptr) {
        cout << "Student found: " << result->name << endl;
    } else {
        cout << "Student not found.\n";
    }

    return 0;
}
