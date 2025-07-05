// Limitation/ Disadvantage of Queue Implementation from Arrays/ Vectors is : Wastage of Space
// Wastage of Space : If we pop() then f++ and after that if we want to push any element back in the array/vector then it is not possible as f can't be decrement if it is once incremented
// although the size of vector/ array is not Full S

#include<iostream>
#include<queue>
using namespace std;
class Queue {
public: 
    int f;          // Front Index
    int b;          // Back Index
    int arr[5];     // Array Declaration
    // By default Constructor 
    Queue() {
        f = 0;
        b = 0;
    }
    void push(int val) {
        if(b==5) {
            // Index out of bound -- "Overflow Error"
            cout << "Queue is FULL!" << endl;
            return;
        }
        arr[b] = val;
        b++;
    }
    void pop() {
        if(b-f==0) {      //    -- as size i.e., b-f = 0
            // Queue is Empty -- "Underflow Error"
            cout << "Queue is Empty!" << endl;
            return;
        }
        f++;
    }
    int front() {
        if(b-f==0) {      // -- as size i.e., b-f = 0
            // Queue is Empty -- "Underflow Error"
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return arr[f];
    }
    int back() {
        if(b-f==0) {      //  -- as size i.e., b-f = 0
            // Queue is Empty -- "Underflow Error"
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return arr[b-1];        // because b stays at next of last element of array
    }
    int size() {
        return b-f;
    }
    bool empty() {
        if(b-f==0) {      //  -- as size i.e., b-f = 0
            return true;
        }
        else return false;
    }
    void display() {
        for(int i=f; i<b; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    // User Defined Queue
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.display();
    q.push(50);
    q.display();
    q.push(50);
    q.display();
    q.pop();
    q.display();
    q.pop();
    q.display();
    q.pop();
    q.display();
    q.pop();
    q.display();
    q.pop();
    q.display();
    q.pop();
    q.display();
    q.pop();
    q.display();
}