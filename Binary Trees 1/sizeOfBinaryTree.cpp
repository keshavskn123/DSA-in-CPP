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

void displayTree(Node* root) {      // Using Recursion
    if(root == NULL) return;        // Base Case
    cout << root->val << " ";
    displayTree(root->left);        // left call/ Recursion
    displayTree(root->right);        // right call/ Recursion
}

int size(Node* root) {
    if(root == NULL) return 0;      // Base Case 
    int ans = 1 + size(root->left) + size(root->right);
    return ans;
}
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
    displayTree(a);     // 1 2 4 5 3 6 7 
    cout << endl;
    cout << "Size of Tree is : " << size(a);
}

// Number of Edges = Size - 1