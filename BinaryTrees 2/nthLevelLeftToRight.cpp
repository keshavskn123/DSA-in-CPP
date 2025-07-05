// Print all the nodes of Nth level from left to right 

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

void nthLevel(Node* root, int currLevel, int level) {
    // We can use any DFS traversal i.e., Preorder, Inorder or Postorder
    if(root == NULL) return;
    // We are using Prorder Traversal (Left to Right)            -- But we can also use Inorder or Postorder Traversal 
    if(currLevel == level) {
        cout << root->val << " ";       // Work or Root
        return;         // For optimisation as we don't need to call all other higher levels if we already reached the required level i.e., currLevel == level   
    }
    nthLevel(root->left, currLevel+1, level);          // Left Call
    nthLevel(root->right, currLevel+1, level);         // Right Call
}

int levels(Node* root) {
    if(root == NULL) return 0;
    return 1 + max(levels(root->left), levels(root->right));
}

void levelOrder(Node* root) {
    if(root == NULL) return;
    // find number of levels in this tree by using root node sent into levels() function
    int n = levels(root);       // Number of Levels

    for(int i=1; i<=n; i++) {
        nthLevel(root, 1, i);
        cout << endl;
    }
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

    // nthLevel(a, 1, 1);
    // nthLevel(a, 1, 2);
    // nthLevel(a, 1, 3);

    // Level Order Traversal by DFS (nth level DFS)
    levelOrder(a);
}