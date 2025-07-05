// Limitation/ Disadvantage of Queue Implementation from Arrays/ Vectors is : Wastage of Space
// Wastage of Space : If we pop() then f++ and after that if we want to push any element back in the array/vector then it is not possible as f can't be decrement if it is once incremented
// although the size of vector/ array is not Full 

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Queue {
public: 
    int f;          // Front Index
    int b;          // Back Index
    vector<int> arr;        // Declaration of vector arr of 0 size
    // By default Constructor       -- which also takes size of queue by using any value i.e., val
    Queue(int val) {
        f = 0;
        b = 0;
        vector<int> v(val);         // Declaring of vector v of size - val
        arr = v;                    // Make a copy of v into arr vector
    }
    void push(int val) {
        if(b==arr.size()) {
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
    // User Defined Queue with a any fixed value of size
    Queue q(5);
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