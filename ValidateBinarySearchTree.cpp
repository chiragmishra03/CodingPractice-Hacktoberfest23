#include <iostream>
#include <climits>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

bool isBSTUtil(Node* root, int minValue, int maxValue) {
    if (root == nullptr) {
        return true; 
    }

    if (root->data < minValue || root->data > maxValue) {
        return false;
    }

    // Recursively check the left and right subtrees
    return isBSTUtil(root->left, minValue, root->data - 1) &&
           isBSTUtil(root->right, root->data + 1, maxValue);
}

bool isBST(Node* root) {
   
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
 
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(18);

    if (isBST(root)) {
        std::cout << "The given binary tree is a Binary Search Tree (BST)." << std::endl;
    } else {
        std::cout << "The given binary tree is NOT a Binary Search Tree (BST)." << std::endl;
    }

    delete root;
    delete root->left;
    delete root->right;

    return 0;
}
