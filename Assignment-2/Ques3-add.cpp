#include <iostream>
#include <string.h>
using namespace std;
int main() {
    string s1;
    string s2;
    cout<<"Enter string 1: ";
    getline(cin,s1);
    cout<<"Enter string 2: ";
    getline(cin,s2);
    if (s1.size() != s2.size() ) {
        cout<<"Not anagrams";
    }
    else {
    for (int i=0;i<s1.size();i++) {
        for (int j=i+1;j<s1.size();j++) {
            if (s1[i]>s1[j]) {
                char temp = s1[i];
                s1[i] = s1[j];
                s1[j] = temp;
            }
        }
    }
    for (int i=0;i<s2.size();i++) {
        for (int j=i+1;j<s2.size();j++) {
            if (s2[i]>s2[j]) {
                char temp = s2[i];
                s2[i] = s2[j];
                s2[j] = temp;
            }
        }
    }
    
        if (s1 == s2) {
            cout<<"Strings are anagrams";
        }
        else {
            cout<<"Strings are not anagrams";
        }
    
    }
}
