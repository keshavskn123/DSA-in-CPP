#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void display(queue<int> &q) {
    int n = q.size();
    for(int i=0; i<n; i++) {
        int x = q.front();
        cout << x << " ";
        q.pop(); 
        q.push(x);
    }
    cout << endl;
}
void reverse(queue<int> &q) {
    stack<int> st;      // Extra stack used for reversing the queue     -- S.C = O(n)
    int n = q.size();
    // empty the queue into stack
    for(int i=0; i<n; i++) {
        int x = q.front();
        q.pop();
        st.push(x);
    }
    // empty the stack into queue
    for(int i=0; i<n; i++) {
        int x = st.top();
        st.pop();
        q.push(x);
    }
}
int main() {
    queue<int> q;       
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    // 10 20 30 40 50 
    display(q);         // Original Queue
    reverse(q);         // Reversing the Queue
    display(q);         // Reversed Queue
    reverse(q);         // Reversing the Reversed Queue
    display(q);         // Original Queue







    // queue<int> q;       
    // q.push(10);
    // q.push(20);
    // q.push(30);
    // q.push(40);
    // q.push(50);
    // // 10 20 30 40 50 
    // display(q);         // Original queue
    // int n = q.size();
    // stack<int> st;
    // // Push every element of queue into stack by using pop() operation in queue
    // for(int i=0; i<n; i++) {
    //     st.push(q.front());
    //     q.pop();
    // }
    // // Now again push element from stack to queue
    // for(int i=0; i<n; i++) {
    //     q.push(st.top());
    //     st.pop();
    // }
    // display(q);         // After reversing the queue using stack
    // q.pop();    // 20 30 40 50
    // display(q);  
}