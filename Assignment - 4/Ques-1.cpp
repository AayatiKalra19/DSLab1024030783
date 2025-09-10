#include <iostream>
using namespace std;
class queue{
    int *arr;
    int front,rear;
    int size;
    public:
    queue(int s) {
        size = s;
        arr = new int[s];
        front = -1;
        rear = -1;
    }
    bool isEmpty() {
        return (front==-1);
    }
    bool isFull() {
        return (rear == size - 1);
    }
    void enqueue(int x) {
        if (isFull()) {
            cout<<"Queue is full"<<endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear++;
        arr[rear] = x;
        cout<<x<<" enqueued"<<endl;
        
    }
    int dequeue() {
        if (isEmpty()) {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int data = arr[front];
        if(front == rear) {
            front = rear = -1;
        }
        else {
            front++;
        }
        cout<<data<<"dequeued"<<endl;
        return data;
    }
    int peek() {
        if (isEmpty()) {
            cout<<"Queue is empty"<<endl;
            return -1; 
        }
        return arr[front];
    }
    void display() {
        if (isEmpty()) {
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<"Queue elements: ";
        for (int i=front;i<=rear;i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main() {
    int size;
    cout<<"Enter size of queue: ";
    cin>>size;
    queue q(size);
    int choice,value;
    do {
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Check if empty"<<endl;
        cout<<"4. Check if full"<<endl;
        cout<<"5. Display"<<endl;
        cout<<"6. Peek"<<endl;
        cout<<"Enter choice(1-6): ";
        cin>>choice;
        switch(choice) {
            case 1:
                cout<<"Enter value: ";
                cin>>value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                if (q.isEmpty()) {
                    cout<<"Queue is empty"<<endl;
                }
                else {
                    cout<<"Queue is not empty"<<endl;
                }
                break;
            case 4:
                if (q.isFull()) {
                    cout<<"Queue is full"<<endl;
                }
                else {
                    cout<<"Queue is not full"<<endl;
                }
                break;
            case 5:
                q.display();
                break;
            case 6:
               value = q.peek();
               if (value!=-1) {
                cout<<"Front element: "<<value<<endl;
               } 
               break;
            case 7:
               cout<<"Invalid choice"<<endl;
               break;
        }
    }
    while (choice!=7);
}