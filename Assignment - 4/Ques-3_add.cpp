#include <iostream>
#include <stack>
#include <queue>
using namespace std;
bool Sort(queue <int> &q) {
    stack <int> s;
    queue <int> q1;
    int n= q.size();
    int num = 1;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr == num) {
            q1.push(curr);
            num++;
            
        }
        else if (!s.empty() && s.top() == num) {
            q1.push(s.top());
            s.pop();
            num++;
            q.push(curr);
        }
        else {
            s.push(curr);
        }
    }
    while (!s.empty() && s.top() == num) {
        q1.push(s.top());
        s.pop();
        num++;
    }
    return (num - 1 == n);
}
int main() {
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    if (Sort(q))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}