#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int val) {
            this -> data = val;
            this-> next = NULL;
            this -> prev = NULL;
        }
};
// find the size of Doubly linked list
int getsize(Node* head) {
    Node* temp = head;
    int size = 0;
    while (temp!=NULL) {
        size++;
        temp = temp -> next;
    }
    return size;
}
int main() {
    Node* head;
    Node* node1 = new Node(10);
    Node* node2 = new Node(20);
    Node* node3 = new Node(30);
    head = node1;
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = NULL;
    node1 -> prev = NULL;
    node2 -> prev = node1;
    node3-> prev = node2;
    cout<<"Size of doubly linked list: "<<getsize(head);
}