/*
 Features of the Program:
Binary Search Tree (BST) implementation

Insertion, Deletion, and Search

Inorder, Preorder, and Postorder traversal

Finding:

Height of the tree

Diameter of the tree (longest path)

Lowest Common Ancestor (LCA)

Level order traversal using queue

Mirror image of the tree


*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Insert a node in BST
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// Inorder traversal (LNR)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder traversal (NLR)
void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal (LRN)
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Level Order Traversal
void levelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

// Search a key
bool search(Node* root, int key) {
    if (!root) return false;
    if (root->data == key) return true;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

// Find height of the tree
int height(Node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

// Find diameter of the tree (naive O(n^2))
int diameter(Node* root) {
    if (!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    int d1 = lh + rh + 1;
    int d2 = diameter(root->left);
    int d3 = diameter(root->right);
    return max(d1, max(d2, d3));
}

// Lowest Common Ancestor (LCA) in BST
Node* LCA(Node* root, int n1, int n2) {
    if (!root) return nullptr;
    if (root->data > max(n1, n2)) return LCA(root->left, n1, n2);
    if (root->data < min(n1, n2)) return LCA(root->right, n1, n2);
    return root;
}

// Mirror the binary tree
void mirror(Node* root) {
    if (!root) return;
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}

// Delete a node from BST
Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Node with two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Driver code
int main() {
    Node* root = nullptr;
    vector<int> values = { 20, 10, 30, 5, 15, 25, 35, 2, 7 };

    for (int val : values)
        root = insert(root, val);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << "\nPreorder Traversal: ";
    preorder(root);
    cout << "\nPostorder Traversal: ";
    postorder(root);
    cout << "\nLevel Order Traversal: ";
    levelOrder(root);

    cout << "\n\nHeight of tree: " << height(root);
    cout << "\nDiameter of tree: " << diameter(root);

    int key = 15;
    cout << "\nSearch " << key << ": " << (search(root, key) ? "Found" : "Not Found");

    int n1 = 2, n2 = 7;
    Node* lca = LCA(root, n1, n2);
    cout << "\nLowest Common Ancestor of " << n1 << " and " << n2 << ": " << (lca ? lca->data : -1);

    cout << "\n\nMirror Image (Inorder): ";
    mirror(root);
    inorder(root);

    cout << "\n\nDeleting 10...\n";
    root = deleteNode(root, 10);
    cout << "Inorder after deletion: ";
    inorder(root);

    return 0;
}
