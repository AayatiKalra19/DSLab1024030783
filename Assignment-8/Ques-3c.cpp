#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        this -> data = d;
        this -> left= NULL;
        this -> right= NULL;
    }
};
int maxDepth(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + max(maxDepth(root -> left),maxDepth(root-> right));
}
Node* insertIntoBST(Node* &root,int val) {
    if (root == NULL) {
        root = new Node(val);
        return root;
    }
    if (root -> data > val) {
        root -> left = insertIntoBST (root -> left,val);
    }
    else if (root -> data < val) {
        root -> right = insertIntoBST (root -> right,val);
    }
    else {
        cout<<"Duplicate Value"<<endl;
    }
    return root;
}
int main() {
    Node* root = NULL;
    insertIntoBST(root,50);
    insertIntoBST(root,30);
    insertIntoBST(root,70);
    insertIntoBST(root,20);
    insertIntoBST(root,40);
    insertIntoBST(root,80);
    cout<<"Maximum Depth: "<<maxDepth(root);
}