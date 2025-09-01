// Convert an infix expression into a postfix expression
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
} 
string infixToPostfix(string str) {
    stack <char> st;
    string postfix;
    for (int i=0;i<str.length();i++) {
        char ch = str[i];
        if ((ch>='A' && ch<='Z') || (ch>='0' && ch<='9')) {
            postfix = postfix + ch;
        } 
        else if (ch=='(') {
            st.push(ch);
        }
        else if (ch==')') {
            while (!st.empty() && st.top() !='(') {
                postfix = postfix + st.top();
                st.pop();
            }
            if (!st.empty()) {
                st.pop();
            }
        }
        else{
            while (!st.empty() && 
            ((precedence(st.top()) > precedence(ch)) || 
            (precedence(st.top()) == precedence(ch) && ch != '^'))) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}
int main() {
    string expr;
    cout << "Enter infix expression: ";
    getline(cin, expr);
    cout << "Postfix expression: " << infixToPostfix(expr) << endl;
    return 0;
}