#include<iostream>
#include<stack>
using namespace std;
int priority(char ch) {
    if(ch == '+' || ch == '-') return 1;
    else return 2;
}
int solve(int val1, char ch, int val2){
    // val1 op val2
    if(ch == '+') return val1 + val2;
    else if(ch == '-') return val1 - val2;
    else if(ch == '*') return val1 * val2;
    else return val1 / val2;
}
int main() {
    string s = "7+9*4/8-3";       // infix expression
    // To evaluate infix expressions we need 2 stacks -- 1 for values and other for operators 
    stack<int> val;
    stack<char> op;
    for(int i=0; i<s.length(); i++) {
        // check if s[i] is a digit or not 
        if(s[i]>='0' && s[i]<='9') {
            val.push(s[i] - 48);            // for adding numbers only in val stack     -- s[i] - 48
        }
        else {
            // if s[i] is a character
            if(op.size()==0 || priority(op.top()) < priority(s[i])) {
                op.push(s[i]);
            }
            else {
                while(op.size() > 0 && priority(op.top()) >= priority(s[i])) {
                    // kaam krna hai
                    char ch = op.top();
                    op.pop();
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    int ans = solve(val1, ch, val2);
                    val.push(ans);
                }
                op.push(s[i]);
            }
        }
    }
    // At last if any operator remains in the operator stack, then we have to again solve (Kaam krna padega)
    while(op.size() > 0) {
        char ch = op.top();
        op.pop();
        int val2 = val.top();
        val.pop();
        int val1 = val.top();
        val.pop();
        int ans = solve(val1, ch, val2);
        val.push(ans);
    }

    cout << val.top() << endl;
    cout << 7+9*4/8-3;
}