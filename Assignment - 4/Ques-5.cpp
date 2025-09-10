#include <iostream>
#include <queue>
using namespace std;

queue<int> q1, q2; 

void push(int x) {
    q2.push(x);
    while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1, q2);

    cout << x << " pushed into stack" << endl;
}

void pop() {
    if (q1.empty()) {
        cout << "Stack Underflow" << endl;
        return;
    }
    cout << q1.front() << " popped from stack" << endl;
    q1.pop();
}
int top() {
    if (q1.empty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return q1.front();
}
int main() {
    push(10);
    push(20);
    push(30);

    cout << "Top element: " << top() << endl;
    pop();
    cout << "Top element: " << top() << endl;
    pop();
    cout << "Top element: " << top() << endl;
    pop();
    return 0;
}
