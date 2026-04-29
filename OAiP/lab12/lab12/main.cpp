#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
};

struct Tree {
    Node* root;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

int main() {
    setlocale(LC_ALL, "ru");
    Tree tree;
    tree.root = createNode(12);
    return 0;
}
