#include <iostream>
#include <stack>
#include <vector>
using namespace std;
stack <int> s;
stack <int> minStack;
void push(int x) {
    s.push(x);
    if (minStack.empty() || x<=minStack.top()) {
        minStack.push(x);
    }
    else {
        minStack.push(minStack.top());
    }
}
int pop() {
    if(s.empty()) {
        return -1;
    }
    else {
        int poppedElement = s.top();
        s.pop();
        minStack.pop();
        return poppedElement;
    }
}
int getMin() {
    if (minStack.empty()) {
        return -1;
    }
    return minStack.top();
}
int main() {
    push(18);
    push(19);
    push(29);
    push(15);
    push(16);
    cout<<"Minimum element is: "<<getMin()<<endl;
    return 0;
}