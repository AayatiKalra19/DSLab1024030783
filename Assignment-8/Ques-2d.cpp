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
Node* inorderSuccessor(Node* root,Node* target) {
    Node* succ = NULL;
    while (root!=NULL) {
        if (target -> data < root -> data) {
            succ = root;
            root = root -> left;
        }
        else {
            root = root -> right;
        }
        return succ;
    }   
}
