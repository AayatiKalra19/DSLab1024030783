#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};
Node* insert(Node* &root, int value) {
    if (root == NULL) {
        root = new Node(value);
        return root;
    }
    if (value == root->data) {
        cout << "Duplicate value " << value << " not inserted." << endl;
        return root;
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else {
        root->right = insert(root->right, value);
    }
    return root;
}
bool Recsearch(Node* root,int val) {
    if (root == NULL) {
        return false;
    }
    if (val == root -> data) {
        return true;
    }
    if (val < root -> data) {
        return Recsearch(root-> left,val);
    }
    else {
        return Recsearch(root -> right, val);
    }
}
bool Search (Node* root ,int val) {
    Node* curr = root;
    while (curr!=NULL) {
        if (curr -> data == val) {
            return true;
        }
        else if (val < curr -> data) {
            curr = curr -> left;
        }
        else {
            curr = curr -> right;
        }
    }
    return false;
}
int main() {
    Node* root = NULL;
    insert(root,8);
    insert(root,10);
    insert(root,3);
    insert(root,27);
    insert(root,4);
    insert(root,7);
    if (Recsearch(root,2)) {
        cout<<"Node is present"<<endl;
    }
    else {
        cout<<"Node is not present"<<endl;
    }
    if (Search(root,10)) {
        cout<<"Node is present"<<endl;
    }
    else {
        cout<<"Node is not present"<<endl;
    }
}