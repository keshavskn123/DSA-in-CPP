#include<iostream>
using namespace std;
class Node {
public: 
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};
int main() {
    Node* a = new Node(10);
    Node* b = new Node(10);
    Node* c = new Node(10);
    a->next = b;
    b->next = c;
    Node* h = a;
    cout << a->val << endl;     // 10
    delete(h);          // or delete(a);        // It is used to delete this a or h node from memory
    cout << a->val;             // Any garbage value
}