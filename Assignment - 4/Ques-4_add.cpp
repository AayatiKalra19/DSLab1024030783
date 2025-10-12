#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int Sandwiches(queue <int> &q,stack <int> &s) {
    int rotations = 0;
    while (!q.empty() && rotations<q.size()) {
        int curr = q.front();
        
        if (curr == s.top()) {
            q.pop();
            s.pop();
            rotations = 0;
        }
        else {
            q.pop();
            q.push(curr);
            rotations++;
        }
    }
    return q.size();
}
int main() {
    queue <int> q;
    stack <int> s;
    q.push(1);
    q.push(1);
    q.push(0);
    q.push(0);
    s.push(0);
    s.push(1);
    s.push(0);
    s.push(1);
    cout<<"Students unable to eat: "<<Sandwiches(q,s);
}