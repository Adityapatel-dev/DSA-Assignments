#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* left;
    Node* right;

Node(string employeeName) {
        name = employeeName;
        left = nullptr;
        right = nullptr;
    }
};

void preorder(Node* root) {
    if (root == nullptr) {
        return;
    }

cout << root->name << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }

inorder(root->left);
    cout << root->name << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) {
        return;
    }

postorder(root->left);
    postorder(root->right);
    cout << root->name << " ";
}

int main() {
    Node* ceo = new Node("CEO");

ceo->left = new Node("Manager A");
    ceo->right = new Node("Manager B");

ceo->left->left = new Node("Employee 1");
    ceo->left->right = new Node("Employee 2");

ceo->right->left = new Node("Employee 3");
    ceo->right->right = new Node("Employee 4");

cout << "Preorder traversal: ";
    preorder(ceo);

cout << "\nInorder traversal: ";
    inorder(ceo);

cout << "\nPostorder traversal: ";
    postorder(ceo);

cout << endl;

return 0;
}
