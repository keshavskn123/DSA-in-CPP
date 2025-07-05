#include<iostream>
using namespace std;
class Node{                 // User Defined Data type
public:
    int val;
    Node* next;
    Node* prev;                 // extra for DLL
    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;      // extra for DLL
    }
};

class Deque{           // User Defined Data Structure   
public:
    Node* head;
    Node* tail;
    int Size;
    
    Deque(){           // Constructor (By default)
        head = tail = NULL;
        Size = 0;
    }
    
    // Insert at End/ Tail End
    void pushBack(int val){          // T.C = O(1) and S.C = O(1)
        Node* temp = new Node(val);
        if(Size==0) head = tail = temp;
        else{
            // link the tail node to temp 
            tail->next = temp;
            // for backward connection 
            temp->prev = tail;      // extra    
            // tail to point at the same address where temp is currently pointing (so that tail->next is always equal to NULL)
            tail = temp;
        }
        Size++;
    }

    // Insert at Beginning/ Front end
    void pushFront(int val){   // T.C = O(1) and S.C = O(1)
        Node* temp = new Node(val);
        if(Size == 0){
            head = tail = temp;
        }
        else{
            // link the head node to temp
            temp->next = head;
            // for backward connection
            head->prev = temp;      // extra
            head = temp;
        }
        Size++;
    }

    // Delete at Head/ Front end
    void popFront(){
        if(Size == 0) {
            cout << "List is Empty";
            return;
        }
        head = head->next;
        head->prev = NULL;      // extra
        if(head != NULL) head->prev = NULL;          // extra
        if(head == NULL) tail = NULL;           // extra
        Size--;
    }

    // Delete at Tail/ Back end
    void popBack(){
        if(Size == 0) {
            cout << "List is Empty";
            return;
        }
        else if(Size == 1) {         // extra
            popFront();
            return;
        }
        Node* temp = tail->prev;
        temp->next = NULL;
        tail = temp;
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
    
    int size() {
        return Size;
    }
    
    bool empty() {
        if(Size == 0) return true;
        else return false;
    }

    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Deque dq;     
    dq.pushBack(10);
    dq.pushBack(20);
    dq.pushBack(30);
    dq.pushBack(40);
    dq.pushBack(50);
    dq.display();
    dq.popBack();
    dq.display();
    dq.popFront();
    dq.display();
    dq.pushFront(24);
    dq.display();
    cout << dq.size() << endl;
    cout << dq.front() << endl;
    cout << dq.back() << endl;
    cout << dq.empty() << endl;
}