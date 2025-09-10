#include <iostream>
#include <queue>
using namespace std;
void InterleaveQueue(queue <int> &q) {
    int n= q.size();
    if (n %2 != 0) {
        cout<<"Queue size must be even"<<endl;
        return;
    }
    queue <int> q1;
    for (int i=0;i<n/2;i++) {
        q1.push(q.front());
        q.pop();
    }
    while (!q1.empty()) {
        q.push(q1.front());
        q1.pop();
        q.push(q.front());
        q.pop();
    }
}
int main() {
    queue <int> q;
    for (int i=1;i<=8;i++) {
        q.push(i);
    }
    InterleaveQueue(q);
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}