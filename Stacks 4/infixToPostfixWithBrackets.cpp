#include<iostream>
#include<stack>
using namespace std;
int priority(char ch) {
    if(ch == '+' || ch == '-') return 1;
    else return 2;
}
string solve(string val1, char ch, string val2){
    // val1 op val2     -- Infix 
    // val1 val2 op     -- Postfix
    string ans = val1 + val2 + ch;
    return ans;
}
int main() {
    string s = "(7+9)*4/8-3";       // Infix expression
    // To evaluate infix expressions we need 2 stacks -- 1 for values and other for operators 
    stack<string> val;
    stack<char> op;
    for(int i=0; i<s.length(); i++) {
        // check if s[i] is a digit or not 
        if(s[i]>='0' && s[i]<='9') {
            string digit = to_string(s[i] - 48);
            val.push(digit);            // for adding numbers only in val stack     -- s[i] - 48
        }
        else {
            // if s[i] is a character
            if(op.size()==0) op.push(s[i]);
            // Pehle brackets ko check krna h
            else if(s[i] == '(') op.push(s[i]);
            else if(op.top() == '(') op.push(s[i]);
            else if(s[i] == ')') {
                // To jab tak opening bracket '(' na dikh jae to solve krna hai
                while(op.top() != '(') {
                    char ch = op.top();
                    op.pop();
                    string val2 = val.top();
                    val.pop();
                    string val1 = val.top();
                    val.pop();
                    string ans = solve(val1, ch, val2);
                    val.push(ans);
                }
                // Also pop the opening bracket after the loop breaks
                op.pop();
            }
            else if(priority(op.top()) < priority(s[i])) {
                op.push(s[i]);
            }
            else {
                while(op.size() > 0 && priority(op.top()) >= priority(s[i])) {
                    // kaam krna hai
                    char ch = op.top();
                    op.pop();
                    string val2 = val.top();
                    val.pop();
                    string val1 = val.top();
                    val.pop();
                    string ans = solve(val1, ch, val2);
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
        string val2 = val.top();
        val.pop();
        string val1 = val.top();
        val.pop();
        string ans = solve(val1, ch, val2);
        val.push(ans);
    }

    cout << val.top(); 
}