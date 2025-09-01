// Write a program for the evaluation of a Postfix expression. 
#include <iostream>
#include <stack>
#include <cmath>
using namespace std;
int evaluatePostfix(string str) {
    stack<int> st;
    for (int i=0;i<str.length();i++) {
        char ch = str[i];
        if(isdigit(ch)) {
            st.push(ch-'0');
        }
        else {
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();
            int result;
            switch (ch) {
                case '+': 
                    result = operand1+operand2;
                    break;
                case '-': 
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                case '^':
                    result = pow(operand1,operand2);
                    break;
                default:
                    cout<<"Invalid Operator"<<endl;
                    return -1;
            }
            st.push(result);
        }
    }
    return st.top();
}
int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;
    cout << "Result = " << evaluatePostfix(postfix) << endl;
    return 0;
}