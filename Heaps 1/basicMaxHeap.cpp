// Priority Queues are of 2 types : Max and Min Heap 

#include<iostream>
#include<queue>
using namespace std;
int main() {
    priority_queue<int> pq;     // By default, max Heap is created in C++ 
    pq.push(10);
    pq.push(-18);
    pq.push(100);
    pq.push(0);
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
}