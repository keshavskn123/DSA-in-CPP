#include<iostream>
#include<bits/stdc++.h>
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

int totalLevels(Node* root) {
    if(root==NULL) return 0;
    // 1 level is always for root node in the tree
    int leftLevel = totalLevels(root->left);
    int rightLevel = totalLevels(root->right);  
    int totalLevels = 1 + max(leftLevel, rightLevel);
    return totalLevels; 
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
    cout << totalLevels(a);
}

// Height of Tree = Level - 1