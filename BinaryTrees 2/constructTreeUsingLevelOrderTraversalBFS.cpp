// Print all the nodes of Nth level from left to right 

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
void levelOrder(Node* root) {       // BFS (Breadth First Search)
    queue<Node*> q;
    q.push(root);
    while(q.size() > 0) {
        Node* temp = q.front();
        cout << temp->val << " ";
        q.pop();
        // Left to Right Traversal
        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, INT_MIN, 6, INT_MIN, INT_MIN, 7, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = construct(arr, n);
    // Level Order Traversal by DFS (nth level DFS)
    levelOrder(root);
}