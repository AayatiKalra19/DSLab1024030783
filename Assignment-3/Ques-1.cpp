#include <iostream>
#include <stack>
using namespace std;
#define MAX 100
int StackArr[MAX];
int top = -1;
void push() {
    if (top==MAX-1) {
        cout<<"Stack Overflow"<<endl;
        return;
    }
    int x;
    cout<<"Enter element to push: "<<endl;
    cin>>x;
    StackArr[++top] = x;
    cout<<x<<" pushed into stack."<<endl;
}
void pop() {
    if (top == -1) {
        cout<<"Stack Underflow"<<endl;
        return;
    }
    else {
        cout<<StackArr[top--] <<"popped from stack."; 
    }
}
void isEmpty() {
    if (top == -1) {
        cout<<"Stack is empty"<<endl;
    }
    else {
        cout<<"Stack is not empty"<<endl;
    }
}
void isFull() {
    if(top == MAX - 1) {
        cout<<"Stack is full."<<endl;
    }
    else {
        cout<<"Stack is not full"<<endl;
    }
}
void display() {
    if (top==-1) {
        cout<<"No element to display"<<endl;
    }
    cout<<"Stack elements: ";
    for (int i= top;i>=0;i--) {
        cout<<StackArr[i]<<" ";
    }
    cout<<endl;
}
void peek() {
    if (top == -1) {
        cout<<"Stack is empty"<<endl;
        return;
    }
    else {
        cout << "Top element is: "<<StackArr[top]<<endl;
    }
}
int main() {
    int choice;
    cout<<"Enter choice: ";
    cin>>choice;
    switch(choice) {
        case 1:
            cout<<"Push(): "<<endl;
            push();
            break;
        case 2:
            cout<<"Pop(): "<<endl;
            pop();
            break;
        case 3:
            cout<<"isEmpty(): "<<endl;
            isEmpty();
            break;
        case 4:
            cout<<"isFull(): "<<endl;
            isFull();
            break; 
        case 5:
            cout<<"Display(): "<<endl;
            display();
            break;
        case 6:
            cout<<"Peek():"<<endl;
            peek();
            break;
        default:
            cout<<"Wrong choice";
    }
}