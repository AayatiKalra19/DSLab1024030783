#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node* up;
    Node* down;
    Node(int val) {
        data = val;
        next = prev = up = down = NULL;
    }
};
Node* constructDoublyLinkedList(int mat[3][3], int m, int n) {
    Node* head = NULL;
    Node* prevRowHead = NULL;
    Node* prevRowTemp = NULL;
    for (int i = 0; i < m; i++) {
        Node* rowHead = NULL;
        Node* temp = NULL;
        for (int j = 0; j < n; j++) {
            Node* newNode = new Node(mat[i][j]);
            if (!rowHead) {
                rowHead = newNode;
                temp = rowHead;
                if (!head) head = rowHead; 
            } 
            else {
                temp->next = newNode;
                newNode->prev = temp;
                temp = newNode;
            }
            if (prevRowTemp) {
                prevRowTemp->down = newNode;
                newNode->up = prevRowTemp;
                prevRowTemp = prevRowTemp->next; 
            }
        }
        prevRowHead = rowHead;
        prevRowTemp = prevRowHead;
    }

    return head;
}

void printList(Node* head) {
    Node* row = head;
    while (row) {
        Node* col = row;
        while (col) {
            cout << col->data << " ";
            col = col->next;
        }
        cout << endl;
        row = row->down;
    }
}
int main() {
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    Node* head = constructDoublyLinkedList(mat, 3, 3);
    cout << "Doubly linked grid form:" << endl;
    printList(head);
    return 0;
}
