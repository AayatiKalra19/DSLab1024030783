#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int d) {
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }
};
Node* head = NULL;
void insertAtBeginning(int val) {
    Node* newNode = new Node(val);
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
    cout << val << " inserted at beginning.\n";
}
void insertAtEnd(int val) {
    Node* newNode = new Node(val);
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        cout << val << " inserted as first node.\n";
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    cout << val << " inserted at end.\n";
}
void insertAfter(int key, int val) {
    Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Node " << key << " not found.\n";
        return;
    }
    Node* newNode = new Node(val);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    cout << val << " inserted after " << key << ".\n";
}
void insertBefore(int key, int val) {
    Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Node " << key << " not found.\n";
        return;
    }

    Node* newNode = new Node(val);
    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = newNode;
    else
        head = newNode;

    temp->prev = newNode;

    cout << val << " inserted before " << key << ".\n";
}
void deleteNode(int key) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    if (temp->data == key) {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
        delete temp;
        cout << "Deleted node " << key << ".\n";
        return;
    }
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Node " << key << " not found.\n";
        return;
    }
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    delete temp;
    cout << "Deleted node " << key << ".\n";
}
void searchNode(int key) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Node " << key << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Node " << key << " not found.\n";
}
void displayList() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "Doubly Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, val, key;

    do {
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a node\n";
        cout << "4. Insert before a node\n";
        cout << "5. Delete a node\n";
        cout << "6. Search a node\n";
        cout << "7. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                insertAtBeginning(val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                insertAtEnd(val);
                break;

            case 3:
                cout << "Enter key (after which to insert): ";
                cin >> key;
                cout << "Enter value: ";
                cin >> val;
                insertAfter(key, val);
                break;

            case 4:
                cout << "Enter key (before which to insert): ";
                cin >> key;
                cout << "Enter value: ";
                cin >> val;
                insertBefore(key, val);
                break;

            case 5:
                cout << "Enter value to delete: ";
                cin >> val;
                deleteNode(val);
                break;

            case 6:
                cout << "Enter value to search: ";
                cin >> val;
                searchNode(val);
                break;

            case 7:
                displayList();
                break;

            case 0:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 0);

    return 0;
}
