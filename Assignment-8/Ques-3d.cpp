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
int minDepth(Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root -> left == NULL) {
        return 1+minDepth(root -> right);
    }
    if(root -> right == NULL) {
        return 1 + minDepth(root -> left);
    }
    return 1 + min(minDepth(root -> left),minDepth(root -> right));
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
}
int main() {
    Node* root = NULL;
    insertIntoBST(root,50);
    insertIntoBST(root,30);
    insertIntoBST(root,70);
    insertIntoBST(root,20);
    insertIntoBST(root,40);
    insertIntoBST(root,80);
    cout<<"Minimum Depth: "<<minDepth(root);
}