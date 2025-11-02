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
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root -> left);
    cout<<root -> data<<" ";
    inorder(root -> right);
}
void preorder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout<<root -> data<<" ";
    preorder(root -> left);
    preorder(root -> right);
}
void postorder(Node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root -> left);
    postorder(root -> right);
    cout<<root -> data<<" ";
}
int main() {
    Node* root = NULL;
    insert(root,8);
    insert(root,10);
    insert(root,3);
    insert(root,27);
    insert(root,4);
    insert(root,7);
    cout<<"Inorder traversal"<<endl;
    inorder(root);
    cout<<endl;
    cout<<"Preorder traversal"<<endl;
    preorder(root);
    cout<<endl;
    cout<<"Postorder traversal"<<endl;
    postorder(root);
}