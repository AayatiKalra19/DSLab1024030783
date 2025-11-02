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
Node* inorderPred(Node* root,Node* target) {
    Node* pred = NULL;
    while (root != NULL) {
        if (target -> data > root -> data) {
            pred = root;
            root = root -> right;
        }
        else {
            root = root -> left;
        }
    }
    return pred;
}