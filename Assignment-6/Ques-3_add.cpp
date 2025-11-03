#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
Node* reverseInGroups(Node* head, int k) {
    if (!head || k<=1) {
        return head;
    }
    Node* curr = head;
    Node* newHead = NULL;
    Node* temp = NULL;
    int count = 0;
    while (curr!=NULL && count < k) {
        temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        newHead = curr;
        curr = temp;
        count++;
    }
    if (newHead ) {
        newHead -> prev = NULL;
    }
    if (temp!=NULL) {
        head->next = reverseInGroups(curr, k);
        if (head->next)
            head->next->prev = head;
    }
    return newHead;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

void push(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head)
        head = newNode;
    else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

int main() {
    Node* head = NULL;
    for (int i = 1; i <= 6; i++)
        push(head, i);

    cout << "Original list:\n";
    printList(head);

    int k = 2;
    head = reverseInGroups(head, k);

    cout << "\nReversed in groups of " << k << ":\n";
    printList(head);
}
