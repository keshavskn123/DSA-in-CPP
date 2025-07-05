// Hint : Use Min Heap of only k elements 

// T.C = O(n*logk) where n = current size of priority queue 
// S.C = O(n)       -- Total space used
// A.S = O(k)       -- Auxiliary Space = Extra Space used = Priority Queue of size "k"

#include<iostream>
#include<queue>
using namespace std;
int main() {
    int arr[] = {10, 20, -4, 5, 18, 24, 1, -7, 56};
    int k = 3;
    priority_queue<int, vector<int>, greater<int>> pq;     // Min Heap
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++) {
        pq.push(arr[i]);
        if(pq.size() > k) pq.pop();
    }
    cout << pq.top();
}