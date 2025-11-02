#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        this -> data = d;
        this -> right = NULL;
        this -> left = NULL;
    }
};
int maxDepth(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + max(maxDepth(root -> left),maxDepth(root -> right));
}
