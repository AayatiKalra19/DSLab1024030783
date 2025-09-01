#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
    string str;
    cout<<"Enter a string: ";
    getline(cin,str);
    stack <int> st;
    for (int i=0;i<str.length();i++) {
        char ch = str[i];
        st.push(ch);
    }
    string ans;
    while (!st.empty()) {
        char ch = st.top();
        ans = ans + ch;
        st.pop();
    }
    cout<<"Reversed String: "<<ans;
    return 0;
}