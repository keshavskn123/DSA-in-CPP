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
void removeAtEven(queue<int> &q) {  
    // Considering 0-based indexing
    int n = q.size();
    // for(int i=0; i<n; i++) {
    //     if(i%2 == 0) {
    //         // even-index as i is even      -- so remove it from queue
    //         q.pop();
    //     }
    //     else {
    //         // odd-index as i is odd        -- so firstly pop and then push again into queue
    //         int x = q.front();
    //         q.pop();
    //         q.push(x);
    //     }
    // }



    for(int i=0; i<n; i++) {
        if(i%2 != 0) {
            // odd-index as i is odd        -- so firstly pop and then push again into queue
            q.push(q.front());
        }
        q.pop();
    }
}
int main() {
    queue<int> q;       
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    // 10 20 30 40 50 
    display(q);         // Original Queue
    removeAtEven(q);         // Removing even-indexed element from Queue
    display(q);         // Reversed Queue
}