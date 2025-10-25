// Write a program to check if a linked list is Circular Linked List or not.
#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(int val) {
            this -> data = val;
            this-> next = NULL;
        }
};
bool CircularLinkedList(Node* head) {
    if (head == NULL) {
        return true;
    }
    Node* temp = head-> next;
    while (temp!=NULL && temp!=head) {
        temp = temp -> next;
    }
    return (temp == head);
}
int main() {
    Node* head = new Node(20);
    Node* node1 = new Node(100);
    Node* node2 = new Node(40);
    Node* node3 = new Node(80);
    Node* node4 = new Node(60);
    head -> next = node1;
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4-> next = NULL;
    if (CircularLinkedList(head)) {
        cout<<"List is circular";
    }
    else {
        cout<<"List is not circular";
    }
}