// b) Write a program to reverse a string. 
#include <iostream>
#include <string>
using namespace std;
int main() {
    string str;
    getline(cin,str);
    cout<<"Original string: "<<str<<endl;
    int i=0,j=str.length()-1;
    for (int k=0;k<str.length()/2;k++) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    cout<<"Reversed string: "<<str;
    return 0;
}