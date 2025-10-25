// size of circular linked list
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
int sizeCLL(Node* head) {
    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp -> next;
    }
    while (temp !=head);
    return count;
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
    node4-> next = head;
    cout<<"Size of circular linked list is: "<<sizeCLL(head);
}