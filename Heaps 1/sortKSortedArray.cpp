// Sort a "k" sorted array (Sort a nearly sorted array)
// Using Min Heap as we need kth smallest element at every point of time
// T.C = O(n*logk) and S.C = O(n)   -- For ans vector 

// Method - 1 : Using Extra Array having S.C = O(n)

// #include<iostream>
// #include<queue>
// using namespace std;
// int main() {
//     int arr[] = {6, 5, 3, 2, 8, 10, 9};
//     int k = 3;
//     int n = sizeof(arr)/sizeof(arr[0]);
//     for(int i=0; i<n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     vector<int> ans;
//     // Using min heap of "k" size 
//     priority_queue<int, vector<int>, greater<int>> pq;
//     for(int i=0; i<n; i++) {
//         pq.push(arr[i]);
//         if(pq.size() > k) {
//             ans.push_back(pq.top());
//             pq.pop();
//         }
//     }
//     // Now, total 1st k largest elements (or last k min elements) are left in the min heap so we need to push it at the end of ans vector
//     while(pq.size() > 0) {
//         ans.push_back(pq.top());
//         pq.pop();
//     }
//     for(int i=0; i<ans.size(); i++) {
//         cout << ans[i] << " ";
//     }
// }



// Method - 2 : Without using any extra array (Modifications in the given array arr)
// T.C = O(n*logk) and S.C = O(1)

#include<iostream>
#include<queue>
using namespace std;
int main() {
    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int idx = 0;      // Used for iterating in the array arr for updating it to store sorted element   
    // Using min heap of "k" size 
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<n; i++) {
        pq.push(arr[i]);
        if(pq.size() > k) {
            arr[idx++] = pq.top();
            pq.pop();
        }
    }
    // Now, total 1st k largest elements (or last k min elements) are left in the min heap so we need to push it at the end of ans vector
    while(pq.size() > 0) {
        arr[idx++] = pq.top();
        pq.pop();
    }
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}