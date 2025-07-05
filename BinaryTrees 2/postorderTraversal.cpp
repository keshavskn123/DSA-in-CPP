#include<iostream>
using namespace std;
class Node{         // User Defined TreeNode
public:
    // Parameters
    int val;
    Node* left;
    Node* right;
    // Constructor with parametrs
    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void postorder(Node* root) {      // Using Recursion
    if(root == NULL) return;        // Base Case 
    postorder(root->left);                // Left
    postorder(root->right);               // Right
    cout << root->val << " ";           // Root
}

// Pre Order : Work, Call 1 and Call 2
// In Order : Call 1, Work and Call 2
// Post Order : Call 1, Call 2 and Work
// These Preorder, Inorder and Postorder are called DFS(Depth First Search) Traversal

int main() {
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);
    
    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->left = f;
    c->right = g;
    postorder(a);     // 1 2 4 5 3 6 7 
}