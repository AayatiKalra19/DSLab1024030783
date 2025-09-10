#include <iostream>
#include <queue>
using namespace std;
void NonRepeating(string s) {
    int freq[26]={0};
    queue <char> q;
    for (int i=0;i<s.length();i++) {
        char ch = s[i];
        q.push(ch);
        freq[ch-'a']++;
        while (!q.empty() && freq[q.front() - 'a']>1) {
            q.pop();
        }
        if (!q.empty()) {
            cout<<q.front()<<" ";
        }
        else {
            cout<<"-1 ";
        }
    }
}
int main() {
    string input = "aabc";
    NonRepeating(input);
    return 0;
}
