// For Preorder Traversal : 
// Time Complexity : "O(n)" where "n" is the number of nodes and we are visiting every nodes once atleast so T.C = O(n)
// Space Complexity : O(levels + 1) ~= O(height + 2) ~= O(height) = "O(h)" where "h" is the maximum height of tree

// Space Complexity is O(h) = O(n)  --  In Average/ Worst Case
// Space Complexity is O(h) = O(logn)  --  In Best/ Worst Case

// Space Complexity is the maximum space used when at any time in the Call Stack and this maximum space used is basically equal to the Total No. of Levels + 1(For NULL) in the tree
#include<iostream>
#include<stack>
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

void preorder(Node* root) {     
    if(root == NULL) return;        // Base Case
    stack<Node*> st;
    st.push(root);

    while(st.size() > 0) {
        Node* temp = st.top();
        st.pop();
        cout << temp->val << " ";       // Root
        if(temp->right) st.push(temp->right);   // Right            // if(temp->right) or if(temp->right != NULL)
        if(temp->left) st.push(temp->left);   // Left
    }
}

// If we use Stack, then we have to push temp->right before temp->left because we want to access temp->left first 
// Stack is LIFO(Last In First Out) or FILO(Fisrt In Last Out)

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
    preorder(a);     // 1 2 4 5 3 6 7 
}