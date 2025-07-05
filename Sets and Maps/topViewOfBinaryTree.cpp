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

void topView(Node* root) {
    // Hashmap or unordered_map
    // Queue
    unordered_map<int, int> m;      // level, root->val
    queue<pair<Node*, int> > q;     // node, level
    // Push root
    pair<Node*, int> r;
    r.first = root;
    r.second = 0;
    q.push(r);
    while(q.size() > 0) {       // BFS Traversal
        Node* temp = (q.front()).first;
        int level = (q.front()).second;
        q.pop();
        if(m.find(level) == m.end()) {  // level not found
            m[level] = temp->val;
        }

        // For LST (Left Sub Tree)
        if(temp->left != NULL) {
            // Push left node along with its level in the queue
            pair<Node*, int> p;
            p.first = temp->left;
            p.second = level-1;
            q.push(p);
        }
        if(temp->right != NULL) {
            // Push left node along with its level in the queue
            pair<Node*, int> p;
            p.first = temp->right;
            p.second = level+1;
            q.push(p);
        }
    }
    // finding minLevel & maxLevel
    int minLevel = INT_MAX;
    int maxLevel = INT_MIN;
    for(auto x : m) {
        // if(x.first < minLevel) minLevel = x.first;
        // if(x.first > maxLevel) maxLevel = x.first;
        //          OR
        minLevel = min(minLevel, x.first);      // x.first is level of any node  
        maxLevel = max(maxLevel, x.first);      // x.first is level of any node  
    }
    for(int i=minLevel; i<=maxLevel; i++) {
        cout << m[i] << " ";        // m[i] is value of ith node of tree
    }
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, INT_MIN, 6, INT_MIN, INT_MIN, 7, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = construct(arr, n);
    // Level Order Traversal by DFS (nth level DFS)
    // levelOrder(root);
    topView(root);
}