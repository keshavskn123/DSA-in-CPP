// Remove first K elements from Queue -- Using Stack

#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void removeKElementsOfQueue(queue<int> &q, int k) {
    // we have to remove first k elements from queue

    // Step 1 : Using for loop, push first "k" elements i.e., from (i=1 to i<=k) into stack and also pop these from queue
    // Step 2 : Then pop from stack and push into queue
    // Step 3 : Then we have to reverse first (n-k) elements with last k elements of queue without changing the order of elements of both of these parts of queue
    // It is done by pop "n-k" elements from front of queue and side by side push these elements back into queue

    // Note : We can only add the elements into queue (from back end)
    // And we can only pop the elements from queue (from front end)

    stack<int> st;
    int n = q.size();
    for(int i=1; i<=k; i++) {
        st.push(q.front());
        q.pop();
    }
    while(st.size() > 0) {
        q.push(st.top());
        st.pop();
    }
    for(int i=1; i<=n-k; i++) {
        q.push(q.front());
        q.pop();
    }
}

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

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    display(q);         // 1 2 3 4 5        -- Original Queue i.e., q
    int k = 2;
    removeKElementsOfQueue(q, k);           // Reverse first k elements of q
    display(q);         // 2 1 3 4 5        -- Updated Queue i.e., q
}