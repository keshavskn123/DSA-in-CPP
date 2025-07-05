#include<iostream>
#include<queue>
using namespace std;
int minCost(vector<int> &arr) {
    priority_queue<int, vector<int>, greater<int>> pq;  // Min-Heap
    for(int i=0; i<arr.size(); i++) {
        pq.push(arr[i]);
    }
    int ans = 0;        // Total Cost
    while(pq.size() > 1) {
        int len1 = pq.top();
        pq.pop();
        int len2 = pq.top();
        pq.pop();
        int cost = len1 + len2;
        ans += cost;
        pq.push(cost);
    }
    return ans;
}
int main() {
    vector<int> arr = {6,5,3,2,8,10,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << minCost(arr);
}