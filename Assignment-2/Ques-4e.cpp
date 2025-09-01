#include <iostream>
#include <string>
using namespace std;
int main() {
    string str;
    cout<<"Enter a string: ";
    getline(cin,str);
    string result;
    for (int i=0;i<str.length();i++) {
        char ch = str[i];
        if (ch>='A' && ch<='Z') {
            ch = tolower(ch);
            result = result + ch;
        }
        else {
            result = result + ch;
        }
    }
    cout<<"The string after converting is: "<<result;
    return 0;
}