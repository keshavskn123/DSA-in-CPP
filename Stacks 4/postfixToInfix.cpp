#include<iostream>
#include<stack>
using namespace std;
string solve(string val1, char ch, string val2){
    // val1 op val2 -- Infix
    string ans = val1 + ch + val2;
    return ans;
}
int main() {
    string s = "79+4*8/3-";       // Postfix expression
    // To evaluate Postfix expression, we need only 1 stack of values
    stack<string> val;
    for(int i=0; i<s.length(); i++) {
        // check if s[i] is a digit or not 
        if(s[i]>='0' && s[i]<='9') {
            val.push(to_string(s[i] - 48));            // for adding numbers only in val stack     -- s[i] - 48
        }
        else {
            // if s[i] is a character
            // To kaam krna hai
            char ch = s[i];
            string val2 = val.top();
            val.pop();
            string val1 = val.top();
            val.pop();
            string ans = solve(val1, ch, val2);
            val.push(ans);
        }
    }
    // At last, only one element left so need to solve at last
    cout << val.top();
}