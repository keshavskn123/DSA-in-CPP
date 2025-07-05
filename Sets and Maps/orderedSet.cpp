#include<iostream>
#include<set>
#include<map>
using namespace std;
int main() {
    // set<int> s;     // Sorted (In ascending order)
    // s.insert(3);
    // s.insert(7);
    // s.insert(5);
    // // for each loop
    // for(int ele : s) {
    //     cout << ele << " ";
    // }

    // map<int, int> m;    // Ordered map is sorted in terms of key or p.first
    // m[1] = 30;
    // m[2] = 10;
    // m[3] = 20;
    // // for each loop
    // for(auto p : m) {
    //     cout << p.first << " " << p.second << endl;
    // }
    
    map<string, int> m;    // Ordered map is sorted in terms of key or p.first
    // If key data type is string, then it will be sorted lexographically order (on the basis of ASCII value)
    m["Keshav"] = 30;
    m["Nikhil"] = 10;
    m["Jyotsna"] = 20;
    // for each loop
    for(auto p : m) {
        cout << p.first << " " << p.second << endl;
    }
    
}