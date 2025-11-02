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
Node* findMin(Node* root) {
    Node* temp = root;
    while (temp -> left!= NULL ) {
        temp = temp -> left;
    }
    return temp;
}
Node* deleteNode(Node* root,int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root -> data) {
        root -> left = deleteNode(root -> left,key); 
    }
    else if (key > root -> data) {
        root -> right = deleteNode(root -> right,key);
    }
    else {
        // No child
        if (root -> left == NULL && root -> right == NULL) {
            delete root;
            return NULL;
        }
        // 1 child
        else if(root -> left== NULL && root -> right != NULL) {
            Node* temp = root -> right;
            delete root;
            return temp;
        }
        else if (root -> right == NULL && root -> left != NULL) {
            Node* temp = root -> left;
            delete root;
            return temp;
        }
        // 2 children
        else {
            Node* temp = findMin(root -> right);
            root -> data = temp -> data;
            root -> right = deleteNode(root -> right,temp -> data);
        }
    }
    return root;
}