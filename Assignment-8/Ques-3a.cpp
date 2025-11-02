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
Node* insertIntoBST(Node* &root,int val) {
    if (root == NULL) {
        root = new Node(val);
        return root;
    }
    if (val < root -> data) {
        root -> left = insertIntoBST(root -> left, val);
        
    }
    else if (val > root -> data) {
        root -> right = insertIntoBST(root -> right,val);
    }
    else {
        cout<<"Duplicate Value"<<endl;
    }
    return root;
}