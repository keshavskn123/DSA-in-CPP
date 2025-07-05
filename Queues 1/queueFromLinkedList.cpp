// Linked List Implementation of Queue
// Advantages opf Queue Implementation from Linked List : Linked List has unlimited size so there is no error of "Queue is FULL"
// 1. Unlimited Size 
// 2. Natural, It is like (same as) Linked List Implementation  
// 3. Wastage of size is not there

#include<iostream>
using namespace std;
class Node {      // User Defined Data Type
public:
    int val;        // Value of node 
    Node* next;     // next is node pointer which stores the address of next Node of Linked List
    // Parameterized Constructor
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};
class Queue {       // User defined Data Structure
public: 
    Node* head;
    Node* tail;
    int Size;       // Size of Queue is same as of linked list
    Queue() {
        head = tail = NULL;
        Size = 0;
    }
    // push, pop, size, empty, front, back, display      -- to be implemented
    
    // push(val)    -- insertAtTail(val)
    // pop()        -- deleteAtHead()
    // front()      -- head->val
    // back()       -- tail->val
    // size()       -- Size i.e., size of ll
    // empty()      -- return true is (Size==0)    else return false
    // display()    -- To display all the elements of Queue 

    void push(int val) {
        // insertAtTail
        Node* temp = new Node(val);
        if(Size == 0) head = tail = temp;
        else {
            // if(Size!=0) 
            tail->next = temp;
            tail = temp;
        }
        Size++;
    }
    void pop() {
        // deleteAtHead() 
        if(Size == 0) {
            cout << "Queue is Empty" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete(temp);       // Wastage nahi ho rahi
        Size--;
    }
    int front() {
        if(Size == 0) {
            cout << "Queue is Empty" << endl; 
            return -1;
        }
        return head->val;
    }
    int back() {
        if(Size == 0) {
            cout << "Queue is Empty" << endl; 
            return -1;
        }
        return tail->val;
    }
    void display() {
        // display the ll -- In Forward direction i.e., from Left to Right
        // if(Size == 0) cout << "Queue is Empty" << endl;
        Node* temp = head;
        while(temp!=NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    int size() {
        return Size;
    }
    bool empty() {
        if(Size == 0) return true;
        else return false;
    }
};
int main() {
    Queue q;
    q.front();
    q.pop();
    q.push(10);  
    cout << q.back() << endl;
    q.push(20);         
    q.push(30);    
    q.push(40);
    q.display();    // 10 20 30 40 
    q.push(50);     
    q.display();    // 10 20 30 40 50
    q.push(60);
    q.display();    // 10 20 30 40 50 60
    q.pop();
    q.display();    // 20 30 40 50 60
    q.pop();
    q.display();    // 30 40 50 60
    q.pop();
    q.display();     // 40 50 60
    q.pop();
    q.display();     // 50 60
    q.pop();
    q.display();     // 60
    cout << q.size();   // 1
    q.pop();         // Queue is Empty
    q.display();   
    q.pop();         // Queue is Empty
    q.display();
    cout << q.size();
}