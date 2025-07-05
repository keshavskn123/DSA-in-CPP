#include<iostream>
#include<unordered_set>
using namespace std;
int main() {
    unordered_set<int> s;
    // We can only store only unique elements in sets
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(1);
    cout << s.size() << endl;
    s.erase(2);
    cout << s.size() << endl;
    // For each loop

    // for(int ele : s) {
    //     cout << ele << " ";
    // }
    //          OR
    for(auto ele : s) {
        cout << ele << " ";
    }
    cout << endl;

    // To find if our target element find in the stack 
    int target = 50;
    if(s.find(target) != s.end()) {         // target exists 
        cout << "Exists";
    }
    else cout << "Does not exist";
}