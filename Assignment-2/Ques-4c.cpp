#include <iostream>
#include <string>
using namespace std;
int main() {
    string str;
    cout<<"Enter a string: ";
    getline(cin,str);
    string res;
    for (int i=0;i<str.length();i++) {
        char ch = str[i];
        ch = tolower(ch);
        if (!(ch=='a' || ch=='e' || ch=='i' || ch== 'o'|| ch=='u')) {
            res = res+str[i];
        }
    }
    cout<<"String after removing vowels: "<<res;
    return 0;
}