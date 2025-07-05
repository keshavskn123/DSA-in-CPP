#include<iostream>
#include<stack>
using namespace std;
int solve(int val1, char ch, int val2){
    // val1 op val2
    if(ch == '+') return val1 + val2;
    else if(ch == '-') return val1 - val2;
    else if(ch == '*') return val1 * val2;
    else return val1 / val2;
}
int main() {
    string s = "-/*+79483";       // Prefix expression
    // To evaluate Prefix expression, we need only 1 stack of values
    stack<int> val;
    int n = s.length();
    for(int i=n-1; i>=0; i--) {
        // check if s[i] is a digit or not 
        if(s[i]>='0' && s[i]<='9') {
            val.push(s[i] - 48);            // for adding numbers only in val stack     -- s[i] - 48
        }
        else {
            // if s[i] is a character
            // To kaam krna hai
            char ch = s[i];
            int val1 = val.top();
            val.pop();
            int val2 = val.top();
            val.pop();
            int ans = solve(val1, ch, val2);
            val.push(ans);
        }
    }
    // At last, only one element left so need to solve at last
    cout << val.top() << endl;
    cout << (7+9)*4/8-3;
}