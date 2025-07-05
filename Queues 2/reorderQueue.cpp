// Reorder Queue (Interleave 1st half with 2nd half)        --  Using Only One Stack

// Time Complexity : O(n) 
// Space Complexity : O(n)

#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void display(queue<int> &q) {
    int n =q.size();
    for(int i=1; i<=n; i++) {
        cout << q.front() << " ";
        q.push(q.front());
        q.pop(); 
    }
    cout << endl;
}
int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    display(q);     // 1 2 3 4 5 6 7 8
    // Step 1 : First Half ko queue se stack and then stack se queue -- to reverse 
    // Step 2 : Then push 1st (exactly 2nd half) half from queue to stack 
    // Step 3 : Do pairing (INTERLEAVE) as push 1st element of queue with top element of stack -- so push st.top() at back of queue and then q.front() to its back
    // Step 4 : Then reverse the queue by using stack

    stack<int> st;
    int  n = q.size();
    // Step 1
    for(int i=1; i<=n/2; i++) {
        st.push(q.front());
        q.pop();
    }
    while(st.size() > 0) {
        q.push(st.top());
        st.pop();
    }
    // Step 2
    for(int i=1; i<=n/2; i++) {
        st.push(q.front());
        q.pop();
    }
    // Step 3 : Then do pairing
    for(int i=1; i<=n/2; i++) {
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }       
    // Step 4 : Now, reverse the queue using stack
    for(int i=1; i<=n; i++) {
        st.push(q.front());
        q.pop();
    }
    while(st.size() > 0) {
        q.push(st.top());
        st.pop();
    }
    display(q);
}

// We can also do this question by using Array (In Coding Test)