#include<iostream>
#include<queue>
using namespace std;
// T.C = O(n) and S.C = O(1)
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
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    // int n = q.size();
    // // Display queue :  // 10 20 30 40 50 
    // for(int i=0; i<n; i++) {
    //     int x = q.front();
    //     cout << x << " ";
    //     q.pop(); 
    //     q.push(x);
    // }

    display(q);  
    q.pop();    // 20 30 40 50
    display(q);  
}