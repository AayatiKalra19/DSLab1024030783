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
bool palindrome(Node* head) {
    if(head == NULL) {
        return true;
    }
    Node* temp = head;
    Node* start = head;
    while (temp -> next!= NULL) {
        temp = temp -> next;
    }
    Node* end = temp;
    while (start!=end && start!=end-> next) {
        if (start -> data == end -> data) {
            start = start -> next;
            end = end -> prev;
        }
        else {
            return false;
        }
    }
    return true;
}
void insert(Node* &head,int d) {
    if (head == NULL) {
        Node* newNode = new Node(d);
        head = newNode;
        return;
    }
    Node* newNode = new Node(d);
    Node* temp = head;
    while (temp -> next != NULL) {
        temp = temp -> next;
    }
    temp -> next = newNode;
    newNode->prev = temp;
    return;
}
int main() {
    Node* head = NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,2);
    insert(head,1);
    if(palindrome(head)) {
        cout<<"Palindrome DLL";
    }
    else {
        cout<<"Not a palindrome DLL";
    }
}