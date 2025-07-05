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

void leftBoundary(Node* root) {
    // Using Preorder -- Root, Left, Right
    if(root == NULL) return;        // Base Case
    if(root->left == NULL && root->right == NULL) return;       // Base Case for Leaf Node
    cout << root->val << " ";
    leftBoundary(root->left);   // Left Call 
    if(root->left == NULL) leftBoundary(root->right);       // Right Call
}

void bottomBoundary(Node* root) {
    // Using Preorder -- Root, Left, Right
    if(root == NULL) return;        // Base Case
    if(root->left == NULL && root->right == NULL) cout << root->val << " ";
    bottomBoundary(root->left);   // Left Call 
    bottomBoundary(root->right);       // Right Call
}

void rightBoundary(Node* root) {
    // Using Preorder -- Root, Left, Right
    if(root == NULL) return;        // Base Case
    if(root->left == NULL && root->right == NULL) return;       // Base Case for Leaf Node
    rightBoundary(root->right);       // Right Call
    if(root->right == NULL) rightBoundary(root->left); 
    cout << root->val << " ";
}

void boundaryTraversal(Node* root) {
    leftBoundary(root);         // Left Boundary
    bottomBoundary(root);       // Bottom Boundary (Leaf Nodes)
    rightBoundary(root->right); // Right Bouundary
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, INT_MIN, 6, 7, INT_MIN, 8, INT_MIN, 9, 10, INT_MIN, 11, INT_MIN, 12, INT_MIN, 13, INT_MIN, 14, 15, 16, INT_MIN, 17, INT_MIN, INT_MIN, 18, INT_MIN, 19, INT_MIN, INT_MIN, INT_MIN, 20, 21, 22, 23, INT_MIN, 24, 25, 26, 27, INT_MIN, INT_MIN, 28, INT_MIN, INT_MIN};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = construct(arr, n);
    // Boundary Traversal
    levelOrder(root);
    boundaryTraversal(root);
}