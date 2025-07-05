#include<iostream>
#include<queue>
using namespace std;
int main() {
    int arr[] = {3, -4, -7, 30, 7, -9, 2, 1, 6, -1}; 
    // ams should be ans[] = {-4, -4, -7, -9, -9, -9, 0, -1}
    int k = 3;      // Size of each window
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Store all negative elements of arr[] into queue
    queue<int> q;
    for(int i=0; i<n; i++) {
        if(arr[i] < 0) q.push(i);   
    }
    
    vector<int> ans;
    int i=0;        // Starting index of 1st window
    while(i+k<=n) {         // i=0 to i=n-k for all windows to cover
        // if q.front() < i (starting index of window)  here q.front() denotes the first negative to check if it is present in the current window or not 
        while(q.size() > 0 && q.front() < i) q.pop();
        // if q.front() >= i+k
        if(q.size() == 0 || q.front() >= i+k) ans.push_back(0);
        else {
            // q.front() lies inside the window 
            ans.push_back(arr[q.front()]);
        }
        i++;
    }
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}