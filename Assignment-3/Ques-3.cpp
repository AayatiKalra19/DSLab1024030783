#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isBalanced(string str) {
    stack <char> st;
    for (int i=0;i<str.length();i++) {
        char ch = str[i];
        if (ch=='(' || ch == '{' || ch=='[') {
            st.push(ch);
        }
        else  {
            if (!st.empty()) {
                char top = st.top();
                if ((ch==')' && top == '(') || (ch=='}' && top == '{') || (ch==']' && top == '[')) {
                    st.pop();
                
                }      
                else {
                    return false;
                }
            }
        }     
    }
    return st.empty();
}
int main() {
    string str;
    cout<<"Enter a string: ";
    getline(cin,str);
    if (isBalanced(str)) {
        cout<<"String has balanced parenthesis";
    }
    else {
        cout<<"String does not have balanced parenthesis";
    }
    return 0;
}