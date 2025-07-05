// Print all the nodes of Nth level from left to right 

#include<iostream>
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

void levelOrder(Node* root) {       // BFS (Breadth First Search)   -- Using Queue  
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

// void levelOrder(Node* root) {
//     queue<Node*> q;
//     q.push(root);
//     while(q.size() > 0) {
//         Node* temp = q.front();
//         cout << temp->val << " ";
//         q.pop();
//         // Right to Left Traversal
//         if(temp->right != NULL) q.push(temp->right);
//         if(temp->left != NULL) q.push(temp->left);
//     }
// }

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

    // Level Order Traversal by DFS (nth level DFS)
    levelOrder(a);
}