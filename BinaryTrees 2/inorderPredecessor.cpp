// Boundary Traversal : 
// 1. Left Boundary (Excluding Leaf Nodes)       -- where leaf node is the node which does not have any node
// 2. Leaf Nodes (Left to Right)    
// 3. Right Boundary (Excluding Leaf Nodes)     -- In Reverse Order
#include<iostream>
#include<bits/stdc++.h>
#include<queue>
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

Node* construct(int arr[], int n) {
    // we can't use size of arr if we will not send it in function
    // and array is a pointer so we don't need not to use int*
    
    queue<Node*> q;
    Node* root = new Node(arr[0]);
    q.push(root);
    int i = 1;
    int j = 2; 
    while(q.size() > 0 && i<n) {
        Node* temp = q.front();
        q.pop();

        Node* l = NULL;
        Node* r = NULL;
        if(arr[i] != INT_MIN) l = new Node(arr[i]);              // Nodes bana lo agar NULL na ho to
        if(j!=n && arr[j] != INT_MIN) r = new Node(arr[j]);     // Nodes bana lo agar NULL na ho to

        temp->left = l;
        temp->right = r;

        if(l != NULL) q.push(l);    // We push l!=NULL because NULL don't have any left and right
        if(r != NULL) q.push(r);    // We push r!=NULL because NULL don't have any left and right

        i+=2;
        j+=2;
    }
    return root;
}

Node* inorderPredecessor(Node* root) {
    if(root->left == NULL) return NULL;
    Node* predecessor = root->left;
    while(predecessor->right != NULL) predecessor = predecessor->right;
    return predecessor;
}

Node* inorderSuccessor(Node* root) {
    if(root->right == NULL) return NULL;
    Node* succesor = root->right;
    while(succesor->left != NULL) succesor = succesor->left;
    return succesor;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = construct(arr, n);
    Node* predecessor = inorderPredecessor(root);
    Node* successor = inorderSuccessor(root);
    // cout << root->val << " " << predecessor->val << " " << successor->val;
    cout << root ->val << endl;
    if(predecessor == NULL) cout << "There is no prdecessor exist for the given node";
    else cout << predecessor->val << endl;
    if(successor == NULL) cout << "There is no successor exist for the given node";
    else cout << successor->val << endl;
}

// Note : Inorder Predecessor and Inorder Successor will always be a Node with 1 child or node with 0 child (i.e., Leaf Node)