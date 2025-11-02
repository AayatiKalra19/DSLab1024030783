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
Node* MinElement(Node* root) {
    if (root == NULL) {
        return NULL;
    }
    while (root -> left != NULL) {
        root = root -> left;
    }
    return root;
}
int main() {
    Node* root = NULL;
    insert(root,8);
    insert(root,10);
    insert(root,3);
    insert(root,27);
    insert(root,4);
    insert(root,7);
    Node* min = MinElement(root);
    cout<<"Minimum Element: "<<min -> data;
}