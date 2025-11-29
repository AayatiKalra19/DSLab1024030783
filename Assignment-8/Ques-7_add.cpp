#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;   
    Node* right; 

    Node(int d) {
        data = d;
        left = right = NULL;
    }
};

void convertToDLL(Node* root, Node*& head, Node*& prev) {
    if (!root) return;

    convertToDLL(root->left, head, prev);

    if (!prev) {
        head = root;      
    } else {
        prev->right = root;
        root->left = prev;
    }
    prev = root;

    convertToDLL(root->right, head, prev);
}

Node* mergeDLL(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    Node* head = NULL;
    Node* tail = NULL;
    while (head1 && head2) {
        Node* temp;
        if (head1->data < head2->data) {
            temp = head1;
            head1 = head1->right;
        } else {
            temp = head2;
            head2 = head2->right;
        }

        if (!head) {
            head = temp;
            tail = temp;
        } else {
            tail->right = temp;
            temp->left = tail;
            tail = temp;
        }
    }

    if (head1) tail->right = head1, head1->left = tail;
    if (head2) tail->right = head2, head2->left = tail;

    return head;
}

void printDLL(Node* head) {
    while (head) {
        cout << head->data << " <--> ";
        head = head->right;
    }
    cout << "null";
}

int main() {
    Node* T1 = new Node(20);
    T1->left = new Node(10);
    T1->right = new Node(30);
    T1->left->right = new Node(25);
    T1->right->right = new Node(100);

    Node* T2 = new Node(50);
    T2->left = new Node(5);
    T2->right = new Node(70);

    Node *head1=NULL, *prev1=NULL;
    convertToDLL(T1, head1, prev1);
    prev1->right = NULL; 

    Node *head2=NULL, *prev2=NULL;
    convertToDLL(T2, head2, prev2);
    prev2->right = NULL;

    Node* mergedHead = mergeDLL(head1, head2);

    printDLL(mergedHead);
    return 0;
}
