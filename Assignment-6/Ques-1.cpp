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
// Implementation on circular linked list
void insertAtPos(Node* &head,int d,int pos) {
    Node* newNode = new Node(d);
    if (head == NULL) {
        newNode -> next = newNode;
        head = newNode;
        return;
    }
    Node* temp = head;
    if (pos == 1) {
        while (temp-> next!=head) {
            temp = temp -> next;
        }
        temp -> next = newNode;
        newNode -> next = head;
        head = newNode;
        return;
    }
    int cnt = 1;
    while (temp->next!=head && cnt<pos-1) {
        temp = temp -> next;
        cnt++;
    }
    newNode -> next = temp -> next;
    temp -> next = nedwNode;
}
void deleteNode(Node* &head,int pos) {
    if (head==NULL) {
        return;
    }
    if (pos == 1) {
        Node* temp = head; 
        Node* last = head;
        while (last -> next != head) {
            last = last -> next;
        }
        if (head -> next == head) {
            delete head;
            head = NULL;
            return;
        }
        last -> next = head -> next;
        head = head -> next;
        delete temp;
        return;
    }
    Node* prev = head;
    int cnt = 1;
    while  (cnt < pos -1 && prev -> next != head) {
        prev = prev -> next;
        cnt++;
    }
    Node* curr = prev -> next;
    if(curr == head) return;
    prev -> next = curr -> next;
    delete curr;
}
bool search(Node* head, int key) {
    if (head == NULL) return false;

    Node* temp = head;
    do {
        if (temp->data == key) {
            return true;
        }
        temp = temp->next;
    } while (temp != head);

    return false;
}
void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
int main() {
    Node* head = NULL;
    int choice, val, pos, key;

    do {
        cout << "1. Insert at position\n";
        cout << "2. Delete a node\n";
        cout << "3. Search for a node\n";
        cout << "4. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Enter position: ";
                cin >> pos;
                insertAtPos(head, val, pos);
                break;

            case 2:
                cout << "Enter position to delete: ";
                cin >> pos;
                deleteNode(head, pos);
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> key;
                if (search(head, key))
                    cout << "Node " << key << " found in list.\n";
                else
                    cout << "Node " << key << " not found.\n";
                break;

            case 4:
                display(head);
                break;

            case 0:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}